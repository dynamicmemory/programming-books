#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#undef getchar

int getchar(void) {
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) {
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

void error(char *, ...);

int main(int argc, char **argv) {

    char text[] = "Hello there\n";

    write(0, text, strlen(text));

    char buf1[BUFSIZ];
    int n1;

    while ((n1 = read(0, buf1, BUFSIZ)) > 0) write(1, buf1, n1);

    int fd = open("./test.txt", O_RDONLY, 0);


    int f1, f2, n;
    char buf[BUFSIZ];

    if (argc!=3) error("Usage: cp from to");
    if ((f1=open(argv[1], O_RDONLY, 0)) == -1) error("Usage: cp from to");
    if ((f2=creat(argv[2], 0755)) == -1) error("Usage: cp from to");

    while ((n=read(f1, buf, BUFSIZ)) > 0)
        if (write(f2, buf, n) != n)
            error("cp: write error on file");

    return 0;
}


