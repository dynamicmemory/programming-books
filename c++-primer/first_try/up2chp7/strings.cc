#include <iostream>
#include <string>
using std::string;

int main() {

    string line = "hello";
    auto len = line.size();

    std::cout << len << std::endl;

    int n = 10;
    std::cout << (len < n) << std::endl;

    string a = "Hello";
    string b = "world";
    string c = a + b;

    for (auto d : a) {
        std::cout << d;
    } 
    std::cout << std::endl;

    string s("Hello cpp@@@!!!");
    decltype(s.size()) punct_count = 0;
    for (auto c: s)
        if (std::ispunct(c))
            punct_count++;
    std::cout << punct_count << "Punctuation characters in " << s << std::endl;

    string e = "abcdefghijklmnopqrstuvwxyz";
    for (int idx=0; idx != e.size(); idx++)
        e[idx] = 'x';

    std::cout << e << std::endl;


    return 0;
}
