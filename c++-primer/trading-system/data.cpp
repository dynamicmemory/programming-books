#include <vector>
#include <string>

class Database {
public: 
    Database(std::string &a, std::string &b) : 
        database_name("./database"+a+b), table_name("table"+a+b) {}
    ~Database() {}

    void open() { /*Implement function*/ }
    void close() { /*Implement function*/ }
    std::vector<std::string> fetch_row() { /*Implement function*/ return {}; }
    std::vector<std::string> fetch_all_rows() { /*Implement function*/ return {}; }
    void insert_row() { /*Implement function*/ }
    void inset_rows() { /*Implement function*/ }

    std::vector<std::vector<double>> get_dataframe() { /*Implement function*/ return {{}}; }

private:
    std::string database_name;
    std::string table_name;
};


#include <vector>
#include <string>

class Features {
public:
    Features(std::vector<std::vector<double>> f) : dataframe(f) {}
    ~Features() {}

    void create_labels() { /*Implement function*/ }
    std::vector<std::vector<double>> get_features() { /*Implement function*/ return {}; }
    std::vector<double> get_labels() { /*Implement function*/ return {}; }

    void volitility() { /*Implement function*/ }
    void sma() { /*Implement function*/ }
    void rsi() { /*Implement function*/ }

private:
    std::vector<std::vector<double>> dataframe;
};


#include <vector>
#include <string>

class MachineLearningTools {
public:
    MachineLearningTools(std::vector<std::vector<double>> a, std::vector<double> b) :
        X(a), y(b) {}
    ~MachineLearningTools() {}

    std::vector<std::vector<double>> pipeline() {
        clean();
        scale(); 
        return split_test_train();
    }

    void scale() { /*Implement function*/ }
    void clean() { /*Implement function*/ }
    std::vector<std::vector<double>> split_test_train() { return {{}}; }

private:
    std::vector<std::vector<double>> X;
    std::vector<double> y;
};


#include <vector>
#include <string>

class DataPipeline {
public:
    DataPipeline(std::string &asset, std::string &timeframe) {
        db = Database(asset, timeframe);
        f = Features(db.get_dataframe());
        mlt = MachineLearningTools(f.get_features(), f.get_labels());
    }
    ~DataPipeline() {} 
    void run_pipeline() {
        std::vector<std::vector<double>> data = mlt.split_test_train();
        y = data[0];
        X = data[1:data.size()];
    }
    
    std::vector<std::vector<double>> get_X_train() { return X; }
    std::vector<double> get_y_train() { return y; }

private:
    Database db;
    Features f;
    MachineLearningTools mlt;
    std::vector<std::vector<double>> X;
    std::vector<double> y;
    
};
