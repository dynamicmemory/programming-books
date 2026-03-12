#include <iostream>
#include <vector>
#include <string>
using std::vector, std::string;

int fact(int val)  {
    int ret = 1;
    while (val > 1) 
        ret *= val--;
    return ret;
}

void user_query(void) {
    int factorial;
    std::cout << "Enter a number to calc a fat factorial on" << std::endl;
    std::cin >> factorial;
    std::cout << fact(factorial) << std::endl;
}

int absoling(int arg) {

    if (arg < 0) return arg * -1;
    else return arg;
}

size_t count_calls(void) {
    static size_t a = 0;
    return ++a;
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void reset(int &i) {
    i = 0;
}

int main(void) {

    // user_query();
    // int a = absoling(49);
    // int b = absoling(-49);
    // std::cout << count_calls() << std::endl;
    // std::cout << count_calls() << std::endl;
    int a, b;
    a = 1, b = 2;
    swap(a, b);
    std::cout << a << b << std::endl;
    reset(a);


    return 0;
}
