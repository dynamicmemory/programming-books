#include <stdio.h>

int mystrlen(char *s) { 
    int n;

    for (n = 0; *s != '\0'; s++)
      n++;
    return n;
}

int mystrlen2(char *s) {
    char *copy = s;
    while(*copy) copy++;
    return copy - s;
}

int mystrlen3(char *s) {
    int n = 0;
    char *p = s;
    while(*p++) n++;
    return n;
}

int mystrlen4(char *s) {
    char *copy = s;
    while(*copy++);
    return copy - s - 1;
}


int main() {

    char *word = "hello";

    printf("%d \n", mystrlen(word));
    printf("%d \n", mystrlen2(word));
    printf("%d \n", mystrlen3(word));
    printf("%d \n", mystrlen4(word));
    return 0;

}
