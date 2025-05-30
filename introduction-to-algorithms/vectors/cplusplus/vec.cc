#include <iostream>

class Vec {
public:
    Vec() {
        array_limit = 0;
        pointer_to_data = nullptr;
        current_size = 0;
    }
    Vec(int size) {
        array_limit = size;
        pointer_to_data = new double[array_limit];
        current_size = 0;

        for (int i = 0; i != array_limit; ++i) 
            pointer_to_data[i] = 0.0;
    }
    ~Vec();
    Vec(const Vec&);
    Vec& operator=(const Vec&);
    double& operator[](int);
    void push_back(const double&);
    void grow();
    int get_current_size();
    int get_limit();
private:
    int array_limit;
    int current_size;
    double *pointer_to_data;
};

Vec::~Vec() {
    delete[] pointer_to_data;
    pointer_to_data = nullptr;
}

Vec& Vec::operator=(const Vec& rhs) {
    if (&rhs != this) {
        delete[] pointer_to_data;

        array_limit = rhs.array_limit;
        pointer_to_data = new double[array_limit];

        for (int i = 0; i != array_limit; ++i) 
            pointer_to_data[i] = rhs.pointer_to_data[i];
    }
    return *this;
}

Vec::Vec(const Vec& vec_to_copy) {
    array_limit = vec_to_copy.array_limit;
    pointer_to_data = new double[array_limit];

    for (int i = 0; i != array_limit; ++i) {
        pointer_to_data[i] = vec_to_copy.pointer_to_data[i];
    }
}

double& Vec::operator[](int i) {
    return pointer_to_data[i];
}

int Vec::get_current_size() {
    return current_size;
}

int Vec::get_limit() {
    return array_limit;
}

void Vec::grow() {

    int old_array_limit = array_limit;
    if (array_limit == 0) 
        array_limit += 1;
    else 
        array_limit *= 2;

    Vec v2(array_limit); 
    for (int i = 0; i != old_array_limit; ++i)
        v2.pointer_to_data[i] = pointer_to_data[i]; 

    delete[] pointer_to_data;
    pointer_to_data = v2.pointer_to_data;
}

void Vec::push_back(const double& element) {
    if (current_size == array_limit)
        grow();

    pointer_to_data[current_size] = element;
    current_size += 1;
}

int main() {

    Vec v(10);
    
    for (int i = 0; i <= 9; i++)
        v.push_back(i + 0.0);

    for (int i = 0; i <= 9; i++)
        std::cout << v[i] << std::endl;

    return 0;
}
