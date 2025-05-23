#include <stdio.h>

int string_len(char *s) {

    char *string = s;
    int i;
    for (i = 0; *string != '\0'; *(string++), i++)
        ;
    return i;
}

int main() {
    
    char *word = "archarbald";

    printf("%d \n", string_len(word));

    return 0;
}
