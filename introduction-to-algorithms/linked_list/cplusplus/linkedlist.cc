#include <iostream>
#include "node.h"

template<class T> 
class Linked_List {

public:
    Linked_List(): head(nullptr), tail(nullptr) {}
    ~Linked_List();
    bool isEmpty();
    void insert(T key);
    void insert(Node<T>* p);
    void remove_from_head();
    void remove(T key);
    Node<T>* search(T key);
    void sort();
    void print_list();

private:
    Node<T>* head;
    Node<T>* tail;
};

template<class T>
bool Linked_List<T>::isEmpty() {
    return head == nullptr;
}

template<class T>
void Linked_List<T>::remove_from_head() {
    while (!isEmpty())
        remove(head->key);
}

template<class T>
Linked_List<T>::~Linked_List() {
    remove_from_head();
}

template<class T>
void Linked_List<T>::insert(T key) {
    insert(new Node<T>(key));
}

template<class T>
void Linked_List<T>::insert(Node<T>* p) {
    if (isEmpty())
        head = p;
    
    else {
        p->next = head;
        head->prev = p;
        head = p;
    }
}

template<class T>
Node<T>* Linked_List<T>::search(T key) {
    Node<T>* p = head;

    while (p != nullptr && p->key != key) {
        p = p->next;
    }
    return p;
}

template<class T>
void Linked_List<T>::remove(T key) {
    Node<T>* p = search(key);

    if (p == nullptr)
        return;
    //
    if (p->next != nullptr)
        p->next->prev = p->prev;

    if (p->prev != nullptr)
        p->prev->next = p->next;
    else
        head = p->next;

    if (p == tail)
        tail = p->prev;


    // Node<T>* p = search(key);
    //
    // if (p != nullptr) {
    //     Node<T>* temp = p;
    //
    //     if (p->next != nullptr)
    //         p->next->prev = p->prev;
    //
    //     if (p->prev != nullptr)
    //         p->prev->next = p->next;    
    // }
    // delete p;
}

template<class T>
void Linked_List<T>::print_list() {
    Node<T>* p = head;
    while (p != nullptr) {
        std::cout << p->key << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main(){

    Linked_List<int> ls;

    ls.insert(5);
    
    ls.print_list();

    ls.insert(8);
    ls.insert(4);
    ls.insert(1);
    ls.insert(3);
    ls.insert(9);
    ls.insert(8);

    ls.print_list();
}








// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
// #include <iostream>
// #include "node.h"
//
// template<class T> 
// class Linked_List {
//
// public:
//     Linked_List(): head(nullptr), tail(nullptr) {}
//     ~Linked_List();
//     bool isEmpty();
//     void insert(T key);
//     void insert(Node<T>* p);
//     void remove_from_head();
//     void remove(T key);
//     Node<T>* search(T key);
//     void sort();
//     void print_list();
//
// private:
//     Node<T>* head;
//     Node<T>* tail;
// };
//
// template<class T>
// bool Linked_List<T>::isEmpty() {
//     return head == nullptr;
// }
//
// template<class T>
// void Linked_List<T>::remove_from_head() {
//     while (!isEmpty())
//         remove(head->key);
// }
//
// template<class T>
// Linked_List<T>::~Linked_List() {
//     remove_from_head();
// }
//
// template<class T>
// void Linked_List<T>::insert(T key) {
//     insert(new Node<T>(key));
// }
//
// template<class T>
// void Linked_List<T>::insert(Node<T>* p) {
//     if (isEmpty())
//         head = p;
//
//     else {
//         p->next = head;
//         head->prev = p;
//         head = p;
//     }
// }
//
// template<class T>
// Node<T>* Linked_List<T>::search(T key) {
//     Node<T>* p = head;
//
//     while (p != nullptr && p->key != key) {
//         p = p->next;
//     }
//     return p;
// }
//
// template<class T>
// void Linked_List<T>::remove(T key) {
//     Node<T>* p = search(key);
//
//     if (p == nullptr)
//         return;
//     //
//     if (p->next != nullptr)
//         p->next->prev = p->prev;
//
//     if (p->prev != nullptr)
//         p->prev->next = p->next;
//     else
//         head = p->next;
//
//     if (p == tail)
//         tail = p->prev;
//
//
//     // Node<T>* p = search(key);
//     //
//     // if (p != nullptr) {
//     //     Node<T>* temp = p;
//     //
//     //     if (p->next != nullptr)
//     //         p->next->prev = p->prev;
//     //
//     //     if (p->prev != nullptr)
//     //         p->prev->next = p->next;    
//     // }
//     // delete p;
// }
//
// template<class T>
// void Linked_List<T>::print_list() {
//     Node<T>* p = head;
//     while (p != nullptr) {
//         std::cout << p->key << " ";
//         p = p->next;
//     }
//     std::cout << std::endl;
// }
//
// int main(){
//
//     Linked_List<int> ls;
//
//     ls.insert(5);
//
//     ls.print_list();
//
//     ls.insert(8);
//     ls.insert(4);
//     ls.insert(1);
//     ls.insert(3);
//     ls.insert(9);
//     ls.insert(8);
//
//     ls.print_list();
// }
