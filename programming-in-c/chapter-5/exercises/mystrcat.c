#include <stdio.h>

void mystrcat(char *s, char *t) {
    char *p = s;
    while(*p) p++;
    while((*p++ = *t++));
}

int main() {

    char a[1000] = "abcdefg";
    char *b = "hijklmn";

    mystrcat(a, b);
    printf("%s \n", a);
        
    return 0;
}

