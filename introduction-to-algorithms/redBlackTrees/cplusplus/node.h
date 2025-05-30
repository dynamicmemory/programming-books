enum Colour {RED, BLACK};

template<class T>
class Node {

public:
    Node(T k = T()) : key(k), parent(nullptr), left(nullptr), 
                      right(nullptr), colour(RED) {}

    T key;
    Node<T> *parent;
    Node<T> *left;
    Node<T> *right;
    Colour colour;
};
