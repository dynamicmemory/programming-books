#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>

bool check_size(const std::string &s, std::string::size_type sz) {
    return s.size() <= sz;
}

int main(void) {
    std::string word = "Hello there";

    auto a = std::bind(check_size, std::placeholders::_1, 5);
    bool b1 = a(word);

    std::cout << b1 << std::endl;



    return 0;
}
