#include <stdio.h>
#include <stdint.h>
#include <string.h>

void itoa(int8_t, char *);
void reverse(char *); 

int main(void) {
    char s[100];
    itoa(-128, s);
    printf("%s\n", s);
    return 0;
}


void itoa(int8_t n, char *s) {
    int i, sign;
    if ((sign = n) < 0) 
        n = -n;

    i = 0;

    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

void reverse(char *s) {
    int len = strlen(s);
    char p[len];
    int i, j;
    for (i=len-1, j=0; i>=0; --i, ++j) {
        p[j] = s[i];
    }

    p[j] = '\n';
    p[++j] = '\0';

    for (int i=0; i<=len; ++i) 
        s[i] = p[i];
}
