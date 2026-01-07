#include <iostream>
using std::string;

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);

public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : 
        bookNo(s), units_sold(n), revenue(p*n) {}

    Sales_data(std::istream &is) { 
        double price = 0;
        is >> bookNo >> units_sold >> price;
        revenue = price * units_sold;
    }

    std::string isbn() const { 
        return bookNo;
    }
    Sales_data &combine(const Sales_data&);
private:
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

double Sales_data::avg_price() const {
    if (units_sold)
        return revenue/units_sold;
    else 
        return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " 
        << item.avg_price();
    return os;
}

class Person {
public:
    Person() = default; 
    Person(const string &s) : name(s) {}
    Person(const string &s, const string &a) : name(s), addr(a) {}

    string get_name() const { return name; }
    string get_addr() const { return addr; }

private:
    string name = "";
    string addr = "";
};

int main(void) {
    Person p1("Archabald");
    string name = p1.get_name();
    string addr = p1.get_addr();

    const Person &p2 = p1;

    std::cout << name << " " << addr << std::endl;

    return 0;
}
