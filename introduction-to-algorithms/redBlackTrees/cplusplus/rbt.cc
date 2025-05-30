#include <filesystem>
#include <iostream>
#include "node.h"

template<class T>
class RBT {

public:
    RBT() {
        NIL = new Node<T>();
        NIL->colour = BLACK;
        NIL->left = NIL;
        NIL->right = NIL;
        NIL->parent = NIL;
        root = NIL;
    }
    ~RBT();
    bool isEmpty();
    Node<T> *min();
    Node<T> *max();
    Node<T> *predecessor(Node<T> *);
    Node<T> *successor(Node<T> *);
    Node<T> *search(T);
    void leftRotate(Node<T> *);
    void rightRotate(Node<T> *);
    void insert(T);
    void remove(T);
    void walkTree();

private:
    Node<T> *root;
    Node<T> *NIL = new Node<T>();

    void walkTree(Node<T> *);
};

template<class T>
bool RBT<T>::isEmpty() {
    return root == NIL;
}

template<class T>
RBT<T>::~RBT() {
    while (!isEmpty())
        remove(root->key);
}

template<class T>
Node<T> *RBT<T>::min() {
    Node<T> *p = root; 
    while (p->left != NIL)
        p = p->left;
    return p;
}

template<class T>
Node<T> *RBT<T>::max() {
    Node<T> *p = root; 
    while (p->right != NIL)
        p = p->right;
    return p;
}

template<class T>
Node<T> *RBT<T>::predecessor(Node<T> *p) {
    if (p == NIL)
        return NIL;

    if (p->left != NIL) {
        Node<T> *current = p->left;
        while (current->right != NIL)
            current = current->right;
        return current;
    }

    Node<T> *parent = p->parent;
    while (parent != NIL && p == parent->left) {
        p = parent;
        parent = p->parent;
    }
    return parent;
}

template<class T>
Node<T> *RBT<T>::successor(Node<T> *p) {
    if (p == NIL)
        return;

    if (p->right != NIL) {
        Node<T> *current = p->right;
        while (current->right != NIL)
            current = current->right;
        return current;
    }

    Node<T> *parent = p->parent;
    while (parent != NIL && p == parent->right) {
        p = parent;
        parent = p->parent;
    }
    return parent;
}

template<class T>
Node<T> *RBT<T>::search(T key) {
    Node<T> *p = root;

    while (p != NIL && p->key != key) {
        if (key < p->key)
            p = p->left;
        else 
            p = p->right;
    }

    if (p != NIL)
        return p;
    else 
        return NIL;
}

template<class T>
void RBT<T>::walkTree() {
    walkTree(root);
}

template<class T>
void RBT<T>::walkTree(Node<T> *p) {
    if (p != NIL) {
        walkTree(p->left);
        std::cout << p->key << " ";
        walkTree(p->right);
    }
}

template<class T>
void RBT<T>::leftRotate(Node<T> *p) {
    Node<T> *q = p->right;
    p->right = q->left;

    if (q->left != NIL)
        q->left->parent = p;
    q->parent = p->parent;

    if (p->parent == NIL)
        root = q;
    else if (p == p->parent->left)
        p->parent->left = q;
    else 
        p->parent->right = q;
    q->left = p;
    p->parent = q;
}

template<class T>
void RBT<T>::rightRotate(Node<T> *p) {
    Node<T> *q = p->left;
    p->left = q->right;

    if (q->right != NIL)
        q->right->parent = p;
    q->parent = p->parent;

    if (p->parent == NIL)
        root = q;
    else if (p == p->parent->right)
        p->parent->right = q;
    else 
        p->parent->left = q;
    q->right = p;
    p->parent = q;
}

template<class T>
void RBT<T>::insert(T key) {
    Node<T> *p = new Node<T>;
    p->key = key;

    Node<T> *q = root;
    Node<T> *s = NIL;

    while (q != NIL)
        s = q;
        if (p->key < q->key)
            q = q->left;
        else 
            q = q->right;

    p->parent = s;
    if (s == NIL)
        root = p;
    else if (p->key < s->key)
        s->left = p;
    else 
        s->right = p;

    p->left = NIL;
    p->right = NIL;
    p->colour = RED;
    insertFixup(p);
}

template<class T>
void RBT<T>::remove(T key) {

}
