#include <iostream>
#include <sstream>
#include  <fstream>
#include <vector>
#include <string>
using std::cin, std::cout, std::cerr, std::endl, std::string, std::vector,
      std::istringstream, std::ostringstream;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(const string &num) {
    if (num.size() < 7) return false;

    for (char c : num)
        if (!std::isdigit(c))
            return false;

    return true;
    }

string format(const string &num) {
    return num;
}

int main(void) {

    vector<PersonInfo> people;
    string line, word;

    while (std::getline(cin, line)) {
        PersonInfo entry;
        istringstream record(line);      //takes the whole string

        record >> entry.name;            // first word is the name 
        while (record >> word)
            entry.phones.push_back(word);

        people.push_back(entry);
    }

    // Output processing the records 
    for (const auto &entry : people) {
        ostringstream formatted, badNums;

        for (const auto &num : entry.phones) {
            if (!valid(num))
                badNums << " " << num;
            else 
                formatted << " " << format(num);
        }

        if (badNums.str().empty())
            cout << entry.name << formatted.str() << endl;
        else 
            cerr << "input error: " << entry.name << "invalid number(s)" << 
                badNums.str() << endl;
    }
    return 0;
}
