#include <stdio.h>

// Getting the segfault cuz s isnt big enough to hold t aswell.
void mystrcat(char *s, char *t) {
    
    int i;

    for(i = 0; *s++ != '\0'; i++)
        printf("%c \n", *s);

    *s--;
    printf("%c \n", *s);


    while (*s++ = *t++) {
        printf("%c \n", *s);
        i++;
    }

    while (i > 0) {
        printf("%c \n", *s);
        *--s;
        i--;
    }
}

int main() {

    char *a = "abcdefg";
    char *b = "hijklmn";

    mystrcat(a, b);
    printf("%s \n", a);
        
    return 0;
}

