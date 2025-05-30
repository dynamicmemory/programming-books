#include <iostream>
#include <stdexcept>
#include "node.h"

template<class T>
class Linked_List {

public:
    Linked_List(): head(nullptr), tail(nullptr) {}
    ~Linked_List();
    bool empty();
    T front();
    void remove_from_head();
    void insert_at_tail(T);
private:
    Node<T> *head;
    Node<T> *tail;
};

template<class T>
Linked_List<T>::~Linked_List(){
    while (!empty())
        remove_from_head();
}

template<class T>
bool Linked_List<T>::empty() {
    return head == nullptr;
}

template<class T>
T Linked_List<T>::front() {
    if (!empty())
        return head->key;
    else 
        throw std::runtime_error("List empty");
}

template<class T>
void Linked_List<T>::remove_from_head() {
    if (!empty()) {
        Node<T> *p = head;
        head = head->next;
        if (head == nullptr) {   
            tail = nullptr;
        }
        delete p;
    }
}

template<class T>
void Linked_List<T>::insert_at_tail(T key) {
    Node<T> *p = new Node<T>;
    p->key = key;

    if (!empty()) {
        tail->next = p;
        tail = p;
    }
    else {
        head = p;
        tail = p;
    }
}
        
