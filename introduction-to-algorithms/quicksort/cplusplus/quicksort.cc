#include <iostream>

template<class T>
int partition(T *arr, int p, int r) {
    T x = arr[r];
    int i = p - 1;

    int temp = 0;
    for (int j = p; j != r; j++) {
        if (arr[j] < x) {
            i = i + 1;

            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    temp = arr[r];
    arr[r] = arr[i + 1];
    arr[i + 1] = temp;

    return i + 1;
}

template<class T>
void quicksort(T *arr, int p, int r) {
    if (p < r) {
    int q = partition(arr, p, r);
    quicksort(arr, p, q - 1);
    quicksort(arr, q + 1, r);
    }
}

int main() {

    int arr[] = {8,4,1,6,9,0,2,7,3,5};

    for (int i = 0; i < 10; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
    quicksort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
        std::cout << arr[i] << " ";

    std::cout << "\n";
    return 0;
}
