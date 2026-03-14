#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max);
int strindex(char *s, char *t);
int strrindex(char *s, char *t);

int main(void) {
    char pattern[] = "old";
    char line[MAXLINE];
    int found = 0;

    while (get_line(line, MAXLINE) > 0) 
        // if (strindex(line, pattern) >= 0) {
        if ((found = strrindex(line, pattern)) >= 0) {
            printf("%s | %d", line, found);
        }

    return 0;
}

int get_line(char s[], int max) {
    int c, i;
    i = 0;
    while (--max > 0 && (c=getchar()) != EOF && c != '\n') 
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char *s, char *t) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++) ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int strrindex(char *s, char *t) {
    int i, j, k;
    int occurance = 0;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++) ;
        if (k > 0 && t[k] == '\0')
            occurance = i;
    }
    if (!occurance) return -1;
    else return occurance;
}
