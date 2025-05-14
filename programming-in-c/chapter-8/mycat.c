#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void my_cat(char *filename) {

    char buf[BUFSIZ];
    // FILE *fp = fopen(filename, "r");
    int f = open(filename, O_RDONLY, 0);
    int c;

    // while ((c = getc(fp)) != EOF)
    while((c = read(f, buf, BUFSIZ)) > 0) // reading f, is just the number if it successfully read the file.
        // putc(c, stdout);
        write(1, buf, c);    // 1 is stdout, so writing the contents of the file to stdout
}


int main(int argc, char *argv[]) {

    if (argc > 1)
        my_cat(*++argv);
    return 0;
}
