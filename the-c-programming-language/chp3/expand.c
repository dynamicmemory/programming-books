#include <stdio.h>
#include <stdint.h>

void expand(char*, char*);

int main(void) {
    char *s1 = "a-z0-9";
    char s2[256];
    expand(s1, s2);
    printf("%s : %s\n", s1, s2);

    return 0;
}

void expand(char *s1, char *s2) {
    uint32_t i, j;
    char prev, curr, next, start, end;
    while (*s1 != '\0') {
        switch(*s1) {
            case 'a':
                start = *s1;
                s1++;
                break;
            case '0':
                start = *s1;
                s1++;
                break;
            case '-':
                prev = *s1;
                s1++;
                break;
            default :
                end = *s1++;
                curr = start;
                while (curr <= end) { 
                    s2[j++] = curr++;
                }
                prev = end;
                break;
        }
    }
    s2[j] = '\0';
}
