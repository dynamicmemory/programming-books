#include "hashmap.c"

int main () {

    hashmap map;
    init_hashmap(&map);

    insert(&map, 69);
    print(&map);
    
    system("clear");

    insert(&map, 420);
    for (int i = 0; i < 100; i++)
        insert(&map, rand());

    print(&map);
    return 0;

}
