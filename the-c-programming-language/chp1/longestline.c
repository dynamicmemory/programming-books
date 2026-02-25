#include <stdio.h>
#include <stdint.h>
#undef getline
#define MAXLINE 1000

int32_t getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
    int32_t len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) 
        printf("%s", longest);
    return 0;
}

int32_t getline(char s[], int lim) {
    int c, i;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
