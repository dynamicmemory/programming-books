#include <stdio.h>

int main(int argc, char *argv[]) {
    
    FILE *fp;
    fp = fopen("logs.txt", "a");

    int c;
    while ((c = getc(fp)) != EOF)
        // printf("%c",c);
        putc(c, stdout);

    return 0;
}
