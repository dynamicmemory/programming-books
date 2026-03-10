#include <stdint.h>

int binsearch(uint32_t, int *, uint32_t);

int binsearch(uint32_t x, int *vec, uint32_t n) { 
    int high, mid, low;

    low = 0;
    high = n-1;
    mid = (low+high)/2;
    while (low <= high) {
        if (x < vec[mid])
            high = mid-1;
        else 
            low = mid+1;
        mid = (low+high)/2;
    }
    return (x == vec[mid]) ? mid : -1;
}

