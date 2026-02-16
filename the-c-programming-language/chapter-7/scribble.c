#include <stdio.h>

int main(void) {
    int x;
    if (scanf("%d", &x) != 1) {
        printf("Error reading in number\n");
        return 1;
    }

    char buf[] = "43 3.14";
    int i;
    float f;
    if (sscanf(buf, "%d %f", &i, &f) != 2) {
        printf("Error parsing in data\n");
        return 1;
    }


    return 0;
}
