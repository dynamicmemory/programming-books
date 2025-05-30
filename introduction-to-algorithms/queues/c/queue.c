#include <stdio.h>
#include "node.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    Node *head;
    Node *tail;
} queue;

void init_queue(queue *q) {
    q->head = NULL;
    q->tail = NULL;

}

bool isempty(const queue *q) {
    return q->head == NULL && q->tail == NULL;
}

void enqueue(queue *q, int key) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->next = NULL;

    if (isempty(q)) {
        p->prev = NULL;
        q->head = p;
        q->tail = q->head;
    }
    else {
        q->tail->next = p;
        p->prev = q->tail;
        q->tail = p;
    }
}

void dequeue(queue *q) {
    Node *p = q->head;

    if (!isempty(q)) {
        if (q->head->next != NULL) {
            q->head = q->head->next; 
            q->head->prev = NULL;
        }
        else {
            q->head = NULL;
            q->tail = NULL;
        }
        free(p);
    }
    else {
      printf("Queue is empty\n");
    }
}



bool front(const queue *q, int *value) {

    if (isempty(q)) {
        printf("Queue is empty\n");
        return false;
    }
    *value = q->head->key;
    return true;
}

void print_queue(const queue *q) {
    if (isempty(q))
        printf("Queue is empty\n");
    else {
        Node *p = q->head;
        while (p != NULL) {
            printf("%d ", p->key);
            p = p->next;
        }
        printf("\n");
    }
}

int main() {
    printf("Pre Queue\n");
    queue q;
    printf("Pre init\n");
    init_queue(&q);

    dequeue(&q);
     
    enqueue(&q, 1);

    enqueue(&q, 2);
     
    enqueue(&q, 3);
    int value;
    printf("Front of the queue: %d\n", front(&q, &value));
    enqueue(&q, 4);
    print_queue(&q);

    enqueue(&q, 5);
    print_queue(&q);

    enqueue(&q, 6);
    print_queue(&q);
 

    enqueue(&q, 7);
    print_queue(&q);

    dequeue(&q);
    print_queue(&q);

    dequeue(&q);
    print_queue(&q);
    
    int value2;
    front(&q, &value2);
    printf("Front of the queue: %d\n", value2); 
    dequeue(&q);
    print_queue(&q);

    dequeue(&q);
    print_queue(&q);
    
    dequeue(&q);
    print_queue(&q);

    dequeue(&q);
    print_queue(&q);

    dequeue(&q);
    print_queue(&q);
    
    dequeue(&q);
    print_queue(&q);

    dequeue(&q);
    print_queue(&q);

    int value3;
    printf("Front of the queue: %d\n", value3);
    while (!isempty(&q))
        dequeue(&q);
    return 0;
}





