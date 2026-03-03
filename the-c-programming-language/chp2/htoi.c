#include <stdio.h>
#include <string.h>

void htoi(const char *);

int main(void) {

    char *hex1 = "A49";
    char *hex2 = "a49";
    htoi(hex1);
    // htoi(hex2);

    // printf("%s\n",hex1);

    return 0;
}

void htoi(const char *s) {
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

    int n = 0;
    while (*p != '\0') {
        c = *p - '0';
        c = c > 10 ? c - 7 : c;
        printf("%d ", c);
        n = 16 * n + c;
        p++;
    }
    printf("%d\n", n);
}
