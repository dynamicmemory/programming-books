#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int c;
    while(argc-- > 1) {
        char *arg = *++argv;

        if (strcmp(arg, "lower") == 0) {
            while ((c = getchar()) != EOF)
                putchar(tolower(c));
        }
        else if (strcmp(arg, "upper") == 0) {
            while ((c = getchar()) != EOF)
                putchar(toupper(c));
        }
        else {
        }
    }
    return 0;
}
