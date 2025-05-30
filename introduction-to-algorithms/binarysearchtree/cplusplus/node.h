template<class T>
class Node {
public:
    Node(): key(), parent(nullptr), left(nullptr), right(nullptr) {}
    explicit Node(T k) : key(k), parent(nullptr), left(nullptr), right(nullptr) {}

    T key;
    Node<T> *parent;
    Node<T> *left;
    Node<T> *right;
};
