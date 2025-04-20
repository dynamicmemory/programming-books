#include <stdio.h>

int mystrlen(char *s) {
    char *p = s;
    while(*p++);
    return *p - *s - 1;
}

int mystrend(char *s, char*t) {
    int tlen = mystrlen(t);
    char *p = s;
    char *q = t;
    
    while(*p) p++;
    while(*q) q++;

    for(int i = tlen; i > 0; i--)
        if (*p-- != *q--)
            return 0;

    return 1;
}

int main() {

    char *a1 = "hopewell";
    char *a2 = "hopeless";
    char *a3 = "the";
    char *b = "well";

    printf("answer: 1, result: %d\n", mystrend(a1, b));
    printf("answer: 0, result: %d\n", mystrend(a2, b));
    printf("answer: 0, result: %d\n", mystrend(a3, b));

    return 0;
}
