#include <iostream>

template<class T>
void merge(T *arr, int p, int q, int r, T MAX_OB) {

    int numLeft = q - p+1;
    int numRight = r - q;
    T *L = new T[numLeft + 1];
    T *R = new T[numRight + 1];

    for (int i = 0; i != numLeft; i++)
        L[i] = arr[p + i];
    for (int j = 0; j != numRight; j++)
        R[j] = arr[q + 1 + j];
    
    L[numLeft] = MAX_OB;
    R[numRight] = MAX_OB;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j])
            arr[k] = L[i], i++;
        else 
            arr[k] = R[j], j++;
    }
    delete[] L, delete[] R;
}

template<class T>
void merge_sort(T *arr, int p, int r, T MAX_OB) {
    if (p < r) {
        int q = (p + r)/2;
        merge_sort(arr, p, q, MAX_OB);
        merge_sort(arr, q + 1, r, MAX_OB);
        merge(arr, p, q, r, MAX_OB);
    }
}

int main() {

    char arr[] = {'v', 'c', 'j', 'e', 'm', 'o'};

    std::cout << arr << "\n";
    merge_sort(arr, 0, 5, 'z');
    std::cout << arr << "\n";


    return 0;
}

















































// #include <iostream>
//
// template<class T>
// void merge(T *arr, int p, int q, int r, T MAX_OB) {
//
//     int numLeft = q - p+1;
//     int numRight = r - q;
//     T *L = new T[numLeft + 1];
//     T *R = new T[numRight + 1];
//
//     for (int i = 0; i != numLeft; i++)
//         L[i] = arr[p + i];
//     for (int j = 0; j != numRight; j++)
//         R[j] = arr[q + 1 + j];
//
//     L[numLeft] = MAX_OB;
//     R[numRight] = MAX_OB;
//
//     int i = 0;
//     int j = 0;
//
//     for (int k = p; k <= r; k++) {
//         if (L[i] <= R[j])
//             arr[k] = L[i], i++;
//         else 
//             arr[k] = R[j], j++;
//     }
//     delete[] L, delete[] R;
// }
//
// template<class T>
// void merge_sort(T *arr, int p, int r, T MAX_OB) {
//     if (p < r) {
//         int q = (p + r)/2;
//         merge_sort(arr, p, q, MAX_OB);
//         merge_sort(arr, q + 1, r, MAX_OB);
//         merge(arr, p, q, r, MAX_OB);
//     }
// }
//
// int main() {
//
//     char arr[] = {'v', 'c', 'j', 'e', 'm', 'o'};
//
//     std::cout << arr << "\n";
//     merge_sort(arr, 0, 5, 'z');
//     std::cout << arr << "\n";
//
//
//     return 0;
// #include <iostream>
//
// template<class T>
// void merge(T *arr, int p, int q, int r, T MAX_OB) {
//
//     int numLeft = q - p+1;
//     int numRight = r - q;
//     T *L = new T[numLeft + 1];
//     T *R = new T[numRight + 1];
//
//     for (int i = 0; i != numLeft; i++)
//         L[i] = arr[p + i];
//     for (int j = 0; j != numRight; j++)
//         R[j] = arr[q + 1 + j];
//
//     L[numLeft] = MAX_OB;
//     R[numRight] = MAX_OB;
//
//     int i = 0;
//     int j = 0;
//
//     for (int k = p; k <= r; k++) {
//         if (L[i] <= R[j])
//             arr[k] = L[i], i++;
//         else 
//             arr[k] = R[j], j++;
//     }
//     delete[] L, delete[] R;
// }
//
// template<class T>
// void merge_sort(T *arr, int p, int r, T MAX_OB) {
//     if (p < r) {
//         int q = (p + r)/2;
//         merge_sort(arr, p, q, MAX_OB);
//         merge_sort(arr, q + 1, r, MAX_OB);
//         merge(arr, p, q, r, MAX_OB);
//     }
// }
//
// int main() {
//
//     char arr[] = {'v', 'c', 'j', 'e', 'm', 'o'};
//
//     std::cout << arr << "\n";
//     merge_sort(arr, 0, 5, 'z');
//     std::cout << arr << "\n";
//
//
//     return 0;
// }
// #include <iostream>
//
// template<class T>
// void merge(T *arr, int p, int q, int r, T MAX_OB) {
//
//     int numLeft = q - p+1;
//     int numRight = r - q;
//     T *L = new T[numLeft + 1];
//     T *R = new T[numRight + 1];
//
//     for (int i = 0; i != numLeft; i++)
//         L[i] = arr[p + i];
//     for (int j = 0; j != numRight; j++)
//         R[j] = arr[q + 1 + j];
//
//     L[numLeft] = MAX_OB;
//     R[numRight] = MAX_OB;
//
//     int i = 0;
//     int j = 0;
//
//     for (int k = p; k <= r; k++) {
//         if (L[i] <= R[j])
//             arr[k] = L[i], i++;
//         else 
//             arr[k] = R[j], j++;
//     }
//     delete[] L, delete[] R;
// }
//
// template<class T>
// void merge_sort(T *arr, int p, int r, T MAX_OB) {
//     if (p < r) {
//         int q = (p + r)/2;
//         merge_sort(arr, p, q, MAX_OB);
//         merge_sort(arr, q + 1, r, MAX_OB);
//         merge(arr, p, q, r, MAX_OB);
//     }
// }
//
// int main() {
//
//     char arr[] = {'v', 'c', 'j', 'e', 'm', 'o'};
//
//     std::cout << arr << "\n";
//     merge_sort(arr, 0, 5, 'z');
//     std::cout << arr << "\n";
//
//
//     return 0;
// }
// }
// #include <iostream>
//
// template<class T>
// void merge(T *arr, int p, int q, int r, T MAX_OB) {
//
//     int numLeft = q - p+1;
//     int numRight = r - q;
//     T *L = new T[numLeft + 1];
//     T *R = new T[numRight + 1];
//
//     for (int i = 0; i != numLeft; i++)
//         L[i] = arr[p + i];
//     for (int j = 0; j != numRight; j++)
//         R[j] = arr[q + 1 + j];
//
//     L[numLeft] = MAX_OB;
//     R[numRight] = MAX_OB;
//
//     int i = 0;
//     int j = 0;
//
//     for (int k = p; k <= r; k++) {
//         if (L[i] <= R[j])
//             arr[k] = L[i], i++;
//         else 
//             arr[k] = R[j], j++;
//     }
//     delete[] L, delete[] R;
// }
//
// template<class T>
// void merge_sort(T *arr, int p, int r, T MAX_OB) {
//     if (p < r) {
//         int q = (p + r)/2;
//         merge_sort(arr, p, q, MAX_OB);
//         merge_sort(arr, q + 1, r, MAX_OB);
//         merge(arr, p, q, r, MAX_OB);
//     }
// }
//
// int main() {
//
//     char arr[] = {'v', 'c', 'j', 'e', 'm', 'o'};
//
//     std::cout << arr << "\n";
//     merge_sort(arr, 0, 5, 'z');
//     std::cout << arr << "\n";
//
//
//     return 0;
// }
// #include <iostream>
//
// template<class T>
// void merge(T *arr, int p, int q, int r, T MAX_OB) {
//
//     int numLeft = q - p+1;
//     int numRight = r - q;
//     T *L = new T[numLeft + 1];
//     T *R = new T[numRight + 1];
//
//     for (int i = 0; i != numLeft; i++)
//         L[i] = arr[p + i];
//     for (int j = 0; j != numRight; j++)
//         R[j] = arr[q + 1 + j];
//
//     L[numLeft] = MAX_OB;
//     R[numRight] = MAX_OB;
//
//     int i = 0;
//     int j = 0;
//
//     for (int k = p; k <= r; k++) {
//         if (L[i] <= R[j])
//             arr[k] = L[i], i++;
//         else 
//             arr[k] = R[j], j++;
//     }
//     delete[] L, delete[] R;
// }
//
// template<class T>
// void merge_sort(T *arr, int p, int r, T MAX_OB) {
//     if (p < r) {
//         int q = (p + r)/2;
//         merge_sort(arr, p, q, MAX_OB);
//         merge_sort(arr, q + 1, r, MAX_OB);
//         merge(arr, p, q, r, MAX_OB);
//     }
// }
//
// int main() {
//
//     char arr[] = {'v', 'c', 'j', 'e', 'm', 'o'};
//
//     std::cout << arr << "\n";
//     merge_sort(arr, 0, 5, 'z');
//     std::cout << arr << "\n";
//
//
//     return 0;
// }
// #include <iostream>
//
// template<class T>
// void merge(T *arr, int p, int q, int r, T MAX_OB) {
//
//     int numLeft = q - p+1;
//     int numRight = r - q;
//     T *L = new T[numLeft + 1];
//     T *R = new T[numRight + 1];
//
//     for (int i = 0; i != numLeft; i++)
//         L[i] = arr[p + i];
//     for (int j = 0; j != numRight; j++)
//         R[j] = arr[q + 1 + j];
//
//     L[numLeft] = MAX_OB;
//     R[numRight] = MAX_OB;
//
//     int i = 0;
//     int j = 0;
//
//     for (int k = p; k <= r; k++) {
//         if (L[i] <= R[j])
//             arr[k] = L[i], i++;
//         else 
//             arr[k] = R[j], j++;
//     }
//     delete[] L, delete[] R;
// }
//
// template<class T>
// void merge_sort(T *arr, int p, int r, T MAX_OB) {
//     if (p < r) {
//         int q = (p + r)/2;
//         merge_sort(arr, p, q, MAX_OB);
//         merge_sort(arr, q + 1, r, MAX_OB);
//         merge(arr, p, q, r, MAX_OB);
//     }
// }
//
// int main() {
//
//     char arr[] = {'v', 'c', 'j', 'e', 'm', 'o'};
//
//     std::cout << arr << "\n";
//     merge_sort(arr, 0, 5, 'z');
//     std::cout << arr << "\n";
//
//
//     return 0;
// }
// #include <iostream>
//
// template<class T>
// void merge(T *arr, int p, int q, int r, T MAX_OB) {
//
//     int numLeft = q - p+1;
//     int numRight = r - q;
//     T *L = new T[numLeft + 1];
//     T *R = new T[numRight + 1];
//
//     for (int i = 0; i != numLeft; i++)
//         L[i] = arr[p + i];
//     for (int j = 0; j != numRight; j++)
//         R[j] = arr[q + 1 + j];
//
//     L[numLeft] = MAX_OB;
//     R[numRight] = MAX_OB;
//
//     int i = 0;
//     int j = 0;
//
//     for (int k = p; k <= r; k++) {
//         if (L[i] <= R[j])
//             arr[k] = L[i], i++;
//         else 
//             arr[k] = R[j], j++;
//     }
//     delete[] L, delete[] R;
// }
//
// template<class T>
// void merge_sort(T *arr, int p, int r, T MAX_OB) {
//     if (p < r) {
//         int q = (p + r)/2;
//         merge_sort(arr, p, q, MAX_OB);
//         merge_sort(arr, q + 1, r, MAX_OB);
//         merge(arr, p, q, r, MAX_OB);
//     }
// }
//
// int main() {
//
//     char arr[] = {'v', 'c', 'j', 'e', 'm', 'o'};
//
//     std::cout << arr << "\n";
//     merge_sort(arr, 0, 5, 'z');
//     std::cout << arr << "\n";
//
//
//     return 0;
// }
// #include <iostream>
//
// template<class T>
// void merge(T *arr, int p, int q, int r, T MAX_OB) {
//
//     int numLeft = q - p+1;
//     int numRight = r - q;
//     T *L = new T[numLeft + 1];
//     T *R = new T[numRight + 1];
//
//     for (int i = 0; i != numLeft; i++)
//         L[i] = arr[p + i];
//     for (int j = 0; j != numRight; j++)
//         R[j] = arr[q + 1 + j];
//
//     L[numLeft] = MAX_OB;
//     R[numRight] = MAX_OB;
//
//     int i = 0;
//     int j = 0;
//
//     for (int k = p; k <= r; k++) {
//         if (L[i] <= R[j])
//             arr[k] = L[i], i++;
//         else 
//             arr[k] = R[j], j++;
//     }
//     delete[] L, delete[] R;
// }
//
// template<class T>
// void merge_sort(T *arr, int p, int r, T MAX_OB) {
//     if (p < r) {
//         int q = (p + r)/2;
//         merge_sort(arr, p, q, MAX_OB);
//         merge_sort(arr, q + 1, r, MAX_OB);
//         merge(arr, p, q, r, MAX_OB);
//     }
// }
//
// int main() {
//
//     char arr[] = {'v', 'c', 'j', 'e', 'm', 'o'};
//
//     std::cout << arr << "\n";
//     merge_sort(arr, 0, 5, 'z');
//     std::cout << arr << "\n";
//
//
//     return 0;
// }
