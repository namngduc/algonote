#include <iostream>

void bubble_sort (int A[], int n) {
    int temp;
    for (int k=0; k < n; k++) {
        for (int i=0; i < n-k-1; i++) {
           if (A[i] > A[i+1]) {
               temp = A[i];
               A[i] = A[i+1];
               A[i+1] = temp;
           } 
        }
    }

}

int main () {
    int A[] = {9, 3, 6, 5, 2, 7, 8, 1};
    std::cout << sizeof(A)/4 << "\n";
    bubble_sort(A, 8);
    for (auto e:A) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}