template<class T>
class Node {

public:
    Node(): key(), prev(nullptr), next(nullptr) {}
    Node(T k): key(k), prev(nullptr), next(nullptr) {}
    
    Node<T>* prev; 
    Node<T>* next;
    T key;
};


