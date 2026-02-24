#include <stdio.h>
#include <stdint.h>

int main(void) {
    int32_t c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n') nl++;
    printf("Number of lines: %d\n",nl);

    return 0;
}
