#include <stdio.h>

void pstrcat(char *s, char *t) {

    while (*s++ != '\0')
        ;

    *s--;

    while ((*s++ = *t++) != '\0')
        ;
}

int main(int argc, char **argv) {
    
    char a[30] = "abcdefghijklmnop";
    char *b = "qrstuvwxyz";

    pstrcat(a, b);
    printf("%s \n", a);
    return 0;
}
