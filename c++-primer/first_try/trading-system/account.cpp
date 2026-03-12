#include <iostream>
#include <vector>
#include <string>

class ApiManager {
public: 
    ApiManager() {
        const char *k = std::getenv("API_KEY");
        const char *s = std::getenv("API_SECRET");
        if (k) key = k;
        if (s) secret = s;
    }
    
    const std::string &get_key() const { return key; }
    const std::string &get_secret() const { return secret; }

private: 
    std::string key;
    std::string secret;
};


#include <string>
#include <map>
using Response = std::map<std::string, std::string>;

class Exchange {
public: 
    Exchange(const ApiManager &api, bool t=false) : test_net(t) {
        apikey = api.get_key();
        apisecret = api.get_secret();
        // Possible test auth here to see if keys are correct, return error if 
        // not?
    }

    std::string authenticate(const std::string &parameters) const { 
        std::string message;
        /*TODO - Generates hash using request with keys + parameters for exchange into string*/
        return message;
    }

    Response make_request(const std::string &method, 
                                const std::string &url, 
                                const std::string &parameters) const {
        const std::string message = authenticate(parameters);
        /*TODO - Send exchange method, to url with authed params*/
        Response r; /*This will be the actual exchanges reply*/ 
        return r;
    }

    Response fetch_account_balance(const std::string &acnt_type, 
                                         const std::string &asset) const {
        std::string parameters = acnt_type + asset;
        std::string url = base_url + "balance";

        Response res = make_request("GET", url, parameters);
        return res;
    }
    
    Response fetch_open_positions(const std::string &acnt_type, 
                                        const std::string &asset) const {
        std::string parameters = acnt_type + asset;
        std::string url = base_url + "positions";

        Response res = make_request("GET", url, parameters);
        return res;
    }

    Response fetch_open_orders(const std::string &acnt_type, 
                                     const std::string &asset) const {
        std::string parameters = acnt_type + asset;
        std::string url = base_url + "orders";

        Response res = make_request("GET", url, parameters);
        return res;
    }

    Response limit_order(const std::string &acnt_type, 
                               const std::string &asset,
                               const std::string &price, 
                               const std::string &side,
                               const std::string &size) const {
        std::string parameters = acnt_type + "limit" + asset + price + side + 
                                 size + "postOnly";
        std::string url = base_url + "order";

        Response res = make_request("POST", url, parameters);
        return res;
    }

    Response market_order(const std::string &acnt_type, 
                                const std::string &asset,
                                const std::string &side,
                                const std::string &size) const {
        std::string parameters = acnt_type + "market" + asset + side + size;
        std::string url = base_url + "order";

        Response res = make_request("POST", url, parameters);
        return res;
    }

    Response conditional_order(const std::string &acnt_type, 
                                     const std::string &asset,
                                     const std::string &price, 
                                     const std::string &side,
                                     const std::string &size,
                                     const std::string &trigger,
                                     const int direction) const {
        std::string parameters = acnt_type + "limit" + asset + price + side + 
                                 size + trigger + std::to_string(direction);
        std::string url = base_url + "order";

        Response res = make_request("POST", url, parameters);
        return res;
    }

    Response cancel_order(const std::string &acnt_type, 
                                const std::string &asset,
                                const std::string &order_id) const {
        std::string parameters = acnt_type + asset + order_id;
        std::string url = base_url + "cancel";

        Response res = make_request("POST", url, parameters);
        return res;
    }

    Response cancel_all_orders(const std::string &acnt_type, 
                                     const std::string &asset) const {
        std::string parameters = acnt_type + asset;
        std::string url = base_url + "cancel_all";

        Response res = make_request("POST", url, parameters);
        return res;
    }

    Response fetch_ohlc(const std::string &acnt_type, 
                              const std::string &asset, 
                              const std::string &timeframe,
                              const int &n) const {

        std::string parameters = acnt_type + asset + timeframe + std::to_string(n);
        std::string url = base_url + "candle_ohlc";

        Response res = make_request("GET", url, parameters);
        return res;
    }

private:
    // Set to false by default
    bool test_net;
    std::string base_url;
    std::string apikey;
    std::string apisecret;
};


#include <iostream>
#include <vector>
#include <string>
using Response = std::map<std::string, std::string>;

class AccountManager {
public: 
    AccountManager(Exchange &e) : exchange(e) { /*Could test apit correct here*/}
    ~AccountManager() = default;

