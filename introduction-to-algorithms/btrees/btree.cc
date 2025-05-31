#include <iostream>
#include "node.h"

template<class T>
class Btree {

public:
    Btree(int degree): t(degree){
        root = new Node<T>;
        }  
    ~Btree();
    std::pair<Node<T>*, int> search(Node<T>*, T);
    void splitchild(Node<T> *, int);
    void insert(T);
    void splitroot();
    void insertnonfull(Node<T> *, int);

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

template<class T>
std::pair<Node<T>*, int> Btree<T>::search(Node<T> *p, T key) {

    int i = 0;
    while (i < p->keys.size() && key > p->keys[i])
         i++;         

    if (i <= t && key == p->keys[i])
        return {p, i}; 
    else if (p->isleaf)
        return {nullptr, -1};
    else 
        return search(p->children[i], key);
 }

template<class T>
void Btree<T>::splitchild(Node<T> *p, int i) {
    Node<T> *y = p->children[i];
    Node<T> *z = new Node<T>;

    z->isleaf = y->isleaf;

    for (int j = 0; j < t-1; ++j) 
        z->keys.push_back(y->keys[j + t]);

    if (!y->isleaf) 
        for (int j = 0; j < t; ++j)
            z->children.push_back(y->children[j + t]);

    y->keys.resize(t - 1);
    if (!y->isleaf)
        y->children.resize(t);

    p->children.insert(p->children.begin() + i + 1, z);

    p->keys.insert(p->keys.begin() + i, y->keys[t - 1]);
}

template<class T>
void Btree<T>::insert(T key) {
    if (root->keys.size() == 2*t-1) {
        Node<T> *s = new Node<T>;
        s->isleaf = false;
        s->children.push_back(root);
        splitchild(s, 0);
        root = s;
        insertnonfull(s, key);
    }
    else 
        insertnonfull(root, key);
}

template<class T>
void Btree<T>::splitroot() {
}

template<class T>
void Btree<T>::insertnonfull(Node<T> *p, int key) {
    int i = p->keys.push_back(0);
    
    if (p->isleaf) {
        p->keys.push_back(0);
        while (i >= 0 && key < p->key[i]) {
            p->keys[i + 1] = p->keys[i];
            i--;
        }
        p->keys[i + 1] = key;
    }
    else {
        while (i >= 0 && key < p->keys[i])
            i--;
       i++;

       if (p->children[i]->keys.size() == 2* t-1) {
           splitchild(p, i);

           if (key > p->keys[i])
               i++;
       }
       insertnonfull(p->children[i], key);
    }
}


int main () {

    return 0;
}
