#include <iostream>
#include "node.h"

template<class T>
class bst {

public:
    bst(Node<T> *r = nullptr) : root(r) {}
    ~bst();
    bool isEmpty();
    void walkTree();
    void walkTreeHelper(Node<T> *);
    void insert(T);
    void insertHelper(T, Node<T>*, Node<T>*);
    void remove(T);
    void removeHelper(T, Node<T>*, Node<T>*);
    void transplant(Node<T> *, Node<T> *);
    Node<T> *search(T);
private:
    Node<T> *root;
};

template<class T>
bool bst<T>::isEmpty() {
     return root == nullptr;
}

template<class T>
bst<T>::~bst() {
}

template<class T>
void bst<T>::insert(T key) {
    Node<T> *newNode = new Node<T>(key);

    if (isEmpty()) 
        root = newNode;
    else
        insertHelper(key, newNode, root);
}

template<class T>
void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
    
    if (p->key < q->key) 
        if (q->left == nullptr) {
            p->parent = q;
            q->left = p;
        }
        else 
            insertHelper(key, p, q->left);
    
    else if (p->key > q->key) {
        if (q->right == nullptr) {
            p->parent = q;
            q->right = p;
        }
        else
            insertHelper(key, p, q->right);
    }
    else 
        delete(p);
}

template<class T>
Node<T> *bst<T>::search(T key) {

    Node<T> *p = root;
    while (p->key != key)
    
        if (key < p->key && p->left != nullptr)
            p = p->left;
        else if (key > p->key && p->right != nullptr)
            p = p->right;
        else if (p->key == key)
            break;
        else
            return nullptr;
    return p;
}

template<class T>
void bst<T>::transplant(Node<T> *p, Node<T> *q) {
    if (p->parent == nullptr)
        root = q;
    else if (p == p->parent->left)
        p->parent->left = q;
    else 
        p->parent->right = q;

    if (q != nullptr)
        q->parent = p->parent;
}

template<class T>
void bst<T>::remove(T key) {
    Node<T> *p = search(key);

    if (p == nullptr)
        return;

    if (p->left == nullptr) 
        transplant(p, p->right);
    else if (p->right == nullptr) 
        transplant(p, p->left);
    else {
        Node<T> *q = p->right;
        while (q->left != nullptr) 
            q = q->left;
       
        if (q->parent != p) {
            transplant(q, q->right);
            q->right = p->right;
            if (q->right)
                q->right->parent = q;
        }

        transplant(p, q);
        q->left = p->left;
        if (q->left)
            q->left->parent = q;
    }

    delete(p);
}

template<class T>
void bst<T>::walkTree() {
    walkTreeHelper(root);
}

template<class T>
void bst<T>::walkTreeHelper(Node<T> *p) {
    if (p != nullptr) {
        walkTreeHelper(p->left);
        std::cout << p->key << " ";
        walkTreeHelper(p->right);
    }
}

int main() {
    
    bst<int> tree;

    tree.insert(5);
    tree.insert(1);
    tree.insert(8);
    tree.insert(4);
    tree.insert(2);
    tree.insert(9);
    tree.insert(7);
    //

    tree.walkTree();
    std::cout << '\n';
    tree.remove(5);
    tree.walkTree();
    //
    return 0;
}




