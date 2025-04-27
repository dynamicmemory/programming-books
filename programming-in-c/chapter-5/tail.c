#include <ctype.h>
#include <stdio.h>

int my_getline(char *s, int lim) {
    int c;
    char *start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;

    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - start;
}

int main(int argc, char *argv[]) {
    int n = 10;
    if (argc > 1 && (*++argv)[0] == '-') {
        n = 0;
        while (isdigit(*++argv[0]))
            n = n * 10 + (*argv[0] - '0');
    }

    int control;
    char *lines[n];
    char buffer[1000];
    int idx = 0; 
    // buffer = "hello";
    // printf("%p = %s\n",buffer, buffer);

    // buffer = "bitch";
    // printf("%p = %s\n", buffer, buffer);

    while((control = my_getline(buffer, 1000)) > 0) {
        if (idx < n) {
        lines[idx] = buffer; 
        idx++; 
        }
    }   

    int idx2 = 0;
    while (idx2 < idx) {
        printf("%p = %s", lines[idx2], lines[idx2]);
        idx2++;
    }
}

// #include <ctype.h>
// #include <stdio.h>
//
// int main(int argc, char *argv[]) {
//
//     int n = 0;
//     int c;
//     int tens = 1; 
//
//     while (--argc > 0 && (*++argv)[0] == '-')
//         while ((c = *++argv[0]))
//             if (!isdigit(c)) {
//                 n = 10;
//                 break;
//             }
//             else {
//                 n = n * tens + (c - '0');
//                 tens *= 10;
//             }
//
//     int d, j, idx = 0;
//     char *lines[n];
//
//     while (n-- > 0) {
//         char line[1000];
//         while ((d = getchar()) != EOF) {
//             if (d == '\n') {
//                 line[j] = '\0';
//                 lines[idx] = line;
//             }                
//             else 
//                 line[j] = d;
//         j++;
//         }
//         idx++;
//     }
//
//     return 0;
// }
