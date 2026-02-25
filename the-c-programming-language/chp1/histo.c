#include <stdio.h>
#include <stdint.h>

#define IN 1
#define OUT 0
#define MAXWORDLEN 10

int main(void) {
    uint32_t word;
    uint8_t c, state;
    uint32_t words[MAXWORDLEN];

    for (int i=0; i<MAXWORDLEN; ++i) words[i] = 0;

    state = word = OUT; 
    while ((c = getchar()) != '\n')
        if (c == ' ' || c == '\t') {
            if (state) {
                ++words[word];
                state = OUT;
                word = 0;
            }
        }
        else if (!state) {
            state = IN;
            ++word;
        }
        else ++word;

    for (int i=1; i<MAXWORDLEN; ++i) {
        printf("%3.0d| ", i);
        for (int j=0; j<words[i]; ++j)
            printf("*");
        printf("\n");
    }

    return 0;
}
