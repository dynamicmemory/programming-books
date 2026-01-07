#include <iostream>
#include <vector>
#include <string>
using std::vector, std::string;

int main(void) {

    // vector<string> v = {"this", "is", "a", "vector"};
    //
    // string s("some string");
    // if (s.begin() != s.end()) {
    //     auto it = s.begin();
    //     *it = toupper(*it);
    // }
    //
    // for (auto it = s.begin(); it != s.end(); it++)
    //     *it = toupper(*it);
    //
    //
    // vector<string> data = {"this","is","a","paragraph","of","text"};
    //
    // for (auto it = data.cbegin(); !it->empty(); it++)
    //     std::cout << *it << std::endl;


    // Binary search 
    // vector<char> text = {'a','b','c','d','e'};
    // auto beg = text.begin();
    // auto end = text.end();
    // auto mid = text.begin() + (end - beg) / 2;
    //
    // while (mid != end && *mid != 'a') {
    //     if ('a' < *mid)
    //         end = mid;
    //     else 
    //         beg = mid + 1;
    //     mid = beg + (end-beg) /2;
    // }

    // Read set of ints into a vec 
    // print sum of each pair
    // print sum of first and last and so on

    vector<int> ivec;
    int i;
    while (std::cin >> i) 
        ivec.push_back(i);

    for (auto start = ivec.begin(); start < ivec.end(); start++)
        if (start+1 != ivec.end())
            std::cout << *start + *start+1 << std::endl;

    return 0;
}
