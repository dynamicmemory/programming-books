#include <stdatomic.h>
#define HASHSIZE 101

typedef struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
} nlist;

static nlist *hashtab[HASHSIZE];

unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

nlist *lookup(char *s) {
    nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

nlist *install(char *name, char *defn) { 
    nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;

        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else 
        free ((void *) np->defn);
    
    if ((np->defn = strdup(defn)) = NULL)
        return NULL;
    return np;
}
