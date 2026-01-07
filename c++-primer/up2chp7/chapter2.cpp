#ifndef POOP
#define POOP
#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif

int main(int argc, char **argv) {

    Sales_data d1, d2;
    double price = 0;

    std::cin >> d1.bookNo >> d1.units_sold >> price;
    d1.revenue = d1.units_sold * price;

    std::cin >> d2.bookNo >> d2.units_sold >> price;
    d2.revenue = d2.units_sold * price;

    if (d1.bookNo == d2.bookNo) {
        unsigned totalCnt = d1.units_sold + d2.units_sold;
        double totalRev = d1.revenue + d2.revenue;
        std::cout << d1.bookNo << " " << totalCnt << " " << totalRev << " ";

        if (totalCnt != 0) std::cout << totalRev/totalCnt << std::endl;
        else std::cout << "(No sales)" << std::endl;

    }
    else {
        std::cerr << "DATA must refer to the same isbn" << std::endl;
        return -1;
    }









    int ival = 5;
    int dval = 10;
    int *p = 0;
    p = &ival;
    std::cout << *p << std::endl;
    *p = dval;
    std::cout << *p << std::endl;
    dval = 20;
    std::cout << *p << std::endl;
   
    int i = 1;
    double d = 2;
    void *magic = &i;
    std::cout << magic << std::endl;
    magic = &d;
    std::cout << magic << std::endl;

    int v = 1024;
    int *pi = &v;
    int **ppi = &pi;

    std::cout << "The value of ival\n"
        << "direct value: " << v << "\n"
        << "indirect value: " << *pi << "\n"
        << "doubly indirect value: " << **ppi 
        << std::endl;

    i = 43;
    int *&r = p;
    r = &i;
    *r = 0;

   const int bufsize = 512;



    return 0;
}
