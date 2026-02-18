#include <stdio.h>
#include <string.h>

int main(void) {

    FILE *fp1 = fopen("./logs1.txt", "r");
    FILE *fp2 = fopen("./logs2.txt", "r");
    if (fp1 == NULL || fp2 == NULL) {
        perror("File open");
        return 0;
    }

    char buf1[1024];
    char buf2[1024];

    while (fgets(buf1, sizeof buf1, fp1) != NULL && fgets(buf2, sizeof buf2, fp2) != NULL){
        if (!strcmp(buf1, buf2)) {
            printf("%s %s", buf1, buf2);
            break;
        }
    }
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}
