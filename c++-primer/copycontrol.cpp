#include <iostream>
#include <string>

class Buffer {
public:
    Buffer(size_t size) {
        data = new int[size];
    }

    Buffer(const Buffer &rhs) {
        size = rhs.size;
        data = new int[size];
        std::copy(rhs.data, rhs.data + size, data);
    }

    ~Buffer() {
        delete[] data;
    }

private:
    int *data;
    size_t size;
};


class IntArray {
    int *data;
    size_t size;

public:
    IntArray(size_t s) : size(s) {
        data = new int[size];
    }

    ~IntArray() {
        delete[] data;
    }

    IntArray(const IntArray &rhs) {
        size = rhs.size;
        std::copy(rhs.data, rhs.data + size, data);
    }
};


int main(void) {

    Buffer b(1024);
    Buffer a = b;

    return 0;
}
