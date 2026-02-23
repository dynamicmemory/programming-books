#include <stdio.h>
#include <stdlib.h>

void fileread(char *file) {
    FILE *frp = fopen(file, "r");
    char c;

    while ((c = getc(frp)) != EOF)
        putc(c, stdout);
    fclose(frp);
}

void fileappend(char *file, char *line) {
    FILE *fap = fopen(file, "a");
    char c;
    char *temp = line; 
    while (*temp != '\n') {
        putc(*temp, fap);
        temp++;
    }
    putc('\n', fap);

    fclose(fap);
}

int main(int argc, char *argv[]) {
    
    char *file = "logs.txt";
    fileread(file);
    
    char newline[1000];
    char *lp = newline;
    char c;

    while ((c = getchar()) != '\n')
        *lp++ = c;
    *lp++ = '\n';
    *lp = '\0';
    // printf("%s\n",newline); 
    
    fileappend(file, newline); 
    system("clear");
    fileread(file); 

    return 0;
}
