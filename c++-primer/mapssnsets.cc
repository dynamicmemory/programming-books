#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main (void) {
    std::map<std::string, size_t> word_count;

    std::string word;
    while (std::cin >> word) 
        ++word_count[word];

    for (auto &w: word_count) { 
        std::cout << w.first << " appears " << w.second << (w.second > 1 ? " times" : "time")
            << std::endl;
    }

    std::map<std::string, size_t> word_count2;
    std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
        "the", "but", "and", "or", "an", "a"};

    std::string word2;
    while (std::cin >> word2)
        if (exclude.find(word) == exclude.end())
            ++word_count2[word2];
    

    std::vector<std::pair<std::string, int>> pairs;
    std::string word3;
    int num;
    std::pair<std::string, int> strint;
    while (std::cin >> word3 >> num)
        pairs.emplace_back(word3, num);

    return 0;
}
