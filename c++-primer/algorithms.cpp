#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <string> 

using std::vector, std::string;
typedef std::vector<int>::iterator viter;

int my_count(viter start, viter end, const int val) {
    int counter = 0;
    while (start != end) 
        if (*start++ == val)
            counter++;
    return counter;
}

bool is_shorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

int main(void) {

//     vector<int> ivec;
//     int val;
//
//     std::cout << "Enter integers (end with non-number): ";
//     while (std::cin >> val) 
//         ivec.push_back(val);
//
//     int target;
//     std::cout << "Enter value to count: ";
//     std::cin.clear();
//     std::cin >> target;
//
//     int count = my_count(ivec.begin(), ivec.end(), target);
//     std::cout << target << " appears " << count << " times." << std::endl;
//
//
//     std::list<string> words;
//     string s;
//
//     std::cout << "Enter words (end with ctrl + D): ";
//     while(std::cin >> s) 
//         words.push_back(s);
//
//     std::string target2;
//     std::cout << "Enter word to count: ";
//     std::cin.clear();
//     std::cin >> target2;
//
//     int cword = std::count(words.begin(), words.end(), target2);
//     std::cout << target2 << " appears " << cword << " times. " << std::endl;
//
    vector<int> ivec = {1,2,3,4,5};
    std::accumulate(ivec.begin(), ivec.end(), 0);

    fill_n(ivec.begin(), ivec.size(), 0);


    vector<string> words = {"ant", "dog", "cat", "frog", "hippomans", "xolotl"};

    sort(words.begin(), words.end(), is_shorter);
    for (auto i=words.begin(); i != words.end(); i++)
        std::cout << *i << "\n";

    for (const auto &word : words) {
        std::cout << word << '\n';
    }


    return 0;
}
