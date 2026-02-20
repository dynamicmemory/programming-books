#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#undef BUFSIZ
#define BUFSIZ 4096

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: cat2 <filename>\n");
        return 0;
    }

    int fd = open(argv[1], O_RDONLY, 0);
    char buf[BUFSIZ];
    int n;

    while ((n = read(fd, buf, BUFSIZ)) != 0) write(0, buf, n);
    return 0;
}
