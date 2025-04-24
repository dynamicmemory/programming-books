#include <ctype.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    char c;
    int numbers[1000];
    int *ip = numbers;
    int a, b;
    // 2 3 4 + * == 2 x (3 + 4)
    char *argvlite = "x234+k";
    int argclite = 6;

    // while(argclite-- > 1) {
    while(argc-- > 0) {
        // while ((c = *++argvlite)) {
        while ((c = *++argv[0])) {
            switch(c) {
                case '+':
                    a = *--ip;
                    b = *--ip;
                    *ip = a + b;
                    printf("%d ", *ip);
                    ip++;
                    break;
                case 'k':
                    a = *--ip;
                    b = *--ip;
                    *ip = a * b;
                    printf("%d ", *ip);
                    ip++;
                    break;
                default:
                    if (isdigit(c)) {
                        *ip = c - '0';
                        ip++;
                        }
                    break;
                }
        }
    }

    printf("Test value should equal 14, test value = %d\n", *--ip);

    return 0;
}
