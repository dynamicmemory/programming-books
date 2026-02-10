#include <iostream>
#include <vector>
#include <string>

class ApiManager {
public: 
    /*TODO - Load key and secret if none found, set key and secret to ""*/
    ApiManager() {
        // if (path_to_keys exists) {
        //     key = read from file or hidden env var 
        //     secret = read from file or hidden env var 
        // }
        // else {
        //     key = "";
        //     secret = "";
        // }
    }

    /*TODO - some kind of hidden environment variable setter / retriever*/
    std::pair<std::string, std::string> get_api_key_and_secret() {
        if (key == "") {
            std::cin >> key;
        }

        if (secret == "") {
            std::cin >> secret;
        }
        return {key, secret};
    }

private: 
    std::string key;
    std::string secret;
};


#include <string>
#include <map>
using Response = std::map<std::string, std::string>;

class Exchange {
public: 
    Exchange(bool t) : test_net(t) {
        ApiManager m;
        auto apikey_and_secret = m.get_api_key_and_secret();
        apikey = apikey_and_secret.first;
        apisecret = apikey_and_secret.second;
        // Possible test auth here to see if keys are correct, return error if 
        // not?
    }

    const std::string authenticate(const std::string &parameters) const { 
        std::string message;
        /*TODO - Generates hash using request with keys + parameters for exchange into string*/
        return message;
    }

    const Response make_request(const std::string &method, 
                                const std::string &url, 
                                const std::string &parameters) const {
        const std::string message = authenticate(parameters);
        /*TODO - Send exchange method, to url with authed params*/
        Response r; /*This will be the actual exchanges reply*/ 
        return r;
    }

    const Response fetch_account_balance(const std::string &acnt_type, 
                                         const std::string &asset) const {
        std::string parameters = acnt_type + asset;
        std::string url = base_url + "balance";

        Response res = make_request("GET", url, parameters);
        return res;
    }
    
    const Response fetch_open_positions(const std::string &acnt_type, 
                                        const std::string &asset) const {
        std::string parameters = acnt_type + asset;
        std::string url = base_url + "positions";

        Response res = make_request("GET", url, parameters);
        return res;
    }

    const Response fetch_open_orders(const std::string &acnt_type, 
                                     const std::string &asset) const {
        std::string parameters = acnt_type + asset;
        std::string url = base_url + "orders";

        Response res = make_request("GET", url, parameters);
        return res;
    }

    const Response limit_order(const std::string &acnt_type, 
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

    const Response market_order(const std::string &acnt_type, 
                                const std::string &asset,
                                const std::string &side,
                                const std::string &size) const {
        std::string parameters = acnt_type + "market" + asset + side + size;
        std::string url = base_url + "order";

        Response res = make_request("POST", url, parameters);
        return res;
    }

    const Response conditional_order(const std::string &acnt_type, 
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

    const Response cancel_order(const std::string &acnt_type, 
                                const std::string &asset,
                                const std::string &order_id) const {
        std::string parameters = acnt_type + asset + order_id;
        std::string url = base_url + "cancel";

        Response res = make_request("POST", url, parameters);
        return res;
    }

    const Response cancel_all_orders(const std::string &acnt_type, 
                                     const std::string &asset) const {
        std::string parameters = acnt_type + asset;
        std::string url = base_url + "cancel_all";

        Response res = make_request("POST", url, parameters);
        return res;
    }

    const Response fetch_ohlc(const std::string &acnt_type, 
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
    bool test_net = false;
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
    AccountManager(bool t) : exchange(t) { /*Could test apit correct here*/}

    int check_response(Response res) {
        if (res["retcode"] != std::to_string(0)) {
            /*Error has occured with the exchange print or throw error*/
            std::cout << "Code: " << res["retcode"] 
                      << " Message: " << res["msg"] << "\n";
            return -1;
        }
        return 0;
    }

    void get_position(const std::string &asset) {
        Response res = exchange.fetch_open_positions(account_type, asset); 
        if (check_response(res) < 0) {
            /*Throw error, return error, print error, do something with the error*/
            return;
        }
        /*Process the response and return what we want.*/
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

class TradeManager {};
