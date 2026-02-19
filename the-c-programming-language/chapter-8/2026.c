#include <stdio.h>
#include <unistd.h>
#include <string.h>

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


int main(int argc, char **argv) {

    char text[] = "Hello there\n";

    write(0, text, strlen(text));

    char buf[BUFSIZ];
    int n;

    while ((n = read(0, buf, BUFSIZ)) > 0) write(1, buf, n);

    return 0;
}
