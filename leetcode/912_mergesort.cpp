#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        mergeSort(nums, l, r);
        return nums; 

    }
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> left_haft(mid - left + 1);
        vector<int> right_haft(right - mid);
        
        for (int i = 0; i < left_haft.size(); i++) {
            left_haft[i] = arr[left+i];
        }
        for (int i = 0; i < right_haft.size(); i++) {
            right_haft[i] = arr[mid+1+i];
        }
        int i = 0, j = 0, k = left;
        while (i < left_haft.size() && j < right_haft.size()) {
            if (left_haft[i] < right_haft[j]) {
                arr[k++] = left_haft[i++];
            }
            else {
                arr[k++] = right_haft[j++];
            }
        }
        while (i < left_haft.size()) {
            arr[k++] = left_haft[i++];
        }
        while (j < right_haft.size()) {
            arr[k++] = right_haft[j++];
        }
    }
};

int main() {
    vector<int> nums = {
        5, 2, 3, 1, 0
    };
    Solution* so = new Solution();
    vector<int> res = so->sortArray(nums);
    for (int n : res) cout << n << endl;

}