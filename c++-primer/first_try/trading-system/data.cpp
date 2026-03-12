#include <vector>
#include <string>
using Matrix = std::vector<std::vector<double>>; 

class Database {
public: 
    Database(const std::string &a, const std::string &b) : 
        database_name("./database"+a+b), table_name("table"+a+b) {}

    ~Database() = default;

    void open() { /*TODO*/ }
    void close() { /*TODO*/ }
    std::vector<std::string> fetch_row() { /*TODO*/ return {}; }
    std::vector<std::string> fetch_all_rows() { /*TODO*/ return {}; }
    void insert_row() { /*TODO*/ }
    void insert_rows() { /*TODO*/ }

    Matrix &get_dataframe() { /*TODO*/ return dataframe; }

private:
    std::string database_name;
    std::string table_name;

    Matrix dataframe;
};


#include <vector>
#include <string>
using Matrix = std::vector<std::vector<double>>; 

class Features {
public:
    Features(Matrix &f) : dataframe(f) {}
    ~Features() = default;

    void create_labels() { /*TODO*/ }
    const Matrix &get_features() const { /*TODO*/ return dataframe; }
    std::vector<double> get_labels() { /*TODO*/ return labels; }

    void volatility() { /*TODO*/ }
    void sma() { /*TODO*/ }
    void rsi() { /*TODO*/ }

private:
    Matrix dataframe;
    std::vector<double> labels;
};


#include <vector>
#include <string>
using Matrix = std::vector<std::vector<double>>; 

class MachineLearningTools {
public:
    MachineLearningTools(const Matrix &a, const std::vector<double> &b) : X(a), y(b) {}
    ~MachineLearningTools() = default;

    std::pair<Matrix, std::vector<double>> pipeline() {
        clean();
        scale(); 
        return split_test_train();
    }

    void scale() { /*TODO*/ }
    void clean() { /*TODO*/ }
    std::pair<Matrix, std::vector<double>> split_test_train() { 
        /*TODO*/
        return {X, y}; 
    }

private:
    Matrix X;
    std::vector<double> y;
};


#include <vector>
#include <string>
using Matrix = std::vector<std::vector<double>>; 

class DataPipeline {
public:
    DataPipeline(const std::string &asset, const std::string &timeframe) :
        db(asset, timeframe), 
        f(db.get_dataframe()), 
        mlt(f.get_features(), f.get_labels()) {}

    ~DataPipeline() = default;

    void run_pipeline() {
        std::pair<Matrix, std::vector<double>> data = mlt.split_test_train();
        X = std::move(data.first);
        y = std::move(data.second);
    }
    
    const Matrix &get_X_train() const { return X; }
    const std::vector<double> &get_y_train() const { return y; }

private:
    Database db;
    Features f;
    MachineLearningTools mlt;

    Matrix X;
    std::vector<double> y;
};
