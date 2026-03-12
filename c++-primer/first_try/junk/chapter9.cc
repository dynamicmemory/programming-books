#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
using std::string, std::vector, std::list, std::deque;

bool find_value(vector<int>::iterator b, vector<int>::iterator e, int n) {
    while (b != e) 
        if (*b++ == n)
            return true;
    return false;
}

vector<int>::iterator find_value2(vector<int>::iterator b, vector<int>::iterator e, 
                                 int n) {
    while (b++ != e)
        if (*b == n)
            return b;
    return e;
}

int main(void) {

//     list<deque<int>> ints;
//     list<int> ilist = {1,2,3,4,5,6};
//     auto begin = ilist.begin(); 
//     while(begin != ilist.end())
//         std::cout << *begin++ << "\n";
//     std::cout << std::endl;
//
//     vector<int> ivec = {1,2,3,4,5,6};
//     vector<int>::iterator r1 = find_value2(ivec.begin(), ivec.end(), 2);
//     vector<int>::iterator r2 = find_value2(ivec.begin(), ivec.end(), 19);
//
//     std::cout << *r1 << *r2 << std::endl;
//
//     deque<string> strings;
//     string s;
//     while (std::cin >> s) {
//         strings.push_back(s);
//     }
//
//     for (auto start=strings.begin(); start != strings.end(); start++) 
//         std::cout << *start << '\n';
//     std::cout << std::endl;
//
//     list<string> strings2;
//     string s2;
//     while (std::cin >> s2) 
//         strings2.push_back(s2);
//
//     for (auto start=strings2.begin(); start != strings2.end(); start++)
//         std::cout << *start << '\n';
//     std::cout << std::endl;
//
//     int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
//
//     vector<int> iavec;
//     list<int> ialist;
//     for (int i=0; i < 11; i++) {
//         iavec[i] = ia[i];
//         ialist.push_back(ia[i]);
//     }
//
//     auto liter = ialist.begin();
//     auto viter = iavec.begin();
//
//     while (liter != ialist.end()) {
//         if (*liter % 2) 
//             ialist.erase(liter);
//         else 
//             liter++;
//     }
//
//     while (viter != iavec.end()) {
//         if (!*viter % 2) 
//             iavec.erase(viter);
//         else 
//             viter++;
//     }

    vector<int> ivec;
    while (ivec.size() != 100) {
        std::cout << ivec.capacity() << '\n';
        if (ivec.capacity() -1 == ivec.size())
            ivec.reserve(2);

        ivec.push_back(0);
    }
    return 0;
}
