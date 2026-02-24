#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

// C = (5.9) * (F-32)
int main(void) {
    float fahr, celsius;

    fahr = LOWER;
    printf("|Fahr | Celsius|\n");
    printf("|-----|--------|\n");
    while (fahr <= UPPER) {
        celsius = 5.0/9.0 * (fahr - 32.0);
        printf("|%3.0f  |  %6.2f|\n", fahr, celsius);
        fahr = fahr + STEP;
    }
    printf("|-----|--------|\n");


    printf("|Celsius | Fahr  |\n");
    printf("|--------|-------|\n");
    celsius = LOWER;
    while (celsius <= UPPER) {
        fahr = celsius*9.0 / 5.0 + 32;
        printf("|%3.0f     | %6.2f|\n", celsius, fahr);
        celsius = celsius + STEP;
    }
    printf("|--------|-------|\n");

    for (float i=UPPER; i>=LOWER; i = i-STEP)
        printf("%3.0f\t%6.2f\n", i, (5.0/9.0) *(i -32.0));
    
    return 0;
}



