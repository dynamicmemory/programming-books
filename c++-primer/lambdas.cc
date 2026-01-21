#include <iostream>
#include <numeric>
#include <algorithm>

int main(void) {

    auto f = [] { return 42; };

    std::cout << f() << std::endl;

    return 0;
}
