#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
};


int main(int argc, char *argv[]) {
    int x = 1;
    int y = 2;

    printf("x: %d, y: %d\n", x, y); 
    swap(&x, &y);
    printf("x: %d, y: %d\n", x, y); 

    return 0;
}
