#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "node.h"

template<class T>
class Queue {

public:
    Queue() : head(nullptr), tail(nullptr) {}
    ~Queue();
    bool isEmpty();
    void dequeue();
    void enqueue(T k);
    T front();
    void printQueue();
    Node<T>* search(T k);


private:
    Node<T>* head;
    Node<T>* tail;
};

template<class T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template<class T>
bool Queue<T>::isEmpty() {
    return head == nullptr;
}

template<class T>
void Queue<T>::enqueue(T k) {
    Node<T>* p = new Node<T>;
    p->key = k;

    if (head == nullptr)
        head = p;
    else if(tail == nullptr) {
        tail = p;
        tail->prev = head;
        head->next = tail;
    }
    else 
        tail->next = p;
        p->prev = tail;
        tail = p;
}

template<class T>
void Queue<T>::dequeue() {
    if (head != nullptr) {
        Node<T>* p = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }
        delete(p);
    }
}

template<class T>
void Queue<T>::printQueue() {
    Node<T>* p = head;
    while(p != nullptr) {
        std::cout<< p->key << " ";
        p = p->next;
    }
    std::cout<<std::endl;
}

int main() {

    Queue<int> q;
        
    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.printQueue();
    q.dequeue();
    q.printQueue();

    q.dequeue();
    q.dequeue();

    return 0;
}



//
//
//
// #include <cstdio>
// #include <cstdlib>
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class Queue {
//
// public:
//     Queue() : head(nullptr), tail(nullptr) {}
//     ~Queue();
//     bool isEmpty();
//     void dequeue();
//     void enqueue(T k);
//     T front();
//     void printQueue();
//     Node<T>* search(T k);
//
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// Queue<T>::~Queue() {
//     while (!isEmpty()) {
//         dequeue();
//     }
// }
//
// template<class T>
// bool Queue<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Queue<T>::enqueue(T k) {
//     Node<T>* p = new Node<T>;
//     p->key = k;
//
//     if (head == nullptr)
//         head = p;
//     else if(tail == nullptr) {
//         tail = p;
//         tail->prev = head;
//         head->next = tail;
//     }
//     else 
//         tail->next = p;
//         p->prev = tail;
//         tail = p;
// }
//
// template<class T>
// void Queue<T>::dequeue() {
//     if (head != nullptr) {
//         Node<T>* p = head;
//         head = head->next;
//
//         if (head == nullptr) {
//             tail = nullptr;
//         }
//         delete(p);
//     }
// }
//
// template<class T>
// void Queue<T>::printQueue() {
//     Node<T>* p = head;
//     while(p != nullptr) {
//         std::cout<< p->key << " ";
//         p = p->next;
//     }
//     std::cout<<std::endl;
// }
//
// int main() {
//
//     Queue<int> q;
//
//     q.dequeue();
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     q.printQueue();
//     q.dequeue();
//     q.printQueue();
//
//     q.dequeue();
//     q.dequeue();
//
//     return 0;
// }
//
//
//
//
//
// #include <cstdio>
// #include <cstdlib>
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class Queue {
//
// public:
//     Queue() : head(nullptr), tail(nullptr) {}
//     ~Queue();
//     bool isEmpty();
//     void dequeue();
//     void enqueue(T k);
//     T front();
//     void printQueue();
//     Node<T>* search(T k);
//
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// Queue<T>::~Queue() {
//     while (!isEmpty()) {
//         dequeue();
//     }
// }
//
// template<class T>
// bool Queue<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Queue<T>::enqueue(T k) {
//     Node<T>* p = new Node<T>;
//     p->key = k;
//
//     if (head == nullptr)
//         head = p;
//     else if(tail == nullptr) {
//         tail = p;
//         tail->prev = head;
//         head->next = tail;
//     }
//     else 
//         tail->next = p;
//         p->prev = tail;
//         tail = p;
// }
//
// template<class T>
// void Queue<T>::dequeue() {
//     if (head != nullptr) {
//         Node<T>* p = head;
//         head = head->next;
//
//         if (head == nullptr) {
//             tail = nullptr;
//         }
//         delete(p);
//     }
// }
//
// template<class T>
// void Queue<T>::printQueue() {
//     Node<T>* p = head;
//     while(p != nullptr) {
//         std::cout<< p->key << " ";
//         p = p->next;
//     }
//     std::cout<<std::endl;
// }
//
// int main() {
//
//     Queue<int> q;
//
//     q.dequeue();
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     q.printQueue();
//     q.dequeue();
//     q.printQueue();
//
//     q.dequeue();
//     q.dequeue();
//
//     return 0;
// }
