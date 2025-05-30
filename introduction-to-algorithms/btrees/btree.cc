#include <iostream>
#include "node.h"

template<class T>
class Btree {

public:
    Btree(int degree): t(degree){
        root = new Node<T>;
        }  
    ~Btree();
    Node<T> *search(Node<T>*, T);
    void insert(T);
    void remove(T);

private:
    void destroy(Node<T> *);
    Node<T> *root;
    int t;
};

template<class T>
Btree<T>::~Btree() {
    destroy(root);
}

template<class T>
void Btree<T>::destroy(Node<T> *p) {
    if (!p)
        return;

    for (auto child : p->children) 
        destroy(child);
    delete p;
}




int main () {

    return 0;
}
