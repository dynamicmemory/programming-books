#include "node.h"
#include <iostream>

template<class T>
class Stack {

public:
    Stack(): head() {}
    ~Stack();
    bool isEmpty();
    T top();
    void pop();
    void push(T k);

private:
    Node<T>* head;
};

template<class T>
Stack<T>::~Stack() {
    while (head != nullptr)
        pop();
}

template<class T>
bool Stack<T>::isEmpty() {
    return head == nullptr;
}

template<class T>
T Stack<T>::top() {
    if (isEmpty())
        return 69;
    return head->key;
}

template<class T>
void Stack<T>::pop() {
    if (isEmpty())
        return;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

template<class T>
void Stack<T>::push(T k) {
    Node<T>* p = new Node<T>;
    p->key = k;
    p->next = head;
    head = p;
}

int main() {
    Stack<int> s;

    s.push(1);
    s.push(3);
    s.push(6);
    int a = s.top();
    std::cout << a << " ";
    s.pop();
    int b = s.top();
    std::cout << b << " ";
    s.pop();
    std::cout << s.top() << " ";
}



























// #include "node.h"
// #include <iostream>
//
// template<class T>
// class Stack {
//
// public:
//     Stack(): head() {}
//     ~Stack();
//     bool isEmpty();
//     T top();
//     void pop();
//     void push(T k);
//
// private:
//     Node<T>* head;
// };
//
// template<class T>
// Stack<T>::~Stack() {
//     while (head != nullptr)
//         pop();
// }
//
// template<class T>
// bool Stack<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// T Stack<T>::top() {
//     if (isEmpty())
//         return 69;
//     return head->key;
// }
//
// template<class T>
// void Stack<T>::pop() {
//     if (isEmpty())
//         return;
//     Node<T>* temp = head;
//     head = head->next;
//     delete temp;
// }
//
// template<class T>
// void Stack<T>::push(T k) {
//     Node<T>* p = new Node<T>;
//     p->key = k;
//     p->next = head;
//     head = p;
// }
//
// int main() {
//     Stack<int> s;
//
//     s.push(1);
//     s.push(3);
//     s.push(6);
//     int a = s.top();
//     std::cout << a << " ";
//     s.pop();
//     int b = s.top();
//     std::cout << b << " ";
//     s.pop();
//     std::cout << s.top() << " ";
// }
//
//
//
//
//
// #include "node.h"
// #include <iostream>
//
// template<class T>
// class Stack {
//
// public:
//     Stack(): head() {}
//     ~Stack();
//     bool isEmpty();
//     T top();
//     void pop();
//     void push(T k);
//
// private:
//     Node<T>* head;
// };
//
// template<class T>
// Stack<T>::~Stack() {
//     while (head != nullptr)
//         pop();
// }
//
// template<class T>
// bool Stack<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// T Stack<T>::top() {
//     if (isEmpty())
//         return 69;
//     return head->key;
// }
//
// template<class T>
// void Stack<T>::pop() {
//     if (isEmpty())
//         return;
//     Node<T>* temp = head;
//     head = head->next;
//     delete temp;
// }
//
// template<class T>
// void Stack<T>::push(T k) {
//     Node<T>* p = new Node<T>;
//     p->key = k;
//     p->next = head;
//     head = p;
// }
//
// int main() {
//     Stack<int> s;
//
//     s.push(1);
//     s.push(3);
//     s.push(6);
//     int a = s.top();
//     std::cout << a << " ";
//     s.pop();
//     int b = s.top();
//     std::cout << b << " ";
//     s.pop();
//     std::cout << s.top() << " ";
// }
