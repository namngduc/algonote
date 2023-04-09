#include<bits/stdc++.h>

class Solution {
public:
    std::vector<int> mergeSort(std::vector<int>& arr) {
        int lo=0, hi=arr.size()-1;
        sort(arr, lo, hi);
        return arr;
    }
    void sort(std::vector<int>& arr, int lo, int hi) {
        if (lo >= hi) return;
        int mid = lo + (hi-lo)/2;
        sort(arr, lo, mid);
        sort(arr, mid+1, hi);
        merge(arr, lo, mid, hi);
    }

    void merge(std::vector<int>& arr, int lo, int mid, int hi) {
        int i=lo, j=mid+1;
        std::vector<int> aux(hi-lo+1);
        for (int k=lo; k <=hi; k++) {
            aux[k] = arr[k];
        }
        for (int k=lo; k<=hi; k++) {
            if (i > mid) 
                arr[k] = aux[j++];
            else if (j > hi) 
                arr[k] = aux[i++];
            else if (aux[i] < aux[j])
                arr[k] = aux[i++];
            else  
                arr[k] = aux[j++];
        }
    }

};

int main() {
    std::vector<int> arr = {1, 4, 10, 3, 6, 8, 9, 2, 5};
    Solution so;
    std::vector<int> result = so.mergeSort(arr);
    for (int i=0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}