#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"

typedef struct stack {
    Node *head;
} stack;

void init_stack(stack *s){
    s->head = NULL;
}

bool isempty(stack *s) {
    return s->head == NULL;
}

void push(stack *s, int k) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->key = k;
    p->next = s->head;
    s->head = p;
}

void pop(stack *s) {
    if (s->head == NULL)
        // free(s->head);
        ;
    else {
        Node *p = s->head;
        s->head = s->head->next;
        free(p);
    }
}

int top(stack *s) {
    if (isempty(s))
        return -1;
    else 
        return s->head->key;
}

void delete(stack *s) {
    while (!isempty(s))
        pop(s);
}

void printstack(stack *s) {
    Node *p = s->head;

    while (p != NULL) {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}

int main() {

    stack s;
    init_stack(&s);
    push(&s, 69);
    push(&s, 98);

    printstack(&s);
    pop(&s);
    
    pop(&s);
    printstack(&s);
    push(&s, 420);
    push(&s, 1);
    push(&s, 4);
    push(&s, 0);
    push(&s, 3);
    push(&s, 69);
    push(&s, 40);
    push(&s, 32);
    push(&s, 411);
    push(&s, 55);
    printstack(&s);

    delete(&s);
    printstack(&s);

    return 0;
}
