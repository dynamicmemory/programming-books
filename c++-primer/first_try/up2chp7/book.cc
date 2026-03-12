#include <iostream>

class Book {
public:
    Book(std::string s = "", int n=100) : title(s) { } 
    Book(std::string s) : title(s) { } 
    Book(int n) : Book("", n) { } 

private:
    std::string title;
    int page_no;
    int date;


};


int main(void) {

    return 0;
}
