#include <vector>

template<class T>
class Node {

public:
    Node(): isleaf(true){}
    
    std::vector<T> keys;
    std::vector<Node*> children;
    bool isleaf;
};
