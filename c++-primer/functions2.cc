#include <iostream>
#include <string>
#include <array>
#include <vector>
using std::string, std::array, std::vector;

string::size_type find_char(const string &s, char c, string::size_type &occurs) {
    auto ret = s.size();
    std::cout << ret << std::endl;
    std::cout << s.size() << std::endl;
    occurs = 0;
    for (decltype(ret) i=0; i!=s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) {
                std::cout << ret << std::endl;
                std::cout << s.size() << std::endl;
                ret = i;
            }
            ++occurs;
        }
    }
    return ret;
}

bool is_cap(const string s) {
    auto len = s.size();
    for (decltype(len) i = 0; i < s.size(); ++i) 
        if (s[i] >= 'A' && s[i] <= 'Z')
            return 1;
    return 0;
}

void print(const char *cp) {
    if (cp)
        while (*cp)
            std::cout << *cp++;
    std::cout << std::endl;
}

void print(const int *beg, const int *end) {
    while (beg != end)
        std::cout << *beg++ << std::endl;
}

void print(const int ai[], size_t size) {
    for (size_t i=0; i<size; ++i)
        std::cout << ai[i] << std::endl;
}

size_t hello(std::initializer_list<int> li) {
    size_t ret;
    for ( auto i : li)
        ret+=i;
    return ret;
}

vector<string> process() {
    return {"a", "aa", "aaa"};
}

int facto(int sum, int n) {
    if (n == 0) return sum;
    else return facto(sum*=n, n-1);
}

void vector_print(vector<int> v, size_t i=0) {
    if (i == v.size()) return;

    std::cout << v[i] << '\n';
    vector_print(v, i+1);
}

void vector_print_iterator(vector<int>::const_iterator it, vector<int>::const_iterator end) {
    if (it == end) return;

    std::cout << *it << '\n';
    vector_print_iterator(next(it), end);
}

void print_line(const char *line) {
    std::cout << line << std::endl;
}

int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int divi(int a, int b) {
    return a / b;
}

int main(void) {

    vector<int (*)(int, int)> ops;
    ops.push_back(add);
    ops.push_back(sub);
    ops.push_back(mul);
    ops.push_back(divi);

    for (auto func : ops) {
        std::cout << func(2,2) << std::endl;
    }



    // void (*pf)(const char*) = print_line;
    // pf("Pointer function");

    // std::cout << facto(1, 5) << std::endl;
    // vector<int> a = {1,2,3,4,5,6};
    // vector_print(a);

    // string::size_type b;
    // string::size_type a = find_char("Hello", 'l', b);
    // std::cout << b << std::endl;
    // std::cout << a << std::endl;
    // std::cout << is_cap("hello");

    // string a = "hello";
    // int c = a.size();
    // string::size_type d = a.size();
    // std::cout << c << std::endl;
    // std::cout << d << std::endl;
    // print("hello");
    
    // int a[] = {1,2,3,4,5};
    // print(std::begin(a), std::end(a)); 
    // print(a, 5);
    // size_t h = hello({1,2,3,4,5,6,6});
    // std::cout << h << std::endl;

    return 0;
}
