#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* string;

string s(char *sp) {
    size_t len = strlen(sp);
    char *temp = malloc(len + 1);
    for (int i=0; i<len ;i++) 
        temp[i] = sp[i];
    temp[len] = '\0';
    return temp;
}

int main(void) {
    string s1 = s("Hello strings in C"); 
    printf("%s\n", s1);

    return 0;
}
