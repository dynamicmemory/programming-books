template<class T>
class Node {
public:
    Node(): next(nullptr), key() {}
    Node(T k): next(nullptr), key(k) {}
    
    Node<T> *next;
    T key;
};


