#include <stdio.h>

int partition(int *arr, int p, int r) {

    int i = p - 1; 
    int temp;
    int x = arr[r];

    for (int j = p; j != r; j++) {
        if (arr[j] <= x) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[r];
    arr[r] = arr[i + 1];
    arr[i + 1] = temp;
    return i + 1;
}

void quicksort(int *arr, int p, int r) {

    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

int main(int argc, char *argv[]) {

    int arr[] = {9,3,6,1,0,2,4,3,7,5};

    for (int i = 0; i < 10; i++) 
        printf("%d ", arr[i]);
    printf("\n");

    quicksort(arr, 0, 9);

    for (int i = 0; i < 10; i++) 
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
