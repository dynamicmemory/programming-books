#include <stdio.h>
#include <string.h>

char *upper(char *s) {
    char c;
    for (int i=0; i < strlen(s); ++i) {
        if (s[i] == '\0') continue;

        if (s[i] >= 96 && s[i] <= 122) 
            s[i] = s[i] - 32;
    }
    return s;
}

char *lower(char *s) {
    char c;
    for (int i=0; i < strlen(s); ++i) {
        if (s[i] == '\0') continue;

        if (s[i] >= 65 && s[i] <= 90) 
            s[i] = s[i] + 32;
    }
    return s;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        printf("usage: 2026 <upper/lower> <word>\n");
        return 1;
    }

    char *result;

    if (!strcmp(argv[1], "upper")) 
        result = upper(argv[2]);
    else 
        result = lower(argv[2]);

    printf("%s\n", result);
    return 0;
}
