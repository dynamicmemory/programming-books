#include <stdio.h>
#include <stdint.h>

enum bool {False, True};


int str_len(const char *);
int atoi(char *);

int main(void) {

    char word[] = "Hello";
    printf("%d\n", str_len(word));

    // for (i=-; i<lim-1 && (c=getchar()) !='\n' && c = EOF; ++i)
    char c, s[10];
    int lim, i;
    while (i<lim-1) {
        if ((c=getchar() == '\n'))
            break;
        if (c == EOF)
            break;
        s[i] = c;
        ++i;
    }


    return 0;
}

int str_len(const char *s) {
    const char *tmp = s;
    while (*tmp++) ;
    return tmp - s - 1;
}

int atoi(char *s) {
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

uint8_t lower(uint8_t c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else 
        return c;
}
