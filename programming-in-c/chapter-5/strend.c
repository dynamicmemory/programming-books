#include <stdio.h>
#include <string.h>

int strend(char *x, char *y) {
    
    char *s = x;
    char *t = y;
    int len = strlen(t);

    while (*s++ != '\0')
        printf("s: %c t: %c\n", *s, *t);
        
    while (*t++ != '\0')
        printf("s: %c t: %c\n", *s, *t);

    for (int i = len; i != 0; --i) 
        if (*s-- != *t--)
            printf("s: %c t: %c\n", *s, *t);
            return 0;
    return 1;
}

int main() {

    char *a = "hello there little one";
    char *b = "one";

    printf("Expected: 1 \nReturned: %d \n\n", strend(a, b));

    char *f = "hello there little one";
    char *g = "r one";
    printf("Expected: 0 \nReturned: %d\n\n", strend(f, g));

    return 0;
}
