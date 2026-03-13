#include <stdio.h>
#include <stdint.h>
#include <string.h>

void itoa(int8_t, char *, int);
void itob(int32_t, char *, int);
uint64_t htoi(const char *);
void reverse(char *); 

int main(void) {
    char s[100];
    // itoa(127, s, 4);
    itob(160, s, 16);
    printf("%s\n", s);
    return 0;
}


void itoa(int8_t n, char *s, int b) {
    int i, sign;
    if ((sign = n) > 0) { 
        n = -n;
        printf("%d\n",n);
    }

    i = 0;

    do {

        s[i++] = -n % 10 + '0';
        printf("%s\n",s);
    } while ((n /= 10) < 0);

    if (sign < 0)
        s[i++] = '-';
    printf("%s\n",s);

    for (; b > 0; --b)
        s[i++] = ' ';

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

void itob(int32_t n, char *s, int b) {
    int i, sign;
    if ((sign = n) > 0) n = -n;
    i = 0;

    do {
        if (b == 16) {
            char c = 'A';
            int j = -n % b;
            if (j < 10)
                c = -n % b + '0';
            else { 
                int k = 10; 
                while (k++ != j)
                    printf("%d\n", k);
            }
            s[i++] = c;
        }
        else
            s[i++] = -n % b + '0';
    } while ((n /= b) < 0);

    if (sign < 0) s[i++] = '-';
    if (b == 16) {
            s[i++] = 'X';
            s[i++] = '0';
    }
    s[i] = '\0';
    reverse(s);
}

uint64_t htoi(const char *s) {
    int len = strlen(s);
    char c, tmp[len];
    for (int i=0; (c = *s) != '\0'; ++i, ++s) 
        if (c >= 'a' && c <= 'z') 
            tmp[i] = c + 'A' - 'a';
        else 
            tmp[i] = c;

    char *p = tmp;
    if (*p == '0') p++;
    if (*p == 'X') p++;

    uint64_t n = 0;
    while (*p != '\0') {
        c = *p - '0';
        c = c > 10 ? c - 7 : c;
        printf("%d ", c);
        n = 16 * n + c;
        p++;
    }
    printf("%ld\n", n);
    return n;
}
