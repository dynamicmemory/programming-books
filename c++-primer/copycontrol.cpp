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


class TestArray {
    int *data;
    size_t size;

public:
    TestArray(size_t s) : size(s) {
        data = new int[size];
        for (size_t i=0; i<size; ++i)
            data[i] = i;
    }

    TestArray(const TestArray &rhs) {
        size = rhs.size;
        data = new int[size];
        std::copy(rhs.data, rhs.data + size, data);
    }

    TestArray &operator=(const TestArray &rhs) {
        if (this == &rhs) return *this;

        int *newdata = new int[rhs.size];
        std::copy(rhs.data, rhs.data + rhs.size, newdata);
        delete[] data;

        data = newdata; 
        size = rhs.size;
        return *this;
    }

    TestArray(TestArray &rhs) : size(rhs.size), data(rhs.data) {
        rhs.data = nullptr;
        rhs.size = 0;
    }

    TestArray &operator=(TestArray &&rhs) {
        if (this == &rhs)
            return *this;

        data = rhs.data;
        size = rhs.size;

        rhs.data = nullptr;
        rhs.size = 0;

        return *this;
    }

    ~TestArray() {
        delete[] data;
    }
};

int main(void) {

    Buffer b(1024);
    Buffer a = b;

    return 0;
}
