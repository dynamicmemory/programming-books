#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *ifp, FILE *ofp) { 
    int c;
    while ((c = getc(ifp)) != EOF) 
        putc(c, ofp);
}


int main(int argc, char **argv) {
    int x;
    // if (scanf("%d", &x) != 1) {
    //     printf("Error reading in number\n");
    //     return 1;
    // }

    char buf[] = "43 3.14";
    int i;
    float f;
    if (sscanf(buf, "%d %f", &i, &f) != 2) {
        printf("Error parsing in data\n");
        return 1;
    }

    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0];

    if (argc == 1) filecopy(stdin, stdout);
    else 
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            }
            else {
                filecopy(fp, stdout);
                fclose(fp);
            }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}
