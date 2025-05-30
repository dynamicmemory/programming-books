#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"

typedef struct bst {
    Node *root;
} bst;

void init_bst(bst *tree) {
    tree->root = NULL;
}

bool is_empty(bst *tree) {
    return tree->root == NULL;
}

Node *minimum(Node *p) {
    // Node *p = tree->root;

    while (p->left != NULL)
        p = p->left;
    return p;
}

Node *maximum(Node *p) {
    // Node *p = tree->root;

    while (p->right != NULL)
        p = p->right;
    return p;
}

Node *search(bst *tree, int key) {
    Node *p = tree->root;
    while (p != NULL && p->key != key)
        if (key < p->key)
            p = p->left;
        else 
            p = p->right;

    return p;
}

void transplant(bst *tree, Node *p, Node *q) {
    if (p->parent == NULL)
        tree->root = q;
    else if (p == p->parent->left)
        p->parent->left = q;
    else 
        p->parent->right = q;

    if (q != NULL)
        q->parent = p->parent;
}

void delete(bst *tree, int key) {
    Node *p = search(tree, key);
    if (p == NULL)
        return;

    if (p->left == NULL)
        transplant(tree, p, p->right);
    else if (p->right == NULL)
        transplant(tree, p, p->left);
    else {
        Node *q = minimum(p->right);
        if (q != p->right) {
            transplant(tree, q, q->right);
            q->right = p->right;
            q->right->parent = q;
        }
        transplant(tree, p, q);
        q->left = p->left;
        q->left->parent = q;
    }
    free(p);
}

void walk_tree_helper(bst *tree, Node *p) {
    if (p != NULL) {
        walk_tree_helper(tree, p->left);
        printf("%d ", p->key);
        walk_tree_helper(tree, p->right);
    }
}

void walk_tree(bst *tree) {
    walk_tree_helper(tree, tree->root); 
    printf("\n");
}

void insert_helper(Node *q, Node *p) {

    while (q != NULL)
        if (p->key < q->key) {
            if (q->left == NULL)
                break;
            q = q->left;
        }
        else {
            if (q->right == NULL)
                break;
            q = q->right;
        }

    if (p->key < q->key) {
        q->left = p;
        p->parent = q;
    }
    else if (p->key > q->key) {
        q->right = p;
        p->parent = q;
    }
    else 
        free(p);
}        

void insert(bst *tree, int key) {
    Node *p = (Node*)malloc(sizeof(Node));

    p->key = key;
    p->left = NULL;
    p->right = NULL;

    if (is_empty(tree)) 
        tree->root = p;
    else {
        Node *q = tree->root;
        insert_helper(q, p);
    }
}

int main() {
    
    bst tree;
    init_bst(&tree);
    
    insert(&tree, 5);
    insert(&tree, 9);
    insert(&tree, 1);
    insert(&tree, 4);
    insert(&tree, 2);
    insert(&tree, 7);
    insert(&tree, 8);
    insert(&tree, 3);
    insert(&tree, 6);
    
    walk_tree(&tree);    

    printf("Tree min = %d\n", minimum(tree.root)->key);
    printf("Tree max = %d\n", maximum(tree.root)->key);

    delete(&tree, 7);

    walk_tree(&tree);    
    return 0;
}





// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "node.h"
//
// typedef struct bst {
//     Node *root;
// } bst;
//
// void init_bst(bst *tree) {
//     tree->root = NULL;
// }
//
// bool is_empty(bst *tree) {
//     return tree->root == NULL;
// }
//
// void walk_tree_helper(bst *tree, Node *p) {
//     if (p != NULL) {
//         walk_tree_helper(tree, p->left);
//         printf("%d ", p->key);
//         walk_tree_helper(tree, p->right);
//     }
// }
//
// void walk_tree(bst *tree) {
//     walk_tree_helper(tree, tree->root); 
//     printf("\n");
// }
//
// void insert_helper(Node *q, Node *p) {
//
//     while (q != NULL)
//         if (p->key < q->key) {
//             if (q->left == NULL)
//                 break;
//             q = q->left;
//         }
//         else {
//             if (q->right == NULL)
//                 break;
//             q = q->right;
//         }
//
//     if (p->key < q->key) {
//         q->left = p;
//         p->parent = q;
//     }
//     else if (p->key > q->key) {
//         q->right = p;
//         p->parent = q;
//     }
//     else 
//         free(p);
// }        
//
// void insert(bst *tree, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//
//     p->key = key;
//     p->left = NULL;
//     p->right = NULL;
//
//     if (is_empty(tree)) 
//         tree->root = p;
//     else {
//         Node *q = tree->root;
//         insert_helper(q, p);
//     }
// }
//
//
//
// int main() {
//
//     bst tree;
//     init_bst(&tree);
//
//     insert(&tree, 5);
//     insert(&tree, 9);
//     insert(&tree, 1);
//     insert(&tree, 4);
//     insert(&tree, 2);
//     insert(&tree, 7);
//     insert(&tree, 8);
//     insert(&tree, 3);
//     insert(&tree, 6);
//
//     walk_tree(&tree);    
//     return 0;
// }






// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "node.h"
//
// typedef struct bst {
//     Node *root;
// } bst;
//
// void init_bst(bst *tree) {
//     tree->root = NULL;
// }
//
// bool is_empty(bst *tree) {
//     return tree->root == NULL;
// }
//
// void walk_tree_helper(bst *tree, Node *p) {
//     if (p != NULL) {
//         walk_tree_helper(tree, p->left);
//         printf("%d ", p->key);
//         walk_tree_helper(tree, p->right);
//     }
// }
//
// void walk_tree(bst *tree) {
//     walk_tree_helper(tree, tree->root); 
//     printf("\n");
// }
//
// void insert_helper(Node *q, Node *p) {
//
//     while (q != NULL)
//         if (p->key < q->key) {
//             if (q->left == NULL)
//                 break;
//             q = q->left;
//         }
//         else {
//             if (q->right == NULL)
//                 break;
//             q = q->right;
//         }
//
//     if (p->key < q->key) {
//         q->left = p;
//         p->parent = q;
//     }
//     else if (p->key > q->key) {
//         q->right = p;
//         p->parent = q;
//     }
//     else 
//         free(p);
// }        
//
// void insert(bst *tree, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//
//     p->key = key;
//     p->left = NULL;
//     p->right = NULL;
//
//     if (is_empty(tree)) 
//         tree->root = p;
//     else {
//         Node *q = tree->root;
//         insert_helper(q, p);
//     }
// }
//
//
//
// int main() {
//
//     bst tree;
//     init_bst(&tree);
//
//     insert(&tree, 5);
//     insert(&tree, 9);
//     insert(&tree, 1);
//     insert(&tree, 4);
//     insert(&tree, 2);
//     insert(&tree, 7);
//     insert(&tree, 8);
//     insert(&tree, 3);
//     insert(&tree, 6);
//
//     walk_tree(&tree);    
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "node.h"
//
// typedef struct bst {
//     Node *root;
// } bst;
//
// void init_bst(bst *tree) {
//     tree->root = NULL;
// }
//
// bool is_empty(bst *tree) {
//     return tree->root == NULL;
// }
//
// void walk_tree_helper(bst *tree, Node *p) {
//     if (p != NULL) {
//         walk_tree_helper(tree, p->left);
//         printf("%d ", p->key);
//         walk_tree_helper(tree, p->right);
//     }
// }
//
// void walk_tree(bst *tree) {
//     walk_tree_helper(tree, tree->root); 
//     printf("\n");
// }
//
// void insert_helper(Node *q, Node *p) {
//
//     while (q != NULL)
//         if (p->key < q->key) {
//             if (q->left == NULL)
//                 break;
//             q = q->left;
//         }
//         else {
//             if (q->right == NULL)
//                 break;
//             q = q->right;
//         }
//
//     if (p->key < q->key) {
//         q->left = p;
//         p->parent = q;
//     }
//     else if (p->key > q->key) {
//         q->right = p;
//         p->parent = q;
//     }
//     else 
//         free(p);
// }        
//
// void insert(bst *tree, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//
//     p->key = key;
//     p->left = NULL;
//     p->right = NULL;
//
//     if (is_empty(tree)) 
//         tree->root = p;
//     else {
//         Node *q = tree->root;
//         insert_helper(q, p);
//     }
// }
//
//
//
// int main() {
//
//     bst tree;
//     init_bst(&tree);
//
//     insert(&tree, 5);
//     insert(&tree, 9);
//     insert(&tree, 1);
//     insert(&tree, 4);
//     insert(&tree, 2);
//     insert(&tree, 7);
//     insert(&tree, 8);
//     insert(&tree, 3);
//     insert(&tree, 6);
//
//     walk_tree(&tree);    
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "node.h"
//
// typedef struct bst {
//     Node *root;
// } bst;
//
// void init_bst(bst *tree) {
//     tree->root = NULL;
// }
//
// bool is_empty(bst *tree) {
//     return tree->root == NULL;
// }
//
// void walk_tree_helper(bst *tree, Node *p) {
//     if (p != NULL) {
//         walk_tree_helper(tree, p->left);
//         printf("%d ", p->key);
//         walk_tree_helper(tree, p->right);
//     }
// }
//
// void walk_tree(bst *tree) {
//     walk_tree_helper(tree, tree->root); 
//     printf("\n");
// }
//
// void insert_helper(Node *q, Node *p) {
//
//     while (q != NULL)
//         if (p->key < q->key) {
//             if (q->left == NULL)
//                 break;
//             q = q->left;
//         }
//         else {
//             if (q->right == NULL)
//                 break;
//             q = q->right;
//         }
//
//     if (p->key < q->key) {
//         q->left = p;
//         p->parent = q;
//     }
//     else if (p->key > q->key) {
//         q->right = p;
//         p->parent = q;
//     }
//     else 
//         free(p);
// }        
//
// void insert(bst *tree, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//
//     p->key = key;
//     p->left = NULL;
//     p->right = NULL;
//
//     if (is_empty(tree)) 
//         tree->root = p;
//     else {
//         Node *q = tree->root;
//         insert_helper(q, p);
//     }
// }
//
//
//
// int main() {
//
//     bst tree;
//     init_bst(&tree);
//
//     insert(&tree, 5);
//     insert(&tree, 9);
//     insert(&tree, 1);
//     insert(&tree, 4);
//     insert(&tree, 2);
//     insert(&tree, 7);
//     insert(&tree, 8);
//     insert(&tree, 3);
//     insert(&tree, 6);
//
//     walk_tree(&tree);    
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "node.h"
//
// typedef struct bst {
//     Node *root;
// } bst;
//
// void init_bst(bst *tree) {
//     tree->root = NULL;
// }
//
// bool is_empty(bst *tree) {
//     return tree->root == NULL;
// }
//
// void walk_tree_helper(bst *tree, Node *p) {
//     if (p != NULL) {
//         walk_tree_helper(tree, p->left);
//         printf("%d ", p->key);
//         walk_tree_helper(tree, p->right);
//     }
// }
//
// void walk_tree(bst *tree) {
//     walk_tree_helper(tree, tree->root); 
//     printf("\n");
// }
//
// void insert_helper(Node *q, Node *p) {
//
//     while (q != NULL)
//         if (p->key < q->key) {
//             if (q->left == NULL)
//                 break;
//             q = q->left;
//         }
//         else {
//             if (q->right == NULL)
//                 break;
//             q = q->right;
//         }
//
//     if (p->key < q->key) {
//         q->left = p;
//         p->parent = q;
//     }
//     else if (p->key > q->key) {
//         q->right = p;
//         p->parent = q;
//     }
//     else 
//         free(p);
// }        
//
// void insert(bst *tree, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//
//     p->key = key;
//     p->left = NULL;
//     p->right = NULL;
//
//     if (is_empty(tree)) 
//         tree->root = p;
//     else {
//         Node *q = tree->root;
//         insert_helper(q, p);
//     }
// }
//
//
//
// int main() {
//
//     bst tree;
//     init_bst(&tree);
//
//     insert(&tree, 5);
//     insert(&tree, 9);
//     insert(&tree, 1);
//     insert(&tree, 4);
//     insert(&tree, 2);
//     insert(&tree, 7);
//     insert(&tree, 8);
//     insert(&tree, 3);
//     insert(&tree, 6);
//
//     walk_tree(&tree);    
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "node.h"
//
// typedef struct bst {
//     Node *root;
// } bst;
//
// void init_bst(bst *tree) {
//     tree->root = NULL;
// }
//
// bool is_empty(bst *tree) {
//     return tree->root == NULL;
// }
//
// void walk_tree_helper(bst *tree, Node *p) {
//     if (p != NULL) {
//         walk_tree_helper(tree, p->left);
//         printf("%d ", p->key);
//         walk_tree_helper(tree, p->right);
//     }
// }
//
// void walk_tree(bst *tree) {
//     walk_tree_helper(tree, tree->root); 
//     printf("\n");
// }
//
// void insert_helper(Node *q, Node *p) {
//
//     while (q != NULL)
//         if (p->key < q->key) {
//             if (q->left == NULL)
//                 break;
//             q = q->left;
//         }
//         else {
//             if (q->right == NULL)
//                 break;
//             q = q->right;
//         }
//
//     if (p->key < q->key) {
//         q->left = p;
//         p->parent = q;
//     }
//     else if (p->key > q->key) {
//         q->right = p;
//         p->parent = q;
//     }
//     else 
//         free(p);
// }        
//
// void insert(bst *tree, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//
//     p->key = key;
//     p->left = NULL;
//     p->right = NULL;
//
//     if (is_empty(tree)) 
//         tree->root = p;
//     else {
//         Node *q = tree->root;
//         insert_helper(q, p);
//     }
// }
//
//
//
// int main() {
//
//     bst tree;
//     init_bst(&tree);
//
//     insert(&tree, 5);
//     insert(&tree, 9);
//     insert(&tree, 1);
//     insert(&tree, 4);
//     insert(&tree, 2);
//     insert(&tree, 7);
//     insert(&tree, 8);
//     insert(&tree, 3);
//     insert(&tree, 6);
//
//     walk_tree(&tree);    
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "node.h"
//
// typedef struct bst {
//     Node *root;
// } bst;
//
// void init_bst(bst *tree) {
//     tree->root = NULL;
// }
//
// bool is_empty(bst *tree) {
//     return tree->root == NULL;
// }
//
// void walk_tree_helper(bst *tree, Node *p) {
//     if (p != NULL) {
//         walk_tree_helper(tree, p->left);
//         printf("%d ", p->key);
//         walk_tree_helper(tree, p->right);
//     }
// }
//
// void walk_tree(bst *tree) {
//     walk_tree_helper(tree, tree->root); 
//     printf("\n");
// }
//
// void insert_helper(Node *q, Node *p) {
//
//     while (q != NULL)
//         if (p->key < q->key) {
//             if (q->left == NULL)
//                 break;
//             q = q->left;
//         }
//         else {
//             if (q->right == NULL)
//                 break;
//             q = q->right;
//         }
//
//     if (p->key < q->key) {
//         q->left = p;
//         p->parent = q;
//     }
//     else if (p->key > q->key) {
//         q->right = p;
//         p->parent = q;
//     }
//     else 
//         free(p);
// }        
//
// void insert(bst *tree, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//
//     p->key = key;
//     p->left = NULL;
//     p->right = NULL;
//
//     if (is_empty(tree)) 
//         tree->root = p;
//     else {
//         Node *q = tree->root;
//         insert_helper(q, p);
//     }
// }
//
//
//
// int main() {
//
//     bst tree;
//     init_bst(&tree);
//
//     insert(&tree, 5);
//     insert(&tree, 9);
//     insert(&tree, 1);
//     insert(&tree, 4);
//     insert(&tree, 2);
//     insert(&tree, 7);
//     insert(&tree, 8);
//     insert(&tree, 3);
//     insert(&tree, 6);
//
//     walk_tree(&tree);    
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "node.h"
//
// typedef struct bst {
//     Node *root;
// } bst;
//
// void init_bst(bst *tree) {
//     tree->root = NULL;
// }
//
// bool is_empty(bst *tree) {
//     return tree->root == NULL;
// }
//
// void walk_tree_helper(bst *tree, Node *p) {
//     if (p != NULL) {
//         walk_tree_helper(tree, p->left);
//         printf("%d ", p->key);
//         walk_tree_helper(tree, p->right);
//     }
// }
//
// void walk_tree(bst *tree) {
//     walk_tree_helper(tree, tree->root); 
//     printf("\n");
// }
//
// void insert_helper(Node *q, Node *p) {
//
//     while (q != NULL)
//         if (p->key < q->key) {
//             if (q->left == NULL)
//                 break;
//             q = q->left;
//         }
//         else {
//             if (q->right == NULL)
//                 break;
//             q = q->right;
//         }
//
//     if (p->key < q->key) {
//         q->left = p;
//         p->parent = q;
//     }
//     else if (p->key > q->key) {
//         q->right = p;
//         p->parent = q;
//     }
//     else 
//         free(p);
// }        
//
// void insert(bst *tree, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//
//     p->key = key;
//     p->left = NULL;
//     p->right = NULL;
//
//     if (is_empty(tree)) 
//         tree->root = p;
//     else {
//         Node *q = tree->root;
//         insert_helper(q, p);
//     }
// }
//
//
//
// int main() {
//
//     bst tree;
//     init_bst(&tree);
//
//     insert(&tree, 5);
//     insert(&tree, 9);
//     insert(&tree, 1);
//     insert(&tree, 4);
//     insert(&tree, 2);
//     insert(&tree, 7);
//     insert(&tree, 8);
//     insert(&tree, 3);
//     insert(&tree, 6);
//
//     walk_tree(&tree);    
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "node.h"
//
// typedef struct bst {
//     Node *root;
// } bst;
//
// void init_bst(bst *tree) {
//     tree->root = NULL;
// }
//
// bool is_empty(bst *tree) {
//     return tree->root == NULL;
// }
//
// void walk_tree_helper(bst *tree, Node *p) {
//     if (p != NULL) {
//         walk_tree_helper(tree, p->left);
//         printf("%d ", p->key);
//         walk_tree_helper(tree, p->right);
//     }
// }
//
// void walk_tree(bst *tree) {
//     walk_tree_helper(tree, tree->root); 
//     printf("\n");
// }
//
// void insert_helper(Node *q, Node *p) {
//
//     while (q != NULL)
//         if (p->key < q->key) {
//             if (q->left == NULL)
//                 break;
//             q = q->left;
//         }
//         else {
//             if (q->right == NULL)
//                 break;
//             q = q->right;
//         }
//
//     if (p->key < q->key) {
//         q->left = p;
//         p->parent = q;
//     }
//     else if (p->key > q->key) {
//         q->right = p;
//         p->parent = q;
//     }
//     else 
//         free(p);
// }        
//
// void insert(bst *tree, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//
//     p->key = key;
//     p->left = NULL;
//     p->right = NULL;
//
//     if (is_empty(tree)) 
//         tree->root = p;
//     else {
//         Node *q = tree->root;
//         insert_helper(q, p);
//     }
// }
//
//
//
// int main() {
//
//     bst tree;
//     init_bst(&tree);
//
//     insert(&tree, 5);
//     insert(&tree, 9);
//     insert(&tree, 1);
//     insert(&tree, 4);
//     insert(&tree, 2);
//     insert(&tree, 7);
//     insert(&tree, 8);
//     insert(&tree, 3);
//     insert(&tree, 6);
//
//     walk_tree(&tree);    
//     return 0;
// }
