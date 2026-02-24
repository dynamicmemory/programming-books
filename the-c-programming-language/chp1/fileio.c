#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

#undef getchar 
#undef putchar 
#undef EOF 

#define EOF -1

uint8_t getchar();
void putchar(uint8_t);

int main(void) {
    uint8_t c = 0;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }

    return 0;
}

uint8_t getchar() { 
    uint8_t c;
    read(1, &c, sizeof(c));
    return c;
}

void putchar(uint8_t c) { 
    write(0, &c, sizeof(c)); 
}
