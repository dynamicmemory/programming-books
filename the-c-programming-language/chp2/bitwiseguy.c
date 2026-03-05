#include <stdio.h>

void printb(unsigned int );


int main(void) {
    unsigned int x = 0b11010110;
    int p = 4;
    int n = 3;

    printf("x = %u ", x);
    printb(x);
    printf("\n");

    int shift = p + 1 - n;
    printf("shift = %d\n", shift);

    unsigned shifted =  x >> shift;
    printf("shifted = %u ", shifted);
    printb(shifted);
    printf("\n");

    unsigned a = ~0;

    printf("~0 = ");
    printb(a);
    printf("\n");

    unsigned b = a << n;
    printf("~0 << n = ");
    printb(b);
    printf("\n");

    unsigned mask = ~b;

    printf("mask = ");
    printb(mask);
    printf("\n");

    unsigned result = shifted & mask;
    printf("result = ");
    printb(result);
    printf("\n");


    return 0;
}

void printb(unsigned int x) {
    for (int i = 7; i >= 0; i--)
        printf("%d", (x >> i) & 1);
    printf("\n");
}
