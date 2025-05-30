#include "linkedlist.c"

#define LENGTH 47

typedef struct hashmap {
    LinkedList list[LENGTH];
} hashmap;

void init_hashmap(hashmap *map) {
   for (int i = 0; i < LENGTH; i++)
        init_list(&map->list[i]);
}

int hash(int key) {
    return key % LENGTH;
}

bool contains(hashmap *map, int key) {
    int index = hash(key);
    return list_search(&map->list[index], key) != NULL;
}

void insert(hashmap *map, int key) {
    int index = hash(key);
    if (!contains(map, key))
        list_insert(&map->list[index], key);
}

void delete(hashmap *map, int key) {
    int index = hash(key);
    if (!contains(map, key))
        list_delete(&map->list[index], key);
}

void print(hashmap *map) {
    for (int i = 0; i < LENGTH; i++) {
        printf("Bucket %d = ", i);
        list_print(&map->list[i]);
    }
}


