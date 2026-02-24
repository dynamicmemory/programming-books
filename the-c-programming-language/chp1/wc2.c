#include <stdio.h>
#include <stdint.h>

#define IN 1
#define OUT 0

int main(void) {

    int8_t c, state;
    uint64_t nl, nw, nc;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ' ||c == '\n' || c == '\t') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }

        if (c == ' ') putchar('\n');
        else putchar(c);
    }
    printf("%ld %ld %ld\n", nl, nw, nc);


    return 0;
}
