template<class T>
class Node {

public:
    Node() : key(), next(nullptr), prev(nullptr) {}
    Node(T k) : key(k), next(nullptr), prev(nullptr) {}

    T key;
    Node<T>* next;
    Node<T>* prev;
};
