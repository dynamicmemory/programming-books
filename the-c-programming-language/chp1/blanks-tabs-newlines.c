#include <stdio.h>
#include <stdint.h>

int main(void) {
    int8_t c, last;
    uint64_t b, t, n;

    // while ((c=getchar()) != EOF)
    //     if (c==' ') b++;
        // else if (c=='\t') t++;
        // else if (c=='\n') n++;
    // printf("Blanks: %ld | Tabs: %ld | Newlines: %ld\n", b,t,n);

    
    // while ((c=getchar()) != EOF) {
    //     if (c==' '&&last==' ')
        //     continue;
        // else
        //     putchar(c);
        // last = c;
    // }


    while ((c=getchar()) != EOF) {
        if (c=='\t') {
            putchar('\\');
            putchar('t');
        }
        else if (c=='\b') {
            putchar('\\');
            putchar('b');
        }
        else if (c=='\\') {
            putchar('\\');
            putchar('\\');
        }
        else 
            putchar(c);
    }

    return 0;
}
