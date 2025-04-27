#include <stdio.h>

int main(int argc, char *argv[]) {
// int main() {
    // int argc = 3;
    // char *argv_array[] = {"./program", "Hello", "there", NULL};
    // char **argv = argv_array; 
    //
    // while (--argc > 0)
        // printf("word: %p\n", ++argv);

    printf("%c", *++argv[0]);
    printf("%c", (*++argv)[0]);

    // while (--argc > 0) {
    //     printf("Input String: %s, Letters - ", *++argv);
    //     while (*argv[0] != '\0') 
    //         printf("%c ", *argv[0]++);
    //     printf("\n");
    // }
                         

    return 0;
}

//     char *array[] = {"apple", "banana", "cherry", NULL };
//     char **p = array;
//
//     printf("Initial array pointer: %p\n", (void *)p);
//
//     while (*p) {
//         printf("p points to: %p -> '%s'\n", (void *)p, *p);
//         printf("First letter: %c\n", (*p)[0]);
//         p++;
//     }
//
//     char *word = "hello";
//     char *q = word;
//
//     printf("word: %s\n", word);
//     printf("Starting at: %p -> %c\n", (void *)q, *q);
//
//     while (*q) {
//         printf("Char at %p: %c\n", (void *)q, *q);
//         q++;
//     }
//
//     // while(--argc > 0)
//     //     printf("%s", (++argv)[0]);
//
//     return 0;
// }
