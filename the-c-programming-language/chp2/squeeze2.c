#include <stdio.h>

// enum letter {OUT, IN};
#define OUT 0
#define IN 1

void squeeze(char *, char *);
int any(char *, char *);

int main(void) {
    char s1[] = "flib";
    squeeze(s1, "insane");
    printf("%s\n", s1); 

    int n = any(s1, "cibman");
    printf("%d\n", n); 

    return 0;
}

void squeeze(char *s1, char *s2) {
    int i, j, k, state;
    k = state = OUT;
    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                state = IN;
                break;
            }
        }
        if (state) {
            state = OUT;
            continue;
        }
        else { 
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}

int any(char *s1, char *s2) {
    int i, j;
    for (i = 0; s2[i] != '\0'; ++i)
        for (j = 0; s1[j] != '\0'; ++j)
            if (s2[i] == s1[j])
                return j+1;
    return -1;
}
