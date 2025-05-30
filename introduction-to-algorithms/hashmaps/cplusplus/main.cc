#include <iostream>
#include "linkedlist.h"

template<class T>
class Hashmap {
public:
    Hashmap();
    ~Hashmap();
    void insert(T);
    bool contains(T);
    void remove(T);
    void print();
private:
    int hash(T);
    LinkedList<T> *buckets;
    int bucketCount = 13;
};

template<class T>
Hashmap<T>::Hashmap() {
    buckets = new LinkedList<T>[bucketCount];
}

template<class T>
Hashmap<T>::~Hashmap() {
    delete[] buckets;
}

template<class T>
int Hashmap<T>::hash(T key) {
    return key % bucketCount;
}

template<class T>
void Hashmap<T>::insert(T key) {
    int index = hash(key);
    std::cout << "we dont blow up here" << "\n";
    if (!contains(key))  {
        std::cout << "we never make it here" << "\n";
        buckets[index].insert(key);
    }
}

template<class T>
bool Hashmap<T>::contains(T key) {
    int index = hash(key);
    return buckets[index].search(key) != nullptr;
}

template<class T>
void Hashmap<T>::remove(T key) {
    int index = hash(key);
    buckets[index].remove(key);
}

template<class T>
void Hashmap<T>::print() {
    for (int i = 0; i < bucketCount; i++) {
        std::cout << "Bucket" << i << ": ";
        buckets[i].print();
    }
}

int main() {
 
    Hashmap<int> map;

    map.print();
    map.insert(69);
    map.insert(420);
    map.print();
    
    bool b = (map.contains(79)) ? true : false;
    std::cout << b << "\n";
    bool e = (map.contains(420)) ? true : false;
    std::cout << e << "\n";
    //
    map.remove(69);
    map.print();

    return 0;
}
