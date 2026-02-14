#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using std::vector, std::string;

struct PersonInfo {
    string name;
    vector<string> phones;
};


int main(void) {
    string filename = "./text.txt";

    string sentence, word;
    vector<string> lines;
    std::ifstream in(filename);

    while (getline(in, sentence))
        lines.push_back(sentence);

    for (const string &line : lines) {
        std::istringstream record(line);
        string word;
    
        while (record >> word) 
            std::cout << word << "\n";
    }


    // string line, word;
    // vector<PersonInfo> people;
    //
    // while (getline(std::cin, line)) {
    //     PersonInfo info;
        // std::istringstream record(line);
        // record >> info.name;
        // while (record >> word)
        //     info.phones.push_back(word);
    //     people.push_back(info);
    // }



    return 0;
}
