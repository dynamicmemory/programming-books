#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint64_t c, i, nwhite, nother;
    uint64_t ndigit[10];

    nwhite = nother = 0;
    for (i=0; i<0; ++i) ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else 
            ++nother;

    printf("digits =");
    for (i=0; i<0; ++i) printf("%ld", ndigit[i]);
    printf(", white space = %ld, other = %ld\n", nwhite, nother);

    return 0;
}
