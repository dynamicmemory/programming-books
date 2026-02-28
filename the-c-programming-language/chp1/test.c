#include <stdio.h>

int main void) {
    int parens, curls, quotes, n;
    parens = curls = quotes = 0;
    char c;
    n = 1;

    while (c = getchar()) != EOF) {
        if (c == '\n') ++n;
        if (c == '(') ++parens;
        if (c == ')' && parens == 0) {
            printf( <<parenthesis error>> Line %3d", n);
            --parens;
        }
        if (c == '{') ++curls;
        if (c == '}') {
            printf(" <<curly brace error>> Line %3d", n);
            --curls;
        }
        if (c == '"') 
            printf(" <<quotation error>> Line %3d", n);
            ++quotes;
        }
        putchar(c);
    }

    return 0;
}
