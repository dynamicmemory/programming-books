#include <stdio.h>
#include <stdint.h>

void printb(uint32_t);
uint32_t setbits(uint32_t, uint32_t, uint32_t, uint32_t);
uint32_t invert(uint32_t, uint32_t, uint32_t);
uint32_t rightrot(uint32_t, uint32_t);


int main(void) {

    // printb(setbits(211, 2, 3, 140));
    invert(211, 2, 3);
    rightrot(211, 3);
    return 0;
}

// x = 11010011 p = 2 n = 3 y = 10010100 x = 10001100
uint32_t setbits(uint32_t x, uint32_t p, uint32_t n, uint32_t y) {
    return ((~0 << n) & x) | (~(~0 << n) & y);
}

void printb(uint32_t x) {
    for (int i = 7; i >= 0; i--)
        printf("%d", (x >> i) & 1);
    printf("\n");
}

uint32_t invert(uint32_t x, uint32_t p, uint32_t n) {
    return (~(~0 << n) & ~x) | ((~0 << n) & x);
}

uint32_t rightrot(uint32_t x, uint32_t n) {
    return (~(~0 << n) & x) << (8-n) | (x >> n);
    }
