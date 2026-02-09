#include <vector>
#include <string>
#include <memory>

// Interface
class IBaseModel {
public: 
    virtual ~IBaseModel() = default;

    virtual void train(const std::vector<double> &x, const std::vector<double> &y) = 0;
    virtual std::vector<double> predict(const std::vector<double> &x, const std::vector<double> &y) = 0;
    virtual void evaluate(const std::vector<double> &x) = 0;

    virtual void save(const std::string &path) = 0;
    virtual void load(const std::string &path) = 0;
};

// Main model manager
class ModelManager {
public:
    std::unique_ptr<IBaseModel> model;   

    void select_model(std::unique_ptr<IBaseModel> m) {
        model = std::move(m);
    }

    void train(const std::vector<double> &x, const std::vector<double> &y) {
        if (!model) return;
        model->train(x, y);
    }

    std::vector<double> predict(const std::vector<double> &x, const std::vector<double> &y) {
        if (!model) return {};
        std::vector<double> result = model->predict(x, y);
        return result;
    }

    void evaluate(const std::vector<double> &x) {
        if (!model) return;
        model->evaluate(x);
    }

    void save(const std::string &path) { 
        if (!model) return;
        model->save(path); 
    }

    void load(const std::string &path) { 
        if (!model) return;
        model->load(path); 
    }
};

// Models
class LinearRegression : public IBaseModel {
    public:

    void train(const std::vector<double> &x, 
               const std::vector<double> &y) override { /*Implement logic*/}

    std::vector<double> predict(const std::vector<double> &x, 
                                const std::vector<double> &y) override {
        // Implement logic
        return {};
    }

    void evaluate(const std::vector<double> &x) override { /*Implement logic*/ }
    void save(const std::string &path) override { /*Implement logic*/ }
    void load(const std::string &path) override { /*Implement logic*/ }
};
