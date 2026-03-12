#include <iostream>
#include <fstream>
using std::istream;

istream &read(istream &in) {
    std::string word;

    while (in >> word)
        std::cout << word;

    in.clear();
    return in;
}

int main(void) {

    // Define a filename
    std::string filename = "./text.txt";

    // Open the file for reading
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Failed to open" << filename << std::endl;
        return -1;
    }

    // Open a new file to copy into
    std::ofstream out(filename + ".copy", std::ofstream::app);
    if (!out) {
        std::cerr << "Failed to open" << filename << std::endl;
        return -1;
    }

    // Read each line and copy the contents from one file to the other.
    std::string line;
    while (std::getline(in, line)) { 
        std::cout << line << '\n';
        out << line << '\n';
    }

    return 0;
}
