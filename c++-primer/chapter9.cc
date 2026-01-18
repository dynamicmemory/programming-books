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

vector<int>::iterator find_value2(vector<int>::iterator b, 
                                 vector<int>::iterator e, 
                                 int n) {
    while (b++ != e)
        if (*b == n)
            return b;
    return e;
}



int main(void) {

    list<deque<int>> ints;
    list<int> ilist = {1,2,3,4,5,6};
    auto begin = ilist.begin(); 
    while(begin != ilist.end())
        std::cout << *begin++ << "\n";
    std::cout << std::endl;

    vector<int> ivec = {1,2,3,4,5,6};
    vector<int>::iterator r1 = find_value2(ivec.begin(), ivec.end(), 2);
    vector<int>::iterator r2 = find_value2(ivec.begin(), ivec.end(), 19);

    std::cout << *r1 << *r2 << std::endl;

    return 0;
}
