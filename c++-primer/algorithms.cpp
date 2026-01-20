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

int main(void) {

    vector<int> ivec;
    int val;

    std::cout << "Enter integers (end with non-number): ";
    while (std::cin >> val) 
        ivec.push_back(val);

    int target;
    std::cout << "Enter value to count: ";
    std::cin.clear();
    std::cin >> target;

    int count = my_count(ivec.begin(), ivec.end(), target);
    std::cout << target << " appears " << count << " times." << std::endl;


    std::list<string> words;
    string s;

    std::cout << "Enter words (end with ctrl + D): ";
    while(std::cin >> s) 
        words.push_back(s);

    std::string target2;
    std::cout << "Enter word to count: ";
    std::cin.clear();
    std::cin >> target2;

    int cword = std::count(words.begin(), words.end(), target2);
    std::cout << target2 << " appears " << cword << " times. " << std::endl;

    return 0;
}
