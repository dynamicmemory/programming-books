#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 1000000

void merge(int *a, int p, int q, int r) {
    
    int lnum = q - p + 1; 
    int rnum = r - q;

    int *L = malloc(sizeof(int) * lnum);
    int *R = malloc(sizeof(int) * rnum);

    for (int i = 0; i < lnum; i++) 
         L[i] = a[p + i];
    for (int j = 0; j < rnum; j++)
        R[j] = a[q + j + 1];

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
        if (i >= lnum)
            a[k] = R[j++];
        else if (j >= rnum)
            a[k] = L[i++];
        else if (L[i] <= R[j])
            a[k] = L[i++];
        else 
            a[k] = R[j++];
    }
    free(L);
    free(R);
}

void merge_sort(int *a, int p, int r) {
    if (p < r) {
        int q =  (p + r)/2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}


int main() {

    int arr[10] = {6,34,8,2,7,9,4,3,1,5};

    for (int i = 0; i < 10; i++)
        printf("%d\n", arr[i]);

    merge_sort(arr, 0, 9);

    for (int i = 0; i < 10; i++)
        printf("%d\n", arr[i]);

    return 0;
}
