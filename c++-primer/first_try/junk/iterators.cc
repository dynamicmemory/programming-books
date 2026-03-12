#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <istream>
#include <vector>
#include <fstream>

int main(void) {

    // std::vector<int> ivec;
    // std::istream_iterator<int> in_iter(std::cin);
    // std::istream_iterator<int> eof;
    //
    // while (in_iter != eof)
    //     ivec.push_back(*in_iter++);
    //
    // std::ostream_iterator<int> out_iter(std::cout, " ");
    // for (auto e: ivec) 
    //     *out_iter++ = e;
    // std::cout << std::endl;
    //
    // std::copy(ivec.begin(), ivec.end(), out_iter);
    // std::cout << std::endl;

    std::ifstream in("./file");
    std::istream_iterator<std::string> str_iter(in);
    std::istream_iterator<std::string> eof;
    // Reads in individual words
    std::vector<std::string> words(str_iter, eof);

    // Reads in lines
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
        lines.push_back(line);
    }

    std::istream_iterator<int> int_iter(std::cin);
    std::istream_iterator<int> int_eof;
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::vector<int> nums(int_iter, int_eof);

    std::sort(nums.begin(), nums.end());
    std::copy(nums.begin(), nums.end(), out_iter);
    std::cout << std::endl;

    auto comma = std::find(lines.begin(), lines.end(), ',');

    std::copy(nums.rbegin(), nums.rend(), out_iter);

    auto last_zero = std::find(nums.rbegin(), nums.rend(), 0);

    return 0;
}
