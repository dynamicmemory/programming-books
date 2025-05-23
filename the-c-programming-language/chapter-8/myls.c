#include "dirent.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void fsize(char *);
int mystat(char *, struct stat *);
void dirwalk(char *, void (*fcn)(char *));

int main(int argc, char *argv[]) {

    if (argc == 1)
        fsize(".");
    else 
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}

void dirwalk(char *dir, void (*fcn)(char *)) {
    char name[MAX_PATH];
    Dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: cant open %s\n", dir);
        return;
    }

    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0) continue;

        if (strlen(dir)+strlen(dp->name)+2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s%s too long \n", dir, dp->name);
        else {
            sprintf(name, "%s%s", dir, dp->name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}