// #include <iostream>
// #include "node.h"
//
// template<class T>
// class bst {
//
// public:
//     bst(Node<T> *r = nullptr) : root(r) {}
//     ~bst();
//     bool isEmpty();
//     void walkTree();
//     void walkTreeHelper(Node<T> *);
//     void insert(T);
//     void insertHelper(T, Node<T>*, Node<T>*);
//     void remove(T);
//     void removeHelper(T, Node<T>*, Node<T>*);
//     void transplant(Node<T> *, Node<T> *);
//     Node<T> *search(T);
// private:
//     Node<T> *root;
// };
//
// template<class T>
// bool bst<T>::isEmpty() {
//      return root == nullptr;
// }
//
// template<class T>
// bst<T>::~bst() {
// }
//
// template<class T>
// void bst<T>::insert(T key) {
//     Node<T> *newNode = new Node<T>(key);
//
//     if (isEmpty()) 
//         root = newNode;
//     else
//         insertHelper(key, newNode, root);
// }
//
// template<class T>
// void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
//
//     if (p->key < q->key) 
//         if (q->left == nullptr) {
//             p->parent = q;
//             q->left = p;
//         }
//         else 
//             insertHelper(key, p, q->left);
//
//     else if (p->key > q->key) {
//         if (q->right == nullptr) {
//             p->parent = q;
//             q->right = p;
//         }
//         else
//             insertHelper(key, p, q->right);
//     }
//     else 
//         delete(p);
// }
//
// template<class T>
// Node<T> *bst<T>::search(T key) {
//
//     Node<T> *p = root;
//     while (p->key != key)
//
//         if (key < p->key && p->left != nullptr)
//             p = p->left;
//         else if (key > p->key && p->right != nullptr)
//             p = p->right;
//         else if (p->key == key)
//             break;
//         else
//             return nullptr;
//     return p;
// }
//
// template<class T>
// void bst<T>::transplant(Node<T> *p, Node<T> *q) {
//     if (p->parent == nullptr)
//         root = q;
//     else if (p == p->parent->left)
//         p->parent->left = q;
//     else 
//         p->parent->right = q;
//
//     if (q != nullptr)
//         q->parent = p->parent;
// }
//
// template<class T>
// void bst<T>::remove(T key) {
//     Node<T> *p = search(key);
//
//     if (p == nullptr)
//         return;
//
//     if (p->left == nullptr) 
//         transplant(p, p->right);
//     else if (p->right == nullptr) 
//         transplant(p, p->left);
//     else {
//         Node<T> *q = p->right;
//         while (q->left != nullptr) 
//             q = q->left;
//
//         if (q->parent != p) {
//             transplant(q, q->right);
//             q->right = p->right;
//             if (q->right)
//                 q->right->parent = q;
//         }
//
//         transplant(p, q);
//         q->left = p->left;
//         if (q->left)
//             q->left->parent = q;
//     }
//
//     delete(p);
// }
//
// template<class T>
// void bst<T>::walkTree() {
//     walkTreeHelper(root);
// }
//
// template<class T>
// void bst<T>::walkTreeHelper(Node<T> *p) {
//     if (p != nullptr) {
//         walkTreeHelper(p->left);
//         std::cout << p->key << " ";
//         walkTreeHelper(p->right);
//     }
// }
//
// int main() {
//
//     bst<int> tree;
//
//     tree.insert(5);
//     tree.insert(1);
//     tree.insert(8);
//     tree.insert(4);
//     tree.insert(2);
//     tree.insert(9);
//     tree.insert(7);
//     //
//
//     tree.walkTree();
//     std::cout << '\n';
//     tree.remove(5);
//     tree.walkTree();
//     //
//     return 0;
// }
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class bst {
//
// public:
//     bst(Node<T> *r = nullptr) : root(r) {}
//     ~bst();
//     bool isEmpty();
//     void walkTree();
//     void walkTreeHelper(Node<T> *);
//     void insert(T);
//     void insertHelper(T, Node<T>*, Node<T>*);
//     void remove(T);
//     void removeHelper(T, Node<T>*, Node<T>*);
//     void transplant(Node<T> *, Node<T> *);
//     Node<T> *search(T);
// private:
//     Node<T> *root;
// };
//
// template<class T>
// bool bst<T>::isEmpty() {
//      return root == nullptr;
// }
//
// template<class T>
// bst<T>::~bst() {
// }
//
// template<class T>
// void bst<T>::insert(T key) {
//     Node<T> *newNode = new Node<T>(key);
//
//     if (isEmpty()) 
//         root = newNode;
//     else
//         insertHelper(key, newNode, root);
// }
//
// template<class T>
// void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
//
//     if (p->key < q->key) 
//         if (q->left == nullptr) {
//             p->parent = q;
//             q->left = p;
//         }
//         else 
//             insertHelper(key, p, q->left);
//
//     else if (p->key > q->key) {
//         if (q->right == nullptr) {
//             p->parent = q;
//             q->right = p;
//         }
//         else
//             insertHelper(key, p, q->right);
//     }
//     else 
//         delete(p);
// }
//
// template<class T>
// Node<T> *bst<T>::search(T key) {
//
//     Node<T> *p = root;
//     while (p->key != key)
//
//         if (key < p->key && p->left != nullptr)
//             p = p->left;
//         else if (key > p->key && p->right != nullptr)
//             p = p->right;
//         else if (p->key == key)
//             break;
//         else
//             return nullptr;
//     return p;
// }
//
// template<class T>
// void bst<T>::transplant(Node<T> *p, Node<T> *q) {
//     if (p->parent == nullptr)
//         root = q;
//     else if (p == p->parent->left)
//         p->parent->left = q;
//     else 
//         p->parent->right = q;
//
//     if (q != nullptr)
//         q->parent = p->parent;
// }
//
// template<class T>
// void bst<T>::remove(T key) {
//     Node<T> *p = search(key);
//
//     if (p == nullptr)
//         return;
//
//     if (p->left == nullptr) 
//         transplant(p, p->right);
//     else if (p->right == nullptr) 
//         transplant(p, p->left);
//     else {
//         Node<T> *q = p->right;
//         while (q->left != nullptr) 
//             q = q->left;
//
//         if (q->parent != p) {
//             transplant(q, q->right);
//             q->right = p->right;
//             if (q->right)
//                 q->right->parent = q;
//         }
//
//         transplant(p, q);
//         q->left = p->left;
//         if (q->left)
//             q->left->parent = q;
//     }
//
//     delete(p);
// }
//
// template<class T>
// void bst<T>::walkTree() {
//     walkTreeHelper(root);
// }
//
// template<class T>
// void bst<T>::walkTreeHelper(Node<T> *p) {
//     if (p != nullptr) {
//         walkTreeHelper(p->left);
//         std::cout << p->key << " ";
//         walkTreeHelper(p->right);
//     }
// }
//
// int main() {
//
//     bst<int> tree;
//
//     tree.insert(5);
//     tree.insert(1);
//     tree.insert(8);
//     tree.insert(4);
//     tree.insert(2);
//     tree.insert(9);
//     tree.insert(7);
//     //
//
//     tree.walkTree();
//     std::cout << '\n';
//     tree.remove(5);
//     tree.walkTree();
//     //
//     return 0;
// }
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class bst {
//
// public:
//     bst(Node<T> *r = nullptr) : root(r) {}
//     ~bst();
//     bool isEmpty();
//     void walkTree();
//     void walkTreeHelper(Node<T> *);
//     void insert(T);
//     void insertHelper(T, Node<T>*, Node<T>*);
//     void remove(T);
//     void removeHelper(T, Node<T>*, Node<T>*);
//     void transplant(Node<T> *, Node<T> *);
//     Node<T> *search(T);
// private:
//     Node<T> *root;
// };
//
// template<class T>
// bool bst<T>::isEmpty() {
//      return root == nullptr;
// }
//
// template<class T>
// bst<T>::~bst() {
// }
//
// template<class T>
// void bst<T>::insert(T key) {
//     Node<T> *newNode = new Node<T>(key);
//
//     if (isEmpty()) 
//         root = newNode;
//     else
//         insertHelper(key, newNode, root);
// }
//
// template<class T>
// void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
//
//     if (p->key < q->key) 
//         if (q->left == nullptr) {
//             p->parent = q;
//             q->left = p;
//         }
//         else 
//             insertHelper(key, p, q->left);
//
//     else if (p->key > q->key) {
//         if (q->right == nullptr) {
//             p->parent = q;
//             q->right = p;
//         }
//         else
//             insertHelper(key, p, q->right);
//     }
//     else 
//         delete(p);
// }
//
// template<class T>
// Node<T> *bst<T>::search(T key) {
//
//     Node<T> *p = root;
//     while (p->key != key)
//
//         if (key < p->key && p->left != nullptr)
//             p = p->left;
//         else if (key > p->key && p->right != nullptr)
//             p = p->right;
//         else if (p->key == key)
//             break;
//         else
//             return nullptr;
//     return p;
// }
//
// template<class T>
// void bst<T>::transplant(Node<T> *p, Node<T> *q) {
//     if (p->parent == nullptr)
//         root = q;
//     else if (p == p->parent->left)
//         p->parent->left = q;
//     else 
//         p->parent->right = q;
//
//     if (q != nullptr)
//         q->parent = p->parent;
// }
//
// template<class T>
// void bst<T>::remove(T key) {
//     Node<T> *p = search(key);
//
//     if (p == nullptr)
//         return;
//
//     if (p->left == nullptr) 
//         transplant(p, p->right);
//     else if (p->right == nullptr) 
//         transplant(p, p->left);
//     else {
//         Node<T> *q = p->right;
//         while (q->left != nullptr) 
//             q = q->left;
//
//         if (q->parent != p) {
//             transplant(q, q->right);
//             q->right = p->right;
//             if (q->right)
//                 q->right->parent = q;
//         }
//
//         transplant(p, q);
//         q->left = p->left;
//         if (q->left)
//             q->left->parent = q;
//     }
//
//     delete(p);
// }
//
// template<class T>
// void bst<T>::walkTree() {
//     walkTreeHelper(root);
// }
//
// template<class T>
// void bst<T>::walkTreeHelper(Node<T> *p) {
//     if (p != nullptr) {
//         walkTreeHelper(p->left);
//         std::cout << p->key << " ";
//         walkTreeHelper(p->right);
//     }
// }
//
// int main() {
//
//     bst<int> tree;
//
//     tree.insert(5);
//     tree.insert(1);
//     tree.insert(8);
//     tree.insert(4);
//     tree.insert(2);
//     tree.insert(9);
//     tree.insert(7);
//     //
//
//     tree.walkTree();
//     std::cout << '\n';
//     tree.remove(5);
//     tree.walkTree();
//     //
//     return 0;
// }
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class bst {
//
// public:
//     bst(Node<T> *r = nullptr) : root(r) {}
//     ~bst();
//     bool isEmpty();
//     void walkTree();
//     void walkTreeHelper(Node<T> *);
//     void insert(T);
//     void insertHelper(T, Node<T>*, Node<T>*);
//     void remove(T);
//     void removeHelper(T, Node<T>*, Node<T>*);
//     void transplant(Node<T> *, Node<T> *);
//     Node<T> *search(T);
// private:
//     Node<T> *root;
// };
//
// template<class T>
// bool bst<T>::isEmpty() {
//      return root == nullptr;
// }
//
// template<class T>
// bst<T>::~bst() {
// }
//
// template<class T>
// void bst<T>::insert(T key) {
//     Node<T> *newNode = new Node<T>(key);
//
//     if (isEmpty()) 
//         root = newNode;
//     else
//         insertHelper(key, newNode, root);
// }
//
// template<class T>
// void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
//
//     if (p->key < q->key) 
//         if (q->left == nullptr) {
//             p->parent = q;
//             q->left = p;
//         }
//         else 
//             insertHelper(key, p, q->left);
//
//     else if (p->key > q->key) {
//         if (q->right == nullptr) {
//             p->parent = q;
//             q->right = p;
//         }
//         else
//             insertHelper(key, p, q->right);
//     }
//     else 
//         delete(p);
// }
//
// template<class T>
// Node<T> *bst<T>::search(T key) {
//
//     Node<T> *p = root;
//     while (p->key != key)
//
//         if (key < p->key && p->left != nullptr)
//             p = p->left;
//         else if (key > p->key && p->right != nullptr)
//             p = p->right;
//         else if (p->key == key)
//             break;
//         else
//             return nullptr;
//     return p;
// }
//
// template<class T>
// void bst<T>::transplant(Node<T> *p, Node<T> *q) {
//     if (p->parent == nullptr)
//         root = q;
//     else if (p == p->parent->left)
//         p->parent->left = q;
//     else 
//         p->parent->right = q;
//
//     if (q != nullptr)
//         q->parent = p->parent;
// }
//
// template<class T>
// void bst<T>::remove(T key) {
//     Node<T> *p = search(key);
//
//     if (p == nullptr)
//         return;
//
//     if (p->left == nullptr) 
//         transplant(p, p->right);
//     else if (p->right == nullptr) 
//         transplant(p, p->left);
//     else {
//         Node<T> *q = p->right;
//         while (q->left != nullptr) 
//             q = q->left;
//
//         if (q->parent != p) {
//             transplant(q, q->right);
//             q->right = p->right;
//             if (q->right)
//                 q->right->parent = q;
//         }
//
//         transplant(p, q);
//         q->left = p->left;
//         if (q->left)
//             q->left->parent = q;
//     }
//
//     delete(p);
// }
//
// template<class T>
// void bst<T>::walkTree() {
//     walkTreeHelper(root);
// }
//
// template<class T>
// void bst<T>::walkTreeHelper(Node<T> *p) {
//     if (p != nullptr) {
//         walkTreeHelper(p->left);
//         std::cout << p->key << " ";
//         walkTreeHelper(p->right);
//     }
// }
//
// int main() {
//
//     bst<int> tree;
//
//     tree.insert(5);
//     tree.insert(1);
//     tree.insert(8);
//     tree.insert(4);
//     tree.insert(2);
//     tree.insert(9);
//     tree.insert(7);
//     //
//
//     tree.walkTree();
//     std::cout << '\n';
//     tree.remove(5);
//     tree.walkTree();
//     //
//     return 0;
// }
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class bst {
//
// public:
//     bst(Node<T> *r = nullptr) : root(r) {}
//     ~bst();
//     bool isEmpty();
//     void walkTree();
//     void walkTreeHelper(Node<T> *);
//     void insert(T);
//     void insertHelper(T, Node<T>*, Node<T>*);
//     void remove(T);
//     void removeHelper(T, Node<T>*, Node<T>*);
//     void transplant(Node<T> *, Node<T> *);
//     Node<T> *search(T);
// private:
//     Node<T> *root;
// };
//
// template<class T>
// bool bst<T>::isEmpty() {
//      return root == nullptr;
// }
//
// template<class T>
// bst<T>::~bst() {
// }
//
// template<class T>
// void bst<T>::insert(T key) {
//     Node<T> *newNode = new Node<T>(key);
//
//     if (isEmpty()) 
//         root = newNode;
//     else
//         insertHelper(key, newNode, root);
// }
//
// template<class T>
// void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
//
//     if (p->key < q->key) 
//         if (q->left == nullptr) {
//             p->parent = q;
//             q->left = p;
//         }
//         else 
//             insertHelper(key, p, q->left);
//
//     else if (p->key > q->key) {
//         if (q->right == nullptr) {
//             p->parent = q;
//             q->right = p;
//         }
//         else
//             insertHelper(key, p, q->right);
//     }
//     else 
//         delete(p);
// }
//
// template<class T>
// Node<T> *bst<T>::search(T key) {
//
//     Node<T> *p = root;
//     while (p->key != key)
//
//         if (key < p->key && p->left != nullptr)
//             p = p->left;
//         else if (key > p->key && p->right != nullptr)
//             p = p->right;
//         else if (p->key == key)
//             break;
//         else
//             return nullptr;
//     return p;
// }
//
// template<class T>
// void bst<T>::transplant(Node<T> *p, Node<T> *q) {
//     if (p->parent == nullptr)
//         root = q;
//     else if (p == p->parent->left)
//         p->parent->left = q;
//     else 
//         p->parent->right = q;
//
//     if (q != nullptr)
//         q->parent = p->parent;
// }
//
// template<class T>
// void bst<T>::remove(T key) {
//     Node<T> *p = search(key);
//
//     if (p == nullptr)
//         return;
//
//     if (p->left == nullptr) 
//         transplant(p, p->right);
//     else if (p->right == nullptr) 
//         transplant(p, p->left);
//     else {
//         Node<T> *q = p->right;
//         while (q->left != nullptr) 
//             q = q->left;
//
//         if (q->parent != p) {
//             transplant(q, q->right);
//             q->right = p->right;
//             if (q->right)
//                 q->right->parent = q;
//         }
//
//         transplant(p, q);
//         q->left = p->left;
//         if (q->left)
//             q->left->parent = q;
//     }
//
//     delete(p);
// }
//
// template<class T>
// void bst<T>::walkTree() {
//     walkTreeHelper(root);
// }
//
// template<class T>
// void bst<T>::walkTreeHelper(Node<T> *p) {
//     if (p != nullptr) {
//         walkTreeHelper(p->left);
//         std::cout << p->key << " ";
//         walkTreeHelper(p->right);
//     }
// }
//
// int main() {
//
//     bst<int> tree;
//
//     tree.insert(5);
//     tree.insert(1);
//     tree.insert(8);
//     tree.insert(4);
//     tree.insert(2);
//     tree.insert(9);
//     tree.insert(7);
//     //
//
//     tree.walkTree();
//     std::cout << '\n';
//     tree.remove(5);
//     tree.walkTree();
//     //
//     return 0;
// }
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class bst {
//
// public:
//     bst(Node<T> *r = nullptr) : root(r) {}
//     ~bst();
//     bool isEmpty();
//     void walkTree();
//     void walkTreeHelper(Node<T> *);
//     void insert(T);
//     void insertHelper(T, Node<T>*, Node<T>*);
//     void remove(T);
//     void removeHelper(T, Node<T>*, Node<T>*);
//     void transplant(Node<T> *, Node<T> *);
//     Node<T> *search(T);
// private:
//     Node<T> *root;
// };
//
// template<class T>
// bool bst<T>::isEmpty() {
//      return root == nullptr;
// }
//
// template<class T>
// bst<T>::~bst() {
// }
//
// template<class T>
// void bst<T>::insert(T key) {
//     Node<T> *newNode = new Node<T>(key);
//
//     if (isEmpty()) 
//         root = newNode;
//     else
//         insertHelper(key, newNode, root);
// }
//
// template<class T>
// void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
//
//     if (p->key < q->key) 
//         if (q->left == nullptr) {
//             p->parent = q;
//             q->left = p;
//         }
//         else 
//             insertHelper(key, p, q->left);
//
//     else if (p->key > q->key) {
//         if (q->right == nullptr) {
//             p->parent = q;
//             q->right = p;
//         }
//         else
//             insertHelper(key, p, q->right);
//     }
//     else 
//         delete(p);
// }
//
// template<class T>
// Node<T> *bst<T>::search(T key) {
//
//     Node<T> *p = root;
//     while (p->key != key)
//
//         if (key < p->key && p->left != nullptr)
//             p = p->left;
//         else if (key > p->key && p->right != nullptr)
//             p = p->right;
//         else if (p->key == key)
//             break;
//         else
//             return nullptr;
//     return p;
// }
//
// template<class T>
// void bst<T>::transplant(Node<T> *p, Node<T> *q) {
//     if (p->parent == nullptr)
//         root = q;
//     else if (p == p->parent->left)
//         p->parent->left = q;
//     else 
//         p->parent->right = q;
//
//     if (q != nullptr)
//         q->parent = p->parent;
// }
//
// template<class T>
// void bst<T>::remove(T key) {
//     Node<T> *p = search(key);
//
//     if (p == nullptr)
//         return;
//
//     if (p->left == nullptr) 
//         transplant(p, p->right);
//     else if (p->right == nullptr) 
//         transplant(p, p->left);
//     else {
//         Node<T> *q = p->right;
//         while (q->left != nullptr) 
//             q = q->left;
//
//         if (q->parent != p) {
//             transplant(q, q->right);
//             q->right = p->right;
//             if (q->right)
//                 q->right->parent = q;
//         }
//
//         transplant(p, q);
//         q->left = p->left;
//         if (q->left)
//             q->left->parent = q;
//     }
//
//     delete(p);
// }
//
// template<class T>
// void bst<T>::walkTree() {
//     walkTreeHelper(root);
// }
//
// template<class T>
// void bst<T>::walkTreeHelper(Node<T> *p) {
//     if (p != nullptr) {
//         walkTreeHelper(p->left);
//         std::cout << p->key << " ";
//         walkTreeHelper(p->right);
//     }
// }
//
// int main() {
//
//     bst<int> tree;
//
//     tree.insert(5);
//     tree.insert(1);
//     tree.insert(8);
//     tree.insert(4);
//     tree.insert(2);
//     tree.insert(9);
//     tree.insert(7);
//     //
//
//     tree.walkTree();
//     std::cout << '\n';
//     tree.remove(5);
//     tree.walkTree();
//     //
//     return 0;
// }
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class bst {
//
// public:
//     bst(Node<T> *r = nullptr) : root(r) {}
//     ~bst();
//     bool isEmpty();
//     void walkTree();
//     void walkTreeHelper(Node<T> *);
//     void insert(T);
//     void insertHelper(T, Node<T>*, Node<T>*);
//     void remove(T);
//     void removeHelper(T, Node<T>*, Node<T>*);
//     void transplant(Node<T> *, Node<T> *);
//     Node<T> *search(T);
// private:
//     Node<T> *root;
// };
//
// template<class T>
// bool bst<T>::isEmpty() {
//      return root == nullptr;
// }
//
// template<class T>
// bst<T>::~bst() {
// }
//
// template<class T>
// void bst<T>::insert(T key) {
//     Node<T> *newNode = new Node<T>(key);
//
//     if (isEmpty()) 
//         root = newNode;
//     else
//         insertHelper(key, newNode, root);
// }
//
// template<class T>
// void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
//
//     if (p->key < q->key) 
//         if (q->left == nullptr) {
//             p->parent = q;
//             q->left = p;
//         }
//         else 
//             insertHelper(key, p, q->left);
//
//     else if (p->key > q->key) {
//         if (q->right == nullptr) {
//             p->parent = q;
//             q->right = p;
//         }
//         else
//             insertHelper(key, p, q->right);
//     }
//     else 
//         delete(p);
// }
//
// template<class T>
// Node<T> *bst<T>::search(T key) {
//
//     Node<T> *p = root;
//     while (p->key != key)
//
//         if (key < p->key && p->left != nullptr)
//             p = p->left;
//         else if (key > p->key && p->right != nullptr)
//             p = p->right;
//         else if (p->key == key)
//             break;
//         else
//             return nullptr;
//     return p;
// }
//
// template<class T>
// void bst<T>::transplant(Node<T> *p, Node<T> *q) {
//     if (p->parent == nullptr)
//         root = q;
//     else if (p == p->parent->left)
//         p->parent->left = q;
//     else 
//         p->parent->right = q;
//
//     if (q != nullptr)
//         q->parent = p->parent;
// }
//
// template<class T>
// void bst<T>::remove(T key) {
//     Node<T> *p = search(key);
//
//     if (p == nullptr)
//         return;
//
//     if (p->left == nullptr) 
//         transplant(p, p->right);
//     else if (p->right == nullptr) 
//         transplant(p, p->left);
//     else {
//         Node<T> *q = p->right;
//         while (q->left != nullptr) 
//             q = q->left;
//
//         if (q->parent != p) {
//             transplant(q, q->right);
//             q->right = p->right;
//             if (q->right)
//                 q->right->parent = q;
//         }
//
//         transplant(p, q);
//         q->left = p->left;
//         if (q->left)
//             q->left->parent = q;
//     }
//
//     delete(p);
// }
//
// template<class T>
// void bst<T>::walkTree() {
//     walkTreeHelper(root);
// }
//
// template<class T>
// void bst<T>::walkTreeHelper(Node<T> *p) {
//     if (p != nullptr) {
//         walkTreeHelper(p->left);
//         std::cout << p->key << " ";
//         walkTreeHelper(p->right);
//     }
// }
//
// int main() {
//
//     bst<int> tree;
//
//     tree.insert(5);
//     tree.insert(1);
//     tree.insert(8);
//     tree.insert(4);
//     tree.insert(2);
//     tree.insert(9);
//     tree.insert(7);
//     //
//
//     tree.walkTree();
//     std::cout << '\n';
//     tree.remove(5);
//     tree.walkTree();
//     //
//     return 0;
// }
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class bst {
//
// public:
//     bst(Node<T> *r = nullptr) : root(r) {}
//     ~bst();
//     bool isEmpty();
//     void walkTree();
//     void walkTreeHelper(Node<T> *);
//     void insert(T);
//     void insertHelper(T, Node<T>*, Node<T>*);
//     void remove(T);
//     void removeHelper(T, Node<T>*, Node<T>*);
//     void transplant(Node<T> *, Node<T> *);
//     Node<T> *search(T);
// private:
//     Node<T> *root;
// };
//
// template<class T>
// bool bst<T>::isEmpty() {
//      return root == nullptr;
// }
//
// template<class T>
// bst<T>::~bst() {
// }
//
// template<class T>
// void bst<T>::insert(T key) {
//     Node<T> *newNode = new Node<T>(key);
//
//     if (isEmpty()) 
//         root = newNode;
//     else
//         insertHelper(key, newNode, root);
// }
//
// template<class T>
// void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
//
//     if (p->key < q->key) 
//         if (q->left == nullptr) {
//             p->parent = q;
//             q->left = p;
//         }
//         else 
//             insertHelper(key, p, q->left);
//
//     else if (p->key > q->key) {
//         if (q->right == nullptr) {
//             p->parent = q;
//             q->right = p;
//         }
//         else
//             insertHelper(key, p, q->right);
//     }
//     else 
//         delete(p);
// }
//
// template<class T>
// Node<T> *bst<T>::search(T key) {
//
//     Node<T> *p = root;
//     while (p->key != key)
//
//         if (key < p->key && p->left != nullptr)
//             p = p->left;
//         else if (key > p->key && p->right != nullptr)
//             p = p->right;
//         else if (p->key == key)
//             break;
//         else
//             return nullptr;
//     return p;
// }
//
// template<class T>
// void bst<T>::transplant(Node<T> *p, Node<T> *q) {
//     if (p->parent == nullptr)
//         root = q;
//     else if (p == p->parent->left)
//         p->parent->left = q;
//     else 
//         p->parent->right = q;
//
//     if (q != nullptr)
//         q->parent = p->parent;
// }
//
// template<class T>
// void bst<T>::remove(T key) {
//     Node<T> *p = search(key);
//
//     if (p == nullptr)
//         return;
//
//     if (p->left == nullptr) 
//         transplant(p, p->right);
//     else if (p->right == nullptr) 
//         transplant(p, p->left);
//     else {
//         Node<T> *q = p->right;
//         while (q->left != nullptr) 
//             q = q->left;
//
//         if (q->parent != p) {
//             transplant(q, q->right);
//             q->right = p->right;
//             if (q->right)
//                 q->right->parent = q;
//         }
//
//         transplant(p, q);
//         q->left = p->left;
//         if (q->left)
//             q->left->parent = q;
//     }
//
//     delete(p);
// }
//
// template<class T>
// void bst<T>::walkTree() {
//     walkTreeHelper(root);
// }
//
// template<class T>
// void bst<T>::walkTreeHelper(Node<T> *p) {
//     if (p != nullptr) {
//         walkTreeHelper(p->left);
//         std::cout << p->key << " ";
//         walkTreeHelper(p->right);
//     }
// }
//
// int main() {
//
//     bst<int> tree;
//
//     tree.insert(5);
//     tree.insert(1);
//     tree.insert(8);
//     tree.insert(4);
//     tree.insert(2);
//     tree.insert(9);
//     tree.insert(7);
//     //
//
//     tree.walkTree();
//     std::cout << '\n';
//     tree.remove(5);
//     tree.walkTree();
//     //
//     return 0;
// }
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class bst {
//
// public:
//     bst(Node<T> *r = nullptr) : root(r) {}
//     ~bst();
//     bool isEmpty();
//     void walkTree();
//     void walkTreeHelper(Node<T> *);
//     void insert(T);
//     void insertHelper(T, Node<T>*, Node<T>*);
//     void remove(T);
//     void removeHelper(T, Node<T>*, Node<T>*);
//     void transplant(Node<T> *, Node<T> *);
//     Node<T> *search(T);
// private:
//     Node<T> *root;
// };
//
// template<class T>
// bool bst<T>::isEmpty() {
//      return root == nullptr;
// }
//
// template<class T>
// bst<T>::~bst() {
// }
//
// template<class T>
// void bst<T>::insert(T key) {
//     Node<T> *newNode = new Node<T>(key);
//
//     if (isEmpty()) 
//         root = newNode;
//     else
//         insertHelper(key, newNode, root);
// }
//
// template<class T>
// void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
//
//     if (p->key < q->key) 
//         if (q->left == nullptr) {
//             p->parent = q;
//             q->left = p;
//         }
//         else 
//             insertHelper(key, p, q->left);
//
//     else if (p->key > q->key) {
//         if (q->right == nullptr) {
//             p->parent = q;
//             q->right = p;
//         }
//         else
//             insertHelper(key, p, q->right);
//     }
//     else 
//         delete(p);
// }
//
// template<class T>
// Node<T> *bst<T>::search(T key) {
//
//     Node<T> *p = root;
//     while (p->key != key)
//
//         if (key < p->key && p->left != nullptr)
//             p = p->left;
//         else if (key > p->key && p->right != nullptr)
//             p = p->right;
//         else if (p->key == key)
//             break;
//         else
//             return nullptr;
//     return p;
// }
//
// template<class T>
// void bst<T>::transplant(Node<T> *p, Node<T> *q) {
//     if (p->parent == nullptr)
//         root = q;
//     else if (p == p->parent->left)
//         p->parent->left = q;
//     else 
//         p->parent->right = q;
//
//     if (q != nullptr)
//         q->parent = p->parent;
// }
//
// template<class T>
// void bst<T>::remove(T key) {
//     Node<T> *p = search(key);
//
//     if (p == nullptr)
//         return;
//
//     if (p->left == nullptr) 
//         transplant(p, p->right);
//     else if (p->right == nullptr) 
//         transplant(p, p->left);
//     else {
//         Node<T> *q = p->right;
//         while (q->left != nullptr) 
//             q = q->left;
//
//         if (q->parent != p) {
//             transplant(q, q->right);
//             q->right = p->right;
//             if (q->right)
//                 q->right->parent = q;
//         }
//
//         transplant(p, q);
//         q->left = p->left;
//         if (q->left)
//             q->left->parent = q;
//     }
//
//     delete(p);
// }
//
// template<class T>
// void bst<T>::walkTree() {
//     walkTreeHelper(root);
// }
//
// template<class T>
// void bst<T>::walkTreeHelper(Node<T> *p) {
//     if (p != nullptr) {
//         walkTreeHelper(p->left);
//         std::cout << p->key << " ";
//         walkTreeHelper(p->right);
//     }
// }
//
// int main() {
//
//     bst<int> tree;
//
//     tree.insert(5);
//     tree.insert(1);
//     tree.insert(8);
//     tree.insert(4);
//     tree.insert(2);
//     tree.insert(9);
//     tree.insert(7);
//     //
//
//     tree.walkTree();
//     std::cout << '\n';
//     tree.remove(5);
//     tree.walkTree();
//     //
//     return 0;
// }
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class bst {
//
// public:
//     bst(Node<T> *r = nullptr) : root(r) {}
//     ~bst();
//     bool isEmpty();
//     void walkTree();
//     void walkTreeHelper(Node<T> *);
//     void insert(T);
//     void insertHelper(T, Node<T>*, Node<T>*);
//     void remove(T);
//     void removeHelper(T, Node<T>*, Node<T>*);
//     void transplant(Node<T> *, Node<T> *);
//     Node<T> *search(T);
// private:
//     Node<T> *root;
// };
//
// template<class T>
// bool bst<T>::isEmpty() {
//      return root == nullptr;
// }
//
// template<class T>
// bst<T>::~bst() {
// }
//
// template<class T>
// void bst<T>::insert(T key) {
//     Node<T> *newNode = new Node<T>(key);
//
//     if (isEmpty()) 
//         root = newNode;
//     else
//         insertHelper(key, newNode, root);
// }
//
// template<class T>
// void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
//
//     if (p->key < q->key) 
//         if (q->left == nullptr) {
//             p->parent = q;
//             q->left = p;
//         }
//         else 
//             insertHelper(key, p, q->left);
//
//     else if (p->key > q->key) {
//         if (q->right == nullptr) {
//             p->parent = q;
//             q->right = p;
//         }
//         else
//             insertHelper(key, p, q->right);
//     }
//     else 
//         delete(p);
// }
//
// template<class T>
// Node<T> *bst<T>::search(T key) {
//
//     Node<T> *p = root;
//     while (p->key != key)
//
//         if (key < p->key && p->left != nullptr)
//             p = p->left;
//         else if (key > p->key && p->right != nullptr)
//             p = p->right;
//         else if (p->key == key)
//             break;
//         else
//             return nullptr;
//     return p;
// }
//
// template<class T>
// void bst<T>::transplant(Node<T> *p, Node<T> *q) {
//     if (p->parent == nullptr)
//         root = q;
//     else if (p == p->parent->left)
//         p->parent->left = q;
//     else 
//         p->parent->right = q;
//
//     if (q != nullptr)
//         q->parent = p->parent;
// }
//
// template<class T>
// void bst<T>::remove(T key) {
//     Node<T> *p = search(key);
//
//     if (p == nullptr)
//         return;
//
//     if (p->left == nullptr) 
//         transplant(p, p->right);
//     else if (p->right == nullptr) 
//         transplant(p, p->left);
//     else {
//         Node<T> *q = p->right;
//         while (q->left != nullptr) 
//             q = q->left;
//
//         if (q->parent != p) {
//             transplant(q, q->right);
//             q->right = p->right;
//             if (q->right)
//                 q->right->parent = q;
//         }
//
//         transplant(p, q);
//         q->left = p->left;
//         if (q->left)
//             q->left->parent = q;
//     }
//
//     delete(p);
// }
//
// template<class T>
// void bst<T>::walkTree() {
//     walkTreeHelper(root);
// }
//
// template<class T>
// void bst<T>::walkTreeHelper(Node<T> *p) {
//     if (p != nullptr) {
//         walkTreeHelper(p->left);
//         std::cout << p->key << " ";
//         walkTreeHelper(p->right);
//     }
// }
//
// int main() {
//
//     bst<int> tree;
//
//     tree.insert(5);
//     tree.insert(1);
//     tree.insert(8);
//     tree.insert(4);
//     tree.insert(2);
//     tree.insert(9);
//     tree.insert(7);
//     //
//
//     tree.walkTree();
//     std::cout << '\n';
//     tree.remove(5);
//     tree.walkTree();
//     //
//     return 0;
// }
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class bst {
//
// public:
//     bst(Node<T> *r = nullptr) : root(r) {}
//     ~bst();
//     bool isEmpty();
//     void walkTree();
//     void walkTreeHelper(Node<T> *);
//     void insert(T);
//     void insertHelper(T, Node<T>*, Node<T>*);
//     void remove(T);
//     void removeHelper(T, Node<T>*, Node<T>*);
//     void transplant(Node<T> *, Node<T> *);
//     Node<T> *search(T);
// private:
//     Node<T> *root;
// };
//
// template<class T>
// bool bst<T>::isEmpty() {
//      return root == nullptr;
// }
//
// template<class T>
// bst<T>::~bst() {
// }
//
// template<class T>
// void bst<T>::insert(T key) {
//     Node<T> *newNode = new Node<T>(key);
//
//     if (isEmpty()) 
//         root = newNode;
//     else
//         insertHelper(key, newNode, root);
// }
//
// template<class T>
// void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
//
//     if (p->key < q->key) 
//         if (q->left == nullptr) {
//             p->parent = q;
//             q->left = p;
//         }
//         else 
//             insertHelper(key, p, q->left);
//
//     else if (p->key > q->key) {
//         if (q->right == nullptr) {
//             p->parent = q;
//             q->right = p;
//         }
//         else
//             insertHelper(key, p, q->right);
//     }
//     else 
//         delete(p);
// }
//
// template<class T>
// Node<T> *bst<T>::search(T key) {
//
//     Node<T> *p = root;
//     while (p->key != key)
//
//         if (key < p->key && p->left != nullptr)
//             p = p->left;
//         else if (key > p->key && p->right != nullptr)
//             p = p->right;
//         else if (p->key == key)
//             break;
//         else
//             return nullptr;
//     return p;
// }
//
// template<class T>
// void bst<T>::transplant(Node<T> *p, Node<T> *q) {
//     if (p->parent == nullptr)
//         root = q;
//     else if (p == p->parent->left)
//         p->parent->left = q;
//     else 
//         p->parent->right = q;
//
//     if (q != nullptr)
//         q->parent = p->parent;
// }
//
// template<class T>
// void bst<T>::remove(T key) {
//     Node<T> *p = search(key);
//
//     if (p == nullptr)
//         return;
//
//     if (p->left == nullptr) 
//         transplant(p, p->right);
//     else if (p->right == nullptr) 
//         transplant(p, p->left);
//     else {
//         Node<T> *q = p->right;
//         while (q->left != nullptr) 
//             q = q->left;
//
//         if (q->parent != p) {
//             transplant(q, q->right);
//             q->right = p->right;
//             if (q->right)
//                 q->right->parent = q;
//         }
//
//         transplant(p, q);
//         q->left = p->left;
//         if (q->left)
//             q->left->parent = q;
//     }
//
//     delete(p);
// }
//
// template<class T>
// void bst<T>::walkTree() {
//     walkTreeHelper(root);
// }
//
// template<class T>
// void bst<T>::walkTreeHelper(Node<T> *p) {
//     if (p != nullptr) {
//         walkTreeHelper(p->left);
//         std::cout << p->key << " ";
//         walkTreeHelper(p->right);
//     }
// }
//
// int main() {
//
//     bst<int> tree;
//
//     tree.insert(5);
//     tree.insert(1);
//     tree.insert(8);
//     tree.insert(4);
//     tree.insert(2);
//     tree.insert(9);
//     tree.insert(7);
//     //
//
//     tree.walkTree();
//     std::cout << '\n';
//     tree.remove(5);
//     tree.walkTree();
//     //
//     return 0;
// }
// #include <iostream>
// #include "node.h"
//
// template<class T>
// class bst {
//
// public:
//     bst(Node<T> *r = nullptr) : root(r) {}
//     ~bst();
//     bool isEmpty();
//     void walkTree();
//     void walkTreeHelper(Node<T> *);
//     void insert(T);
//     void insertHelper(T, Node<T>*, Node<T>*);
//     void remove(T);
//     void removeHelper(T, Node<T>*, Node<T>*);
//     void transplant(Node<T> *, Node<T> *);
//     Node<T> *search(T);
// private:
//     Node<T> *root;
// };
//
// template<class T>
// bool bst<T>::isEmpty() {
//      return root == nullptr;
// }
//
// template<class T>
// bst<T>::~bst() {
// }
//
// template<class T>
// void bst<T>::insert(T key) {
//     Node<T> *newNode = new Node<T>(key);
//
//     if (isEmpty()) 
//         root = newNode;
//     else
//         insertHelper(key, newNode, root);
// }
//
// template<class T>
// void bst<T>::insertHelper(T key, Node<T> *p, Node<T> *q) {
//
//     if (p->key < q->key) 
//         if (q->left == nullptr) {
//             p->parent = q;
//             q->left = p;
//         }
//         else 
//             insertHelper(key, p, q->left);
//
//     else if (p->key > q->key) {
//         if (q->right == nullptr) {
//             p->parent = q;
//             q->right = p;
//         }
//         else
//             insertHelper(key, p, q->right);
//     }
//     else 
//         delete(p);
// }
//
// template<class T>
// Node<T> *bst<T>::search(T key) {
//
//     Node<T> *p = root;
//     while (p->key != key)
//
//         if (key < p->key && p->left != nullptr)
//             p = p->left;
//         else if (key > p->key && p->right != nullptr)
//             p = p->right;
//         else if (p->key == key)
//             break;
//         else
//             return nullptr;
//     return p;
// }
//
// template<class T>
// void bst<T>::transplant(Node<T> *p, Node<T> *q) {
//     if (p->parent == nullptr)
//         root = q;
//     else if (p == p->parent->left)
//         p->parent->left = q;
//     else 
//         p->parent->right = q;
//
//     if (q != nullptr)
//         q->parent = p->parent;
// }
//
// template<class T>
// void bst<T>::remove(T key) {
//     Node<T> *p = search(key);
//
//     if (p == nullptr)
//         return;
//
//     if (p->left == nullptr) 
//         transplant(p, p->right);
//     else if (p->right == nullptr) 
//         transplant(p, p->left);
//     else {
//         Node<T> *q = p->right;
//         while (q->left != nullptr) 
//             q = q->left;
//
//         if (q->parent != p) {
//             transplant(q, q->right);
//             q->right = p->right;
//             if (q->right)
//                 q->right->parent = q;
//         }
//
//         transplant(p, q);
//         q->left = p->left;
//         if (q->left)
//             q->left->parent = q;
//     }
//
//     delete(p);
// }
//
// template<class T>
// void bst<T>::walkTree() {
//     walkTreeHelper(root);
// }
//
// template<class T>
// void bst<T>::walkTreeHelper(Node<T> *p) {
//     if (p != nullptr) {
//         walkTreeHelper(p->left);
//         std::cout << p->key << " ";
//         walkTreeHelper(p->right);
//     }
// }
//
// int main() {
//
//     bst<int> tree;
//
//     tree.insert(5);
//     tree.insert(1);
//     tree.insert(8);
//     tree.insert(4);
//     tree.insert(2);
//     tree.insert(9);
//     tree.insert(7);
//     //
//
//     tree.walkTree();
//     std::cout << '\n';
//     tree.remove(5);
//     tree.walkTree();
//     //
//     return 0;
// }
