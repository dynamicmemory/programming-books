#include <stdio.h>
#include <stdint.h>

void expand(char*, char*);

int main(void) {
    char *s1 = "a-z";
    char s2[256];
    expand(s1, s2);
    printf("%s : %s\n", s1, s2);

    return 0;
}

void expand(char *s1, char *s2) {
    uint32_t i, j;
    char prev, curr, next, start, end;
    for (i=j=0; *s1 != '\0'; i++) {
        if (prev == '-') {
            end = *s1++;
            curr = start;
            while (curr != end) { 
                s2[j++] = curr++;
            }
        }
        else if (*s1 == 'a') {
            start = *s1;
            s1++;
        }
        else if (*s1 == '-') {
            prev = *s1;
            s1++;
        }
    }
    s2[j] = '\0';
}
