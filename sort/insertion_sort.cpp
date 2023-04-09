#include <iostream>

void insertion_sort(int A[], int n) {
    for (int i=0; i < n; i++) {
        int temp = A[i];
        int j = i;
        while (j>0 && temp < A[j-1]) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = temp;
    }
}

int main() {
    int A[] = {9, 3, 6, 5, 2, 7, 8, 1};
    std::cout << sizeof(A)/4 << "\n";
    insertion_sort(A, 8);
    for (auto e:A) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}