// #include <stdio.h>
// #include "node.h"
// #include <stdlib.h>
// #include <stdbool.h>
//
// typedef struct queue {
//     Node *head;
//     Node *tail;
// } queue;
//
// void init_queue(queue *q) {
//     q->head = NULL;
//     q->tail = NULL;
//
// }
//
// bool isempty(const queue *q) {
//     return q->head == NULL && q->tail == NULL;
// }
//
// void enqueue(queue *q, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//     p->key = key;
//     p->next = NULL;
//
//     if (isempty(q)) {
//         p->prev = NULL;
//         q->head = p;
//         q->tail = q->head;
//     }
//     else {
//         q->tail->next = p;
//         p->prev = q->tail;
//         q->tail = p;
//     }
// }
//
// void dequeue(queue *q) {
//     Node *p = q->head;
//
//     if (!isempty(q)) {
//         if (q->head->next != NULL) {
//             q->head = q->head->next; 
//             q->head->prev = NULL;
//         }
//         else {
//             q->head = NULL;
//             q->tail = NULL;
//         }
//         free(p);
//     }
//     else {
//       printf("Queue is empty\n");
//     }
// }
//
//
//
// bool front(const queue *q, int *value) {
//
//     if (isempty(q)) {
//         printf("Queue is empty\n");
//         return false;
//     }
//     *value = q->head->key;
//     return true;
// }
//
// void print_queue(const queue *q) {
//     if (isempty(q))
//         printf("Queue is empty\n");
//     else {
//         Node *p = q->head;
//         while (p != NULL) {
//             printf("%d ", p->key);
//             p = p->next;
//         }
//         printf("\n");
//     }
// }
//
// int main() {
//     printf("Pre Queue\n");
//     queue q;
//     printf("Pre init\n");
//     init_queue(&q);
//
//     dequeue(&q);
//
//     enqueue(&q, 1);
//
//     enqueue(&q, 2);
//
//     enqueue(&q, 3);
//     int value;
//     printf("Front of the queue: %d\n", front(&q, &value));
//     enqueue(&q, 4);
//     print_queue(&q);
//
//     enqueue(&q, 5);
//     print_queue(&q);
//
//     enqueue(&q, 6);
//     print_queue(&q);
//
//
//     enqueue(&q, 7);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     int value2;
//     front(&q, &value2);
//     printf("Front of the queue: %d\n", value2); 
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     int value3;
//     printf("Front of the queue: %d\n", value3);
//     while (!isempty(&q))
//         dequeue(&q);
//     return 0;
// }



// #include <stdio.h>
// #include "node.h"
// #include <stdlib.h>
// #include <stdbool.h>
//
// typedef struct queue {
//     Node *head;
//     Node *tail;
// } queue;
//
// void init_queue(queue *q) {
//     q->head = NULL;
//     q->tail = NULL;
//
// }
//
// bool isempty(const queue *q) {
//     return q->head == NULL && q->tail == NULL;
// }
//
// void enqueue(queue *q, int key) {
//     Node *p = (Node*)malloc(sizeof(Node));
//     p->key = key;
//     p->next = NULL;
//
//     if (isempty(q)) {
//         p->prev = NULL;
//         q->head = p;
//         q->tail = q->head;
//     }
//     else {
//         q->tail->next = p;
//         p->prev = q->tail;
//         q->tail = p;
//     }
// }
//
// void dequeue(queue *q) {
//     Node *p = q->head;
//
//     if (!isempty(q)) {
//         if (q->head->next != NULL) {
//             q->head = q->head->next; 
//             q->head->prev = NULL;
//         }
//         else {
//             q->head = NULL;
//             q->tail = NULL;
//         }
//         free(p);
//     }
//     else {
//       printf("Queue is empty\n");
//     }
// }
//
//
//
// bool front(const queue *q, int *value) {
//
//     if (isempty(q)) {
//         printf("Queue is empty\n");
//         return false;
//     }
//     *value = q->head->key;
//     return true;
// }
//
// void print_queue(const queue *q) {
//     if (isempty(q))
//         printf("Queue is empty\n");
//     else {
//         Node *p = q->head;
//         while (p != NULL) {
//             printf("%d ", p->key);
//             p = p->next;
//         }
//         printf("\n");
//     }
// }
//
// int main() {
//     printf("Pre Queue\n");
//     queue q;
//     printf("Pre init\n");
//     init_queue(&q);
//
//     dequeue(&q);
//
//     enqueue(&q, 1);
//
//     enqueue(&q, 2);
//
//     enqueue(&q, 3);
//     int value;
//     printf("Front of the queue: %d\n", front(&q, &value));
//     enqueue(&q, 4);
//     print_queue(&q);
//
//     enqueue(&q, 5);
//     print_queue(&q);
//
//     enqueue(&q, 6);
//     print_queue(&q);
//
//
//     enqueue(&q, 7);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     int value2;
//     front(&q, &value2);
//     printf("Front of the queue: %d\n", value2); 
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     dequeue(&q);
//     print_queue(&q);
//
//     int value3;
//     printf("Front of the queue: %d\n", value3);
//     while (!isempty(&q))
//         dequeue(&q);
//     return 0;
// }
