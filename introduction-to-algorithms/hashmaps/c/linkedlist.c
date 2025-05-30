#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "node.h"

typedef struct LinkedList {
    Node *head;
    Node *tail; // probably wont use this
} LinkedList;

void init_list(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
}

bool is_empty(LinkedList *list) {
    return list->head == NULL;
}

Node *list_search(LinkedList *list, int key) {
    Node *p = list->head;

    if (p == NULL)
        return NULL;

    while (p != NULL && p->key != key)
        p = p->next;
    
    return p;
}

void list_insert(LinkedList *list, int key){
    Node *p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->next = NULL;
    p->prev = NULL;

    if (list->head == NULL)
        list->head = p;
    else {
        list->head->prev = p;
        p->next = list->head;
        list->head = p;
    }
}

void list_delete(LinkedList *list, int key) {
    Node *p = list_search(list, key);

    if (p == NULL)
        return;

    if (p == list->head) {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    else {
        if (p->next != NULL)
            p->next->prev = p->prev;
        if (p->prev != NULL)
            p->prev->next = p->next;
    }
    free(p);
}

void list_print(LinkedList *list) {
    Node *p = list->head;
    while (p != NULL) {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}
