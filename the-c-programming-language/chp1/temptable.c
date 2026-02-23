#include <stdio.h>

// C = (5.9) * (F-32)
int main(void) {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("|Fahr | Celsius|\n");
    printf("|-----|--------|\n");
    while (fahr <= upper) {
        celsius = 5.0/9.0 * (fahr - 32.0);
        printf("|%3.0f  |  %6.2f|\n", fahr, celsius);
        fahr = fahr + step;
    }
    printf("|-----|--------|\n");


    printf("|Celsius | Fahr  |\n");
    printf("|--------|-------|\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius*9.0 / 5.0 + 32;
        printf("|%3.0f     | %6.2f|\n", celsius, fahr);
        celsius = celsius + step;
    }
    printf("|--------|-------|\n");
    
    
    return 0;
}



