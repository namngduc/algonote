#include <algorithm>
#include <iostream>

void selection_sort(int A[], int n) {
    for (int i=0; i < n-1; i++) {
        int minimum = i;
        for (int j=i+1; j < n; j++) {
            if (A[j] < A[minimum]) {
                minimum = j;
            }
        }
        std::swap(A[minimum], A[i]);
    }
}

int main () {
    int A[] = {9, 3, 6, 5, 2, 7, 8, 1};
    std::cout << sizeof(A)/4 << "\n";
    selection_sort(A, 8);
    for (auto e:A) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}