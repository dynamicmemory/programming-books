#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

typedef struct Node {
    char *word;
    int count;
    struct Node *left;
    struct Node *right;
} Node;

Node *addtree(Node *, char *);
void treeprint(Node *);
int getword(char *, int);
Node *talloc(void);
// char *strdup(char *);

int main(int argc, char *argv[]) {

    Node *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}

Node *addtree(Node *p, char *w) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } 
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

void treeprint(Node *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4 %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

Node *talloc(void) {
    return (Node*)malloc(sizeof(Node));
}

char *strdup(char *s) {
    char *p;

    p = (char *)malloc(strlen(s)+1);
    if (p != NULL)
        strcpy(p, s);
    return p;

int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalpha(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word [0];
}
