#include <stdio.h>
#include <stdint.h>

#undef getline
#define MAXLINE 1000
int32_t budget_getline(char *, int);
void reverse(char *, int32_t);

int main(void) {
    char line[MAXLINE];
    int32_t len;

    while ((len = budget_getline(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }

    return 0;
}

void reverse(char *s, int32_t len) {
    char p[len];
    int i, j;
    for (i=len-2, j=0; i>=0; --i, ++j) {
        p[j] = s[i];
    }

    p[j] = '\n';
    p[++j] = '\0';

    for (int i=0; i<=len; ++i) 
        s[i] = p[i];
}

int32_t budget_getline(char *s, int lim) {
    int32_t i, c;
    for (i=0; i<lim && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
