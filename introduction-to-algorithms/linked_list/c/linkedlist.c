#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "node.h"

typedef struct Linked_List {
    Node *head;
    Node *tail;
} list;

void initlist(list *ls) {
    ls->head = NULL;
    ls->tail = NULL;

    // ls->head->prev = NULL;
    // ls->head->next = NULL;
    // ls->tail->prev = NULL;
    // ls->tail->next = NULL;

}

bool isempty(list *ls) {
    return ls->head == NULL && ls->tail == NULL;
}

Node *contains(list *ls, int key) {
    Node *p = ls->head;
    while (p != NULL) {
        if (p->key == key)
            return p;
        p = p->next;
    }
    return NULL;
}

void add(list *ls, int key) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->prev = NULL;

    if (ls->head == NULL) {
        ls->head = p;
        ls->head->next = NULL;
        ls->tail = p;
    }
    else {
        ls->tail->next = p;
        p->prev = ls->tail;
        ls->tail = p;
        ls->tail->next = NULL;
    }
}

void delete(list *ls, int key) {

    if (ls->head != NULL) {
        printf("head %d, tail %d\n", ls->head->key, ls->tail->key);
        Node *p = contains(ls, key);

        if (p != NULL) {

            if (p != ls->head && p != ls->tail) {
                p->next->prev = p->prev;
                p->prev->next = p->next;
            }
            else if (p == ls->head && p == ls->tail) {
                ls->head = NULL;
                ls->tail = NULL;
            }
            else if (p == ls->head) {
                ls->head = ls->head->next;
                if (ls->head != NULL)
                    ls->head->prev = NULL;
            }
            else if (p == ls->tail) {
                ls->tail = ls->tail->prev;
                if (ls->tail != NULL)
                    ls->tail->next = NULL;
            }
            free(p);
        }
    }
    else 
        printf("Heads empty dawg");
}

void deletefromhead(list *ls) {
    while(!isempty(ls))
        delete(ls, ls->head->key);
}

void insert(list *ls, int pos, int key) {

}

void printlist(list *ls) { 
    if (!isempty(ls)) {
        Node *p = ls->head;
        while (p != NULL) {
            printf("%d ", p->key);
            p = p->next;
        }
        printf("\n");
    }
    else 
        printf("List is empty\n");
}

int length(list *ls) {
    int n = 0;
    Node *p = ls->head;
    while (p != NULL) {
        p = p->next;
        n++;
    }
    return n;
}

int main(int argc, char *argv[]) {

    list ls;
    initlist(&ls);

    add(&ls, 1);
    add(&ls, 2);
    add(&ls, 3);
    add(&ls, 4);

    printf("%s\n", (contains(&ls, 3) != NULL) ? "true" : "false");
    printf("%s\n", (contains(&ls, 5) != NULL) ? "true" : "false");
    printlist(&ls);    // This doesnt throw a seg fault it works fine

    delete(&ls, 1);

    printlist(&ls);    // This doesnt throw a sef fault it works fine 

    delete(&ls, 4);
    delete(&ls, 2);
    delete(&ls, 3);
    printlist(&ls);    // This doesnt throw a seg fault it works fine

    add(&ls, 1);
    add(&ls, 2);
    add(&ls, 3);
    add(&ls, 4);
    printlist(&ls);  // Why does this line only here cause a segfault?

    printf("List size is %d\n", length(&ls));
    deletefromhead(&ls);
    printlist(&ls);
    return 0;
}










// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include "node.h"
//
// typedef struct Linked_List {
//     Node *head;
//     Node *tail;
// } list;
//
// void initlist(list *ls) {
//     ls->head = NULL;
//     ls->tail = NULL;
//
//     // ls->head->prev = NULL;
//     // ls->head->next = NULL;
//     // ls->tail->prev = NULL;
//     // ls->tail->next = NULL;
//
// }
//
// bool isempty(list *ls) {
//     return ls->head == NULL && ls->tail == NULL;
// }
//
// Node *contains(list *ls, int key) {
//     Node *p = ls->head;
//     while (p != NULL) {
//         if (p->key == key)
//             return p;
//         p = p->next;
//     }
//     return NULL;
// }
//
// void add(list *ls, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//     p->key = key;
//     p->prev = NULL;
//
//     if (ls->head == NULL) {
//         ls->head = p;
//         ls->head->next = NULL;
//         ls->tail = p;
//     }
//     else {
//         ls->tail->next = p;
//         p->prev = ls->tail;
//         ls->tail = p;
//         ls->tail->next = NULL;
//     }
// }
//
// void delete(list *ls, int key) {
//
//     if (ls->head != NULL) {
//         printf("head %d, tail %d\n", ls->head->key, ls->tail->key);
//         Node *p = contains(ls, key);
//
//         if (p != NULL) {
//
//             if (p != ls->head && p != ls->tail) {
//                 p->next->prev = p->prev;
//                 p->prev->next = p->next;
//             }
//             else if (p == ls->head && p == ls->tail) {
//                 ls->head = NULL;
//                 ls->tail = NULL;
//             }
//             else if (p == ls->head) {
//                 ls->head = ls->head->next;
//                 if (ls->head != NULL)
//                     ls->head->prev = NULL;
//             }
//             else if (p == ls->tail) {
//                 ls->tail = ls->tail->prev;
//                 if (ls->tail != NULL)
//                     ls->tail->next = NULL;
//             }
//             free(p);
//         }
//     }
//     else 
//         printf("Heads empty dawg");
// }
//
// void deletefromhead(list *ls) {
//     while(!isempty(ls))
//         delete(ls, ls->head->key);
// }
//
// void insert(list *ls, int pos, int key) {
//
// }
//
// void printlist(list *ls) { 
//     if (!isempty(ls)) {
//         Node *p = ls->head;
//         while (p != NULL) {
//             printf("%d ", p->key);
//             p = p->next;
//         }
//         printf("\n");
//     }
//     else 
//         printf("List is empty\n");
// }
//
// int length(list *ls) {
//     int n = 0;
//     Node *p = ls->head;
//     while (p != NULL) {
//         p = p->next;
//         n++;
//     }
//     return n;
// }
//
// int main(int argc, char *argv[]) {
//
//     list ls;
//     initlist(&ls);
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//
//     printf("%s\n", (contains(&ls, 3) != NULL) ? "true" : "false");
//     printf("%s\n", (contains(&ls, 5) != NULL) ? "true" : "false");
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     delete(&ls, 1);
//
//     printlist(&ls);    // This doesnt throw a sef fault it works fine 
//
//     delete(&ls, 4);
//     delete(&ls, 2);
//     delete(&ls, 3);
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//     printlist(&ls);  // Why does this line only here cause a segfault?
//
//     printf("List size is %d\n", length(&ls));
//     deletefromhead(&ls);
//     printlist(&ls);
//     return 0;
// }


// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include "node.h"
//
// typedef struct Linked_List {
//     Node *head;
//     Node *tail;
// } list;
//
// void initlist(list *ls) {
//     ls->head = NULL;
//     ls->tail = NULL;
//
//     // ls->head->prev = NULL;
//     // ls->head->next = NULL;
//     // ls->tail->prev = NULL;
//     // ls->tail->next = NULL;
//
// }
//
// bool isempty(list *ls) {
//     return ls->head == NULL && ls->tail == NULL;
// }
//
// Node *contains(list *ls, int key) {
//     Node *p = ls->head;
//     while (p != NULL) {
//         if (p->key == key)
//             return p;
//         p = p->next;
//     }
//     return NULL;
// }
//
// void add(list *ls, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//     p->key = key;
//     p->prev = NULL;
//
//     if (ls->head == NULL) {
//         ls->head = p;
//         ls->head->next = NULL;
//         ls->tail = p;
//     }
//     else {
//         ls->tail->next = p;
//         p->prev = ls->tail;
//         ls->tail = p;
//         ls->tail->next = NULL;
//     }
// }
//
// void delete(list *ls, int key) {
//
//     if (ls->head != NULL) {
//         printf("head %d, tail %d\n", ls->head->key, ls->tail->key);
//         Node *p = contains(ls, key);
//
//         if (p != NULL) {
//
//             if (p != ls->head && p != ls->tail) {
//                 p->next->prev = p->prev;
//                 p->prev->next = p->next;
//             }
//             else if (p == ls->head && p == ls->tail) {
//                 ls->head = NULL;
//                 ls->tail = NULL;
//             }
//             else if (p == ls->head) {
//                 ls->head = ls->head->next;
//                 if (ls->head != NULL)
//                     ls->head->prev = NULL;
//             }
//             else if (p == ls->tail) {
//                 ls->tail = ls->tail->prev;
//                 if (ls->tail != NULL)
//                     ls->tail->next = NULL;
//             }
//             free(p);
//         }
//     }
//     else 
//         printf("Heads empty dawg");
// }
//
// void deletefromhead(list *ls) {
//     while(!isempty(ls))
//         delete(ls, ls->head->key);
// }
//
// void insert(list *ls, int pos, int key) {
//
// }
//
// void printlist(list *ls) { 
//     if (!isempty(ls)) {
//         Node *p = ls->head;
//         while (p != NULL) {
//             printf("%d ", p->key);
//             p = p->next;
//         }
//         printf("\n");
//     }
//     else 
//         printf("List is empty\n");
// }
//
// int length(list *ls) {
//     int n = 0;
//     Node *p = ls->head;
//     while (p != NULL) {
//         p = p->next;
//         n++;
//     }
//     return n;
// }
//
// int main(int argc, char *argv[]) {
//
//     list ls;
//     initlist(&ls);
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//
//     printf("%s\n", (contains(&ls, 3) != NULL) ? "true" : "false");
//     printf("%s\n", (contains(&ls, 5) != NULL) ? "true" : "false");
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     delete(&ls, 1);
//
//     printlist(&ls);    // This doesnt throw a sef fault it works fine 
//
//     delete(&ls, 4);
//     delete(&ls, 2);
//     delete(&ls, 3);
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//     printlist(&ls);  // Why does this line only here cause a segfault?
//
//     printf("List size is %d\n", length(&ls));
//     deletefromhead(&ls);
//     printlist(&ls);
//     return 0;
// }
// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include "node.h"
//
// typedef struct Linked_List {
//     Node *head;
//     Node *tail;
// } list;
//
// void initlist(list *ls) {
//     ls->head = NULL;
//     ls->tail = NULL;
//
//     // ls->head->prev = NULL;
//     // ls->head->next = NULL;
//     // ls->tail->prev = NULL;
//     // ls->tail->next = NULL;
//
// }
//
// bool isempty(list *ls) {
//     return ls->head == NULL && ls->tail == NULL;
// }
//
// Node *contains(list *ls, int key) {
//     Node *p = ls->head;
//     while (p != NULL) {
//         if (p->key == key)
//             return p;
//         p = p->next;
//     }
//     return NULL;
// }
//
// void add(list *ls, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//     p->key = key;
//     p->prev = NULL;
//
//     if (ls->head == NULL) {
//         ls->head = p;
//         ls->head->next = NULL;
//         ls->tail = p;
//     }
//     else {
//         ls->tail->next = p;
//         p->prev = ls->tail;
//         ls->tail = p;
//         ls->tail->next = NULL;
//     }
// }
//
// void delete(list *ls, int key) {
//
//     if (ls->head != NULL) {
//         printf("head %d, tail %d\n", ls->head->key, ls->tail->key);
//         Node *p = contains(ls, key);
//
//         if (p != NULL) {
//
//             if (p != ls->head && p != ls->tail) {
//                 p->next->prev = p->prev;
//                 p->prev->next = p->next;
//             }
//             else if (p == ls->head && p == ls->tail) {
//                 ls->head = NULL;
//                 ls->tail = NULL;
//             }
//             else if (p == ls->head) {
//                 ls->head = ls->head->next;
//                 if (ls->head != NULL)
//                     ls->head->prev = NULL;
//             }
//             else if (p == ls->tail) {
//                 ls->tail = ls->tail->prev;
//                 if (ls->tail != NULL)
//                     ls->tail->next = NULL;
//             }
//             free(p);
//         }
//     }
//     else 
//         printf("Heads empty dawg");
// }
//
// void deletefromhead(list *ls) {
//     while(!isempty(ls))
//         delete(ls, ls->head->key);
// }
//
// void insert(list *ls, int pos, int key) {
//
// }
//
// void printlist(list *ls) { 
//     if (!isempty(ls)) {
//         Node *p = ls->head;
//         while (p != NULL) {
//             printf("%d ", p->key);
//             p = p->next;
//         }
//         printf("\n");
//     }
//     else 
//         printf("List is empty\n");
// }
//
// int length(list *ls) {
//     int n = 0;
//     Node *p = ls->head;
//     while (p != NULL) {
//         p = p->next;
//         n++;
//     }
//     return n;
// }
//
// int main(int argc, char *argv[]) {
//
//     list ls;
//     initlist(&ls);
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//
//     printf("%s\n", (contains(&ls, 3) != NULL) ? "true" : "false");
//     printf("%s\n", (contains(&ls, 5) != NULL) ? "true" : "false");
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     delete(&ls, 1);
//
//     printlist(&ls);    // This doesnt throw a sef fault it works fine 
//
//     delete(&ls, 4);
//     delete(&ls, 2);
//     delete(&ls, 3);
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//     printlist(&ls);  // Why does this line only here cause a segfault?
//
//     printf("List size is %d\n", length(&ls));
//     deletefromhead(&ls);
//     printlist(&ls);
//     return 0;
// }
// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include "node.h"
//
// typedef struct Linked_List {
//     Node *head;
//     Node *tail;
// } list;
//
// void initlist(list *ls) {
//     ls->head = NULL;
//     ls->tail = NULL;
//
//     // ls->head->prev = NULL;
//     // ls->head->next = NULL;
//     // ls->tail->prev = NULL;
//     // ls->tail->next = NULL;
//
// }
//
// bool isempty(list *ls) {
//     return ls->head == NULL && ls->tail == NULL;
// }
//
// Node *contains(list *ls, int key) {
//     Node *p = ls->head;
//     while (p != NULL) {
//         if (p->key == key)
//             return p;
//         p = p->next;
//     }
//     return NULL;
// }
//
// void add(list *ls, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//     p->key = key;
//     p->prev = NULL;
//
//     if (ls->head == NULL) {
//         ls->head = p;
//         ls->head->next = NULL;
//         ls->tail = p;
//     }
//     else {
//         ls->tail->next = p;
//         p->prev = ls->tail;
//         ls->tail = p;
//         ls->tail->next = NULL;
//     }
// }
//
// void delete(list *ls, int key) {
//
//     if (ls->head != NULL) {
//         printf("head %d, tail %d\n", ls->head->key, ls->tail->key);
//         Node *p = contains(ls, key);
//
//         if (p != NULL) {
//
//             if (p != ls->head && p != ls->tail) {
//                 p->next->prev = p->prev;
//                 p->prev->next = p->next;
//             }
//             else if (p == ls->head && p == ls->tail) {
//                 ls->head = NULL;
//                 ls->tail = NULL;
//             }
//             else if (p == ls->head) {
//                 ls->head = ls->head->next;
//                 if (ls->head != NULL)
//                     ls->head->prev = NULL;
//             }
//             else if (p == ls->tail) {
//                 ls->tail = ls->tail->prev;
//                 if (ls->tail != NULL)
//                     ls->tail->next = NULL;
//             }
//             free(p);
//         }
//     }
//     else 
//         printf("Heads empty dawg");
// }
//
// void deletefromhead(list *ls) {
//     while(!isempty(ls))
//         delete(ls, ls->head->key);
// }
//
// void insert(list *ls, int pos, int key) {
//
// }
//
// void printlist(list *ls) { 
//     if (!isempty(ls)) {
//         Node *p = ls->head;
//         while (p != NULL) {
//             printf("%d ", p->key);
//             p = p->next;
//         }
//         printf("\n");
//     }
//     else 
//         printf("List is empty\n");
// }
//
// int length(list *ls) {
//     int n = 0;
//     Node *p = ls->head;
//     while (p != NULL) {
//         p = p->next;
//         n++;
//     }
//     return n;
// }
//
// int main(int argc, char *argv[]) {
//
//     list ls;
//     initlist(&ls);
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//
//     printf("%s\n", (contains(&ls, 3) != NULL) ? "true" : "false");
//     printf("%s\n", (contains(&ls, 5) != NULL) ? "true" : "false");
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     delete(&ls, 1);
//
//     printlist(&ls);    // This doesnt throw a sef fault it works fine 
//
//     delete(&ls, 4);
//     delete(&ls, 2);
//     delete(&ls, 3);
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//     printlist(&ls);  // Why does this line only here cause a segfault?
//
//     printf("List size is %d\n", length(&ls));
//     deletefromhead(&ls);
//     printlist(&ls);
//     return 0;
// }
// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include "node.h"
//
// typedef struct Linked_List {
//     Node *head;
//     Node *tail;
// } list;
//
// void initlist(list *ls) {
//     ls->head = NULL;
//     ls->tail = NULL;
//
//     // ls->head->prev = NULL;
//     // ls->head->next = NULL;
//     // ls->tail->prev = NULL;
//     // ls->tail->next = NULL;
//
// }
//
// bool isempty(list *ls) {
//     return ls->head == NULL && ls->tail == NULL;
// }
//
// Node *contains(list *ls, int key) {
//     Node *p = ls->head;
//     while (p != NULL) {
//         if (p->key == key)
//             return p;
//         p = p->next;
//     }
//     return NULL;
// }
//
// void add(list *ls, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//     p->key = key;
//     p->prev = NULL;
//
//     if (ls->head == NULL) {
//         ls->head = p;
//         ls->head->next = NULL;
//         ls->tail = p;
//     }
//     else {
//         ls->tail->next = p;
//         p->prev = ls->tail;
//         ls->tail = p;
//         ls->tail->next = NULL;
//     }
// }
//
// void delete(list *ls, int key) {
//
//     if (ls->head != NULL) {
//         printf("head %d, tail %d\n", ls->head->key, ls->tail->key);
//         Node *p = contains(ls, key);
//
//         if (p != NULL) {
//
//             if (p != ls->head && p != ls->tail) {
//                 p->next->prev = p->prev;
//                 p->prev->next = p->next;
//             }
//             else if (p == ls->head && p == ls->tail) {
//                 ls->head = NULL;
//                 ls->tail = NULL;
//             }
//             else if (p == ls->head) {
//                 ls->head = ls->head->next;
//                 if (ls->head != NULL)
//                     ls->head->prev = NULL;
//             }
//             else if (p == ls->tail) {
//                 ls->tail = ls->tail->prev;
//                 if (ls->tail != NULL)
//                     ls->tail->next = NULL;
//             }
//             free(p);
//         }
//     }
//     else 
//         printf("Heads empty dawg");
// }
//
// void deletefromhead(list *ls) {
//     while(!isempty(ls))
//         delete(ls, ls->head->key);
// }
//
// void insert(list *ls, int pos, int key) {
//
// }
//
// void printlist(list *ls) { 
//     if (!isempty(ls)) {
//         Node *p = ls->head;
//         while (p != NULL) {
//             printf("%d ", p->key);
//             p = p->next;
//         }
//         printf("\n");
//     }
//     else 
//         printf("List is empty\n");
// }
//
// int length(list *ls) {
//     int n = 0;
//     Node *p = ls->head;
//     while (p != NULL) {
//         p = p->next;
//         n++;
//     }
//     return n;
// }
//
// int main(int argc, char *argv[]) {
//
//     list ls;
//     initlist(&ls);
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//
//     printf("%s\n", (contains(&ls, 3) != NULL) ? "true" : "false");
//     printf("%s\n", (contains(&ls, 5) != NULL) ? "true" : "false");
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     delete(&ls, 1);
//
//     printlist(&ls);    // This doesnt throw a sef fault it works fine 
//
//     delete(&ls, 4);
//     delete(&ls, 2);
//     delete(&ls, 3);
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//     printlist(&ls);  // Why does this line only here cause a segfault?
//
//     printf("List size is %d\n", length(&ls));
//     deletefromhead(&ls);
//     printlist(&ls);
//     return 0;
// }
// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include "node.h"
//
// typedef struct Linked_List {
//     Node *head;
//     Node *tail;
// } list;
//
// void initlist(list *ls) {
//     ls->head = NULL;
//     ls->tail = NULL;
//
//     // ls->head->prev = NULL;
//     // ls->head->next = NULL;
//     // ls->tail->prev = NULL;
//     // ls->tail->next = NULL;
//
// }
//
// bool isempty(list *ls) {
//     return ls->head == NULL && ls->tail == NULL;
// }
//
// Node *contains(list *ls, int key) {
//     Node *p = ls->head;
//     while (p != NULL) {
//         if (p->key == key)
//             return p;
//         p = p->next;
//     }
//     return NULL;
// }
//
// void add(list *ls, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//     p->key = key;
//     p->prev = NULL;
//
//     if (ls->head == NULL) {
//         ls->head = p;
//         ls->head->next = NULL;
//         ls->tail = p;
//     }
//     else {
//         ls->tail->next = p;
//         p->prev = ls->tail;
//         ls->tail = p;
//         ls->tail->next = NULL;
//     }
// }
//
// void delete(list *ls, int key) {
//
//     if (ls->head != NULL) {
//         printf("head %d, tail %d\n", ls->head->key, ls->tail->key);
//         Node *p = contains(ls, key);
//
//         if (p != NULL) {
//
//             if (p != ls->head && p != ls->tail) {
//                 p->next->prev = p->prev;
//                 p->prev->next = p->next;
//             }
//             else if (p == ls->head && p == ls->tail) {
//                 ls->head = NULL;
//                 ls->tail = NULL;
//             }
//             else if (p == ls->head) {
//                 ls->head = ls->head->next;
//                 if (ls->head != NULL)
//                     ls->head->prev = NULL;
//             }
//             else if (p == ls->tail) {
//                 ls->tail = ls->tail->prev;
//                 if (ls->tail != NULL)
//                     ls->tail->next = NULL;
//             }
//             free(p);
//         }
//     }
//     else 
//         printf("Heads empty dawg");
// }
//
// void deletefromhead(list *ls) {
//     while(!isempty(ls))
//         delete(ls, ls->head->key);
// }
//
// void insert(list *ls, int pos, int key) {
//
// }
//
// void printlist(list *ls) { 
//     if (!isempty(ls)) {
//         Node *p = ls->head;
//         while (p != NULL) {
//             printf("%d ", p->key);
//             p = p->next;
//         }
//         printf("\n");
//     }
//     else 
//         printf("List is empty\n");
// }
//
// int length(list *ls) {
//     int n = 0;
//     Node *p = ls->head;
//     while (p != NULL) {
//         p = p->next;
//         n++;
//     }
//     return n;
// }
//
// int main(int argc, char *argv[]) {
//
//     list ls;
//     initlist(&ls);
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//
//     printf("%s\n", (contains(&ls, 3) != NULL) ? "true" : "false");
//     printf("%s\n", (contains(&ls, 5) != NULL) ? "true" : "false");
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     delete(&ls, 1);
//
//     printlist(&ls);    // This doesnt throw a sef fault it works fine 
//
//     delete(&ls, 4);
//     delete(&ls, 2);
//     delete(&ls, 3);
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//     printlist(&ls);  // Why does this line only here cause a segfault?
//
//     printf("List size is %d\n", length(&ls));
//     deletefromhead(&ls);
//     printlist(&ls);
//     return 0;
// }
// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include "node.h"
//
// typedef struct Linked_List {
//     Node *head;
//     Node *tail;
// } list;
//
// void initlist(list *ls) {
//     ls->head = NULL;
//     ls->tail = NULL;
//
//     // ls->head->prev = NULL;
//     // ls->head->next = NULL;
//     // ls->tail->prev = NULL;
//     // ls->tail->next = NULL;
//
// }
//
// bool isempty(list *ls) {
//     return ls->head == NULL && ls->tail == NULL;
// }
//
// Node *contains(list *ls, int key) {
//     Node *p = ls->head;
//     while (p != NULL) {
//         if (p->key == key)
//             return p;
//         p = p->next;
//     }
//     return NULL;
// }
//
// void add(list *ls, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//     p->key = key;
//     p->prev = NULL;
//
//     if (ls->head == NULL) {
//         ls->head = p;
//         ls->head->next = NULL;
//         ls->tail = p;
//     }
//     else {
//         ls->tail->next = p;
//         p->prev = ls->tail;
//         ls->tail = p;
//         ls->tail->next = NULL;
//     }
// }
//
// void delete(list *ls, int key) {
//
//     if (ls->head != NULL) {
//         printf("head %d, tail %d\n", ls->head->key, ls->tail->key);
//         Node *p = contains(ls, key);
//
//         if (p != NULL) {
//
//             if (p != ls->head && p != ls->tail) {
//                 p->next->prev = p->prev;
//                 p->prev->next = p->next;
//             }
//             else if (p == ls->head && p == ls->tail) {
//                 ls->head = NULL;
//                 ls->tail = NULL;
//             }
//             else if (p == ls->head) {
//                 ls->head = ls->head->next;
//                 if (ls->head != NULL)
//                     ls->head->prev = NULL;
//             }
//             else if (p == ls->tail) {
//                 ls->tail = ls->tail->prev;
//                 if (ls->tail != NULL)
//                     ls->tail->next = NULL;
//             }
//             free(p);
//         }
//     }
//     else 
//         printf("Heads empty dawg");
// }
//
// void deletefromhead(list *ls) {
//     while(!isempty(ls))
//         delete(ls, ls->head->key);
// }
//
// void insert(list *ls, int pos, int key) {
//
// }
//
// void printlist(list *ls) { 
//     if (!isempty(ls)) {
//         Node *p = ls->head;
//         while (p != NULL) {
//             printf("%d ", p->key);
//             p = p->next;
//         }
//         printf("\n");
//     }
//     else 
//         printf("List is empty\n");
// }
//
// int length(list *ls) {
//     int n = 0;
//     Node *p = ls->head;
//     while (p != NULL) {
//         p = p->next;
//         n++;
//     }
//     return n;
// }
//
// int main(int argc, char *argv[]) {
//
//     list ls;
//     initlist(&ls);
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//
//     printf("%s\n", (contains(&ls, 3) != NULL) ? "true" : "false");
//     printf("%s\n", (contains(&ls, 5) != NULL) ? "true" : "false");
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     delete(&ls, 1);
//
//     printlist(&ls);    // This doesnt throw a sef fault it works fine 
//
//     delete(&ls, 4);
//     delete(&ls, 2);
//     delete(&ls, 3);
//     printlist(&ls);    // This doesnt throw a seg fault it works fine
//
//     add(&ls, 1);
//     add(&ls, 2);
//     add(&ls, 3);
//     add(&ls, 4);
//     printlist(&ls);  // Why does this line only here cause a segfault?
//
//     printf("List size is %d\n", length(&ls));
//     deletefromhead(&ls);
//     printlist(&ls);
//     return 0;
// }
