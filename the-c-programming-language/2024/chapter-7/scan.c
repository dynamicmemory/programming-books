#include <stdio.h>

int main() {
    int one, two;
    char sign;
    scanf("%d %c %d", &one, &sign, &two);

    switch(sign) {

        case '+':
            printf("%d\n", one + two);
            break;
        case '-':
            printf("%d\n", one - two);
            break;
        case '*':
            printf("%d\n", one * two);
            break;
        case '/':
            if (two != 0) {
                double c_one = one;
                double c_two = two;
                printf("%f\n", c_one / c_two);
            }
            else 
                printf("Cannot divide by zero");
        default:
            break;
    }
    return 0;
}
