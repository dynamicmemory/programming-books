#include <iostream>
#include <array>

int main(void) {
    unsigned i = 0, j;
    std::cout << i << " " << j << std::endl;
    j = ++i;
    std::cout << i << " " << j << std::endl;
    j = i++;
    std::cout << i << " " << j << std::endl;

    int array[] = {1,2,3,4,5};
    int *p = array;

    std::cout << sizeof(array) << std::endl;
    std::cout << sizeof(array)/sizeof(*array) << std::endl;
    std::cout << sizeof(array)/sizeof(*array) << std::endl;
    std::cout << sizeof(array)/sizeof(*p) << std::endl;

    int e;
    int *q;

    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(long) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(double) << std::endl;




    return 0;
}
