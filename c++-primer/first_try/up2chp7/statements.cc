#include <iostream>
#include <vector>
using std::vector;

int main(void) {

    unsigned aCnt = 0, eCnt = 0, iCnt=0;
    char ch;
    while (std::cin >> ch) {
        switch(ch) {
            case 'a':
                ++aCnt;
                break;
            case 'b':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            default:
                break;
        }
    }

    vector<int> v = {1,2,3,4,5};
    for (auto &i : v) {
        i *= 2;
    }

    for (auto beg = v.begin(), end = v.end(); beg != end; ++beg) {
        auto &f = beg;
        f += 2;
    }
    
    try {
        if (1 != 1)
            throw std::runtime_error("The matrix is falling apart");
    }
    catch (std::runtime_error err) {
        std::cout << err.what() << std::endl;
    }


    return 0;
}
