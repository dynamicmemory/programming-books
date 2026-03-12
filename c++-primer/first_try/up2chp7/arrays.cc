#include <array>
#include <string>
#include <iostream>
using std::array, std::string, std::cout, std::cin, std::endl;

int main(void) {

    unsigned cnt = 42;
    constexpr unsigned sz = 42;


    unsigned scores[11] = {};
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++scores[grade/10];
    }

    for (auto i : scores) {
        cout << i << " ";
    }
    cout << endl;

    auto ai = scores;

    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    int *beg = std::begin(ia);
    int *end = std::end(ia);

    int arr[3][3] = {0};
    for (auto &row : arr)
        for (auto col : row)
            cout << col << endl;
    int aa[3][2] = {0};
    for (auto p = std::begin(aa); p != std::end(aa); p++) {
        for (auto q = std::begin(*p); q != std::end(*p); q++)
            cout << *q << ' ';
    }

    return 0;
}
