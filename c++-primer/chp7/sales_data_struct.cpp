#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

double Sales_data::avg_price() const { 
    return (units_sold) ? revenue / units_sold : 0; 
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}



class Person {
private:
    std::string name_;
    std::string address_;
public:
    std::string get_name() const { return name_; } 
    std::string get_address() const { return address_; }
};
