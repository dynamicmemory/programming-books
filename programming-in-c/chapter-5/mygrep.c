#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int mygetline(char *line, int max);

const char *mystrstr(const char *s, const char *t) {
    if (*t == '\0')
        return s;

    for(; *s != '\0'; s++) {
        const char *p = s;
        const char *q = t;

        while (*q != '\0' && *p == *q)
            p++, q++;

        if (*q == '\0') 
            return s;
    } 
    return NULL;
}

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*--argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break; 
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }

    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else 
        while (mygetline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
}
