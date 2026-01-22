#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using std::vector, std::string;

int add_five(int n) {
    int a = 5;

    auto x = [a](int number) {
        return a + number; 
    };

    int result = x(n);
    return result;
}

void biggies(std::vector<string> &words, std::vector<string>::size_type sz) {
    auto is_smaller = [](const string &a, const string &b) {
        return a.size() < b.size();
    };

    auto is_greater_or_equals = [sz](const string&a) {
        return a.size() >= sz;
    };

    auto print_words = [](const string &a) {
        std::cout << a << " ";
    };

    std::stable_sort(words.begin(), words.end(), is_smaller);
    auto wc = find_if(words.begin(), words.end(), is_greater_or_equals);
    auto count = words.end() - wc;
    for_each(wc, words.end(), print_words);
    std::cout << std::endl;
}


int main(void) {

    auto f = [] { return 42; };

    std::cout << f() << std::endl;

    auto sum_two_num = [](int a, int b) { return a + b; };



    return 0;
}
