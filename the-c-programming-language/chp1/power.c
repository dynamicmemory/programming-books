#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint64_t power(uint64_t, uint64_t);

int main(void) {

    uint64_t n = power(2,5);
    printf("%ld\n", n);

    printf("%f\n", pow(2,5));
    return 0;
}

uint64_t power(uint64_t m, uint64_t n) {
    uint64_t result = m;
    while (--n > 0)
        result *= m;
        
    return result;
}

