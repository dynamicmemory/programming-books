#include <stdio.h>

int main(int argc, char *argv[]) {

    while (--argc > 0)
        printf((argc > 1) ? "%s " : "%s", *++argv);
    printf("\n");
    return 0;

    // for (int i = 1; i < argc; i++)
    //      printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    // printf("\n");
    // return 0;
}
