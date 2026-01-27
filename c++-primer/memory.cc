#include <iostream>
#include <memory>
#include <list>
#include <vector>
using std::shared_ptr;

shared_ptr<Foo> factory(T arg);



int main(void) {

    std::shared_ptr<std::string> p1;
    std::shared_ptr<std::list<int>> p2;

    if (p1 && p1->empty())
        *p1 = "hi";

    std::shared_ptr<int> p3 = std::make_shared<int>(43);
    std::shared_ptr<std::string> p4 = std::make_shared<std::string>(10, '9');

    auto p6 = std::make_shared<std::vector<std::string>>;

    auto p = std::make_shared<int>(43);
    auto q(p);

    

    return 0;
}
