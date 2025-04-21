#include <stdio.h>

int mystrlen(char *s) {
    char *p = s;
    while (*p++);
    return p - s - 1;
}

char *mystrncpy(char *s, const char *t, int n) {
    char *p = s;
    const char *q = t;

    while (n > 0) {
        if (*q == '\0')
            *p++ = '\0';
        else 
            *p++ = *q++;
        n--;
    }
    return s;
}

char *mystrncat(char *s, const char *t, int n) {
    char *p = s + mystrlen(s);
    const char *q = t;
    
    while (*q != '\0' && n > 0) {
        *p++ = *q++;
        n--;
    }
    *p = '\0';
    return s;
}

int mystrncmp(const char *s, const char *t, int n) {
    const char *p = s;
    const char *q = t;
    int i;

    while (n > 0) {
        // cant do this wiff ponters brah
        i += *p++ - *q++;
        n--; 
    }

    return i;
}

int main() {

    char a[10000] = "abcde";
    char *b = "fghij";
    char c[100];


    printf("%s \n", c);
    mystrncpy(c, b, 10);
    printf("%s \n", c);

    printf("%s \n", a);
    mystrncat(a, b, 1);
    printf("%s \n", a);

    printf("Should be <0, :%d \n", mystrncmp(a, b, 4));
    printf("Should = 0%d \n", mystrncmp(c, b, 4));
    printf("Should be >0 %d \n", mystrncmp(b, a, 4));

    return 0;
}
