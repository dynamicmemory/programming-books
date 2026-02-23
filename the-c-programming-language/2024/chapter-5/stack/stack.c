#include <stdio.h>
#define ALLOCSIZE 10000 

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
static char *top = NULL;

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    else 
        return NULL;
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

void push_int(int n) {
    int *stack = (int *) alloc(sizeof(int));
    if (stack != NULL)
        *stack = n;
    top = (char *) stack;
}

void pop() {
    char *temp = top; 
    afree(top);
    top = temp - sizeof(int);
}

int main() {

    for (int i = 0; i < 10; i++)
        push_int(i);

    printf("%d \n", *top);
    pop();
    printf("%d \n", *top);

    return 0;
} 
