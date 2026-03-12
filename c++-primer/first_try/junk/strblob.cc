#include <iostream>
#include <vector>
#include <memory>
using std::vector, std::string, std::shared_ptr;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) {data->push_back(t);}
    void pop_back();

    string &front();
    string &back();

    const string &front() const;
    const string &back() const;
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<vector<string>>()) {}
StrBlob::StrBlob(std::initializer_list<string> il) : 
    data(std::make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const { 
    if (i >= data->size())
        throw std::out_of_range(msg);
}

string &StrBlob::front() {
    check(0, "front on empty strblob");
    return data->front();
}

string &StrBlob::back() {
    check(0, "back on empty strblob");
    return data->back();
}

const string &StrBlob::front() const {
    check(0, "front on empty strblob");
    return data->front();
}

const string &StrBlob::back() const {
    check(0, "back on empty strblob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty strblob");
    data->pop_back();
}


