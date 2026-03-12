#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

void word_transform(std::ifstream &map_file, std::ifstream &input) {
    auto trans_map = buildMap(map_file);
    std::string text;
    while(std::getline(input, text)) {
        std::istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else 
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}


std::map<std::string, std::string> buildMap(std::ifstream &map_file) {
    std::map<std::string, std::string> trans_map;
    std::string key;
    std::string val;

    while (map_file >> key && std::getline(map_file, val))
        if (val.size() > 1)
            trans_map[key] = val.substr(1);
        else 
            throw std::runtime_error("no rule for " + key);
    return trans_map;
}

const std::string &transform(const std::string &s, const std::map<std::string, std::string> &m) {
    auto map_it = m.find(s);
    if (map_it != map_it.cend())
        return map_it->second;
    else 
        return s;
}

int main (void) {

    std::map<int, int> m;
    m.insert({0, 1});

    std::vector<int> v;
    v[0] = 1;

    if (m.find(0) == m.end()) std::cout << "Not in map" << std::endl;

    std::map<std::string, std::string> authors;
    std::string search_item("Alain de Botton");
    auto entries = authors.count(search_item);
    auto iter = authors.find(search_item);

    while(entries) {
        std::cout << iter->second << std::endl;
        ++iter;
        --entries;
    }

    for (auto beg = authors.lower_bound(search_item),
            end = authors.upper_bound(search_item); beg != end; ++beg)
        std::cout << beg->second << std::endl;



    // std::map<std::string, size_t> word_count;
    //
    // std::string word;
    // while (std::cin >> word) 
    //     ++word_count[word];
    //
    // for (auto &w: word_count) { 
    //     std::cout << w.first << " appears " << w.second << (w.second > 1 ? " times" : "time")
    //         << std::endl;
    // }
    //
    // std::map<std::string, size_t> word_count2;
    // std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
    //     "the", "but", "and", "or", "an", "a"};
    //
    // std::string word2;
    // while (std::cin >> word2)
    //     if (exclude.find(word) == exclude.end())
    //         ++word_count2[word2];
    //
    //
    // std::vector<std::pair<std::string, int>> pairs;
    // std::string word3;
    // int num;
    // std::pair<std::string, int> strint;
    // while (std::cin >> word3 >> num)
    //     pairs.emplace_back(word3, num);
    //
    //
    // std::map<std::string, int>::mapped_type he;
    //
    //
    // std::vector<int> ivex = {2,3,4,5};
    // std::set<int> set2;
    // set2.insert(ivex.cbegin(), ivex.cend());
    //
    // std::map<std::string, size_t> count2;
    //
    // std::string word5;
    // while (std::cin >> word5)  {
    //     auto ret = count2.insert({word5, 1});
    //     if (!ret.second) 
    //         ++ret.first->second;
    // }
    return 0;
}
