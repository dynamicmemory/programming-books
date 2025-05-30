#include <iostream>
#include "node.h"

template<class T>
class LinkedList {
public:
    LinkedList(): head(nullptr) {}
    ~LinkedList();
    bool isEmpty();
    void insert(T);
    Node<T> *search(T);
    void remove(T);
    int size();
    void print();
private:
    Node<T> *head;
};

template<class T>
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}

template<class T>
LinkedList<T>::~LinkedList() {
    Node<T> *p = head;
    while (p != nullptr) {
        Node<T> *next = p->next;
        delete p;
        p = next;
    }
}

template<class T>
int LinkedList<T>::size() {
    int n = 0;
    Node<T> *p = head;
    while (p != nullptr) {
        n += 1;
        p = p->next;
    }
        
    return n;
}

template<class T>
void LinkedList<T>::insert(T key) {
    Node<T> *p = new Node<T>;
    p->key = key;
    p->next = head;

    if (head != nullptr)
        head->prev = p;

    head = p;
}

template<class T>
Node<T> *LinkedList<T>::search(T key) {
    Node<T> *p = head;

    if (p == nullptr)
        return nullptr;

    if (p->key == key)
        return p;

    while (p != nullptr && p->key != key)
        p = p->next;

    return p;
}

template<class T>
void LinkedList<T>::remove(T key) {
    Node<T> *p = search(key);

    if (p == nullptr)
        return;
    
    if (p == head) {
        head = head->next;
        if (head != nullptr) 
            head->prev = nullptr;
    }
    else {
        if (p->next != nullptr) 
            p->next->prev = p->prev;

        if (p->prev != nullptr)
            p->prev->next = p->next;
    }
    delete p;
}

template<class T>
void LinkedList<T>::print() {
    Node<T> *p = head;
    while (p != nullptr) {
        std::cout << p->key << " ";
        p = p->next;
    }
    std::cout << "\n";
}
