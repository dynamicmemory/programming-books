#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

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

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    if (argc > 1)
        my_cat(*++argv);

    clock_gettime(CLOCK_MONOTONIC, &end);

    double seconds = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Execution time: %.9f seconds \n", seconds);

    return 0;
}


// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
//
// void my_cat(char *filename) {
//
//     char buf[BUFSIZ];
//     // FILE *fp = fopen(filename, "r");
//     int f = open(filename, O_RDONLY, 0);
//     int c;
//
//     // while ((c = getc(fp)) != EOF)
//     while((c = read(f, buf, BUFSIZ)) > 0) // reading f, is just the number if it successfully read the file.
//         // putc(c, stdout);
//         write(1, buf, c);    // 1 is stdout, so writing the contents of the file to stdout
// }
//
//
// int main(int argc, char *argv[]) {
//
//     if (argc > 1)
//         my_cat(*++argv);
//     return 0;
// }