    int check_response(Response res) {
        if (res.at("retcode") != std::to_string(0)) {
            /*Error has occured with the exchange print or throw error*/
            std::cout << "Code: " << res["retcode"] 
                      << " Message: " << res["msg"] << "\n";
            return -1;
        }
        return 0;
    }

    double get_account_balance(const std::string &asset) {
        Response res = exchange.fetch_account_balance(account_type, asset);
        if (check_response(res) < 0) {
            /*Throw error, return error, print error, do something with the error*/
            return 0;
        }
        return std::stod(res["balance"]);
    }

    std::pair<std::string, std::string> get_position(const std::string &asset) {
        Response res = exchange.fetch_open_positions(account_type, asset); 
        if (check_response(res) < 0) {
            /*Throw error, return error, print error, do something with the error*/
            return {"",""};
        }
        /*Process the response and return what we want.*/
        return {res["side"],res["size"]};
    }

    void get_orders(const std::string &asset) {
        Response res = exchange.fetch_open_orders(account_type, asset); 
        if (check_response(res) < 0) {
            /*Throw error, return error, print error, do something with the error*/
            return;
        }
        /*Process the response and return what we want.*/
    }

    void limit_order(const std::string &asset, const std::string &price, 
                     const std::string &side, const std::string &size) {
        Response res = exchange.limit_order(account_type, asset, price, side, size); 
        if (check_response(res) < 0) {
            /*Throw error, return error, print error, do something with the error*/
            return;
        }
        /*Process the response and return what we want.*/
    }

    void market_order(const std::string &asset, const std::string &side, 
                      const std::string &size) {
        Response res = exchange.market_order(account_type, asset, side, size); 
        if (check_response(res) < 0) {
            /*Throw error, return error, print error, do something with the error*/
            return;
        }
        /*Process the response and return what we want.*/
    }

    void stop_loss(const std::string &asset, const std::string &price, 
                   const std::string &side, const std::string &size,
                   const std::string &trigger, int direction) {
        Response res = exchange.conditional_order(account_type, asset, price,
                side, size, trigger, direction); 
        if (check_response(res) < 0) {
            /*Throw error, return error, print error, do something with the error*/
            return;
        }
        /*Process the response and return what we want.*/
    }

    void cancel_order(const std::string &asset, const std::string &order_id) {
        Response res = exchange.cancel_order(account_type, asset, order_id); 
        if (check_response(res) < 0) {
            /*Throw error, return error, print error, do something with the error*/
            return;
        }
        /*Process the response and return what we want.*/
    }

    void cancel_all_orders(const std::string &asset) {
        Response res = exchange.cancel_all_orders(account_type, asset); 
        if (check_response(res) < 0) {
            /*Throw error, return error, print error, do something with the error*/
            return;
        }
        /*Process the response and return what we want.*/
    }

    void change_account_type(const std::string &new_type) {
        account_type = new_type;
    }

private:
    Exchange exchange;
    std::string account_type = "Linear";
};


#include <vector>
#include <string>

class TradeManager {
public:
    TradeManager(AccountManager &a, const std::string &b) : account(a), asset(b) {}
    ~TradeManager() = default;

    void manager_trade(const std::string &decision) {
        /* TODO: Define flow for a trade given a decision & current account position & balance */
    }

    void change_asset(const std::string &new_asset) {
        asset = new_asset;
    }

    void open_trade(const std::string &side) { 
        std::string size = std::to_string(calculate_size());
        account.market_order(asset, side, size);
    }

    void close_trade() { 
        std::pair<std::string, std::string> position = get_position();
        std::string side = position.first;
        std::string size = position.second;

        if (side == "" || size == "") {
            /* TODO: Implement error handling*/
            return;
        }

        side = side == "Buy" ? "Sell" : "Buy";
        account.market_order(asset, side, size);
    }

    double get_balance() { 
        double balance = account.get_account_balance(asset); 
        if (balance <= 0) { /* TODO: Decide if function or caller deals with 0 bal*/}
        return balance;
    }

    std::pair<std::string, std::string> get_position() { 
        return account.get_position(asset);
    }

    double calculate_entry() { double var; /*TODO - calculation*/ return var; }
    double calculate_stop() { double var; /*TODO - calculation*/ return var; } 
    double calculate_target() { double var; /*TODO - calculation*/ return var; }
    double calculate_size() { double var; /*TODO - calculation*/ return var; }
    
private:
    AccountManager account;
    std::string asset;
};
