#include <iostream>
#include <string>
#include <vector>
using std::vector; using std::string;

int main(void) {
    
    vector<int> ivec;
    vector<int> ivec2 = {1,23,4};
    vector<int> zeros(10, 0);     // 0,0,0,0,0,0,0
    vector<string> words = {10, "hi"}; // hi,hi,hi,hi,hi,hi,hi,hi,hi

    for (int i = 0; i < 100; i++)
        ivec.push_back(i);
     
    bool isEmpty = words.empty();
    int len = (int)words.size();
    


    return 0;
}
