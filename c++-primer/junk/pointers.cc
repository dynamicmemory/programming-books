#include <iostream>
#include <vector>

std::vector<int> *generate_vec() {
    std::vector<int> *p = new std::vector<int>;
    return p;
}

void read_std_in(std::vector<int> *p) {
    int number;
    while (std::cin >> number)
        p->push_back(number);
}

void print_values(std::vector<int> *p) {
    for (auto q=p->begin(); q != p->end(); ++q)
        std::cout << *q << "\n";
}

int main(void) {
    std::vector<int> *v = generate_vec();
    read_std_in(v);
    print_values(v);
    delete(v);

    return 0;
}
