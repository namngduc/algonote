#include<bits/stdc++.h>

class Solution {
public:
    std::vector<int> res;
    std::vector<int> pancakesSort(std::vector<int>& cakes) {
        sort(cakes, cakes.size());
        return res;
    }
    void sort(std::vector<int>& cakes, int n) {
        // Base case
        if (n==1) return;
        int maxCake=0, maxIndexcake=0;
        for (int i=0; i < n; i++) {
            if(cakes[i] > maxCake) {
                maxIndexcake = i;
                maxCake = cakes[i];
            }
        }
        reversed(cakes, 0, maxIndexcake);
        res.push_back(maxIndexcake+1);
        reversed(cakes, 0, n-1);
        res.push_back(n);
        sort(cakes, n-1);
    }
    void reversed(std::vector<int>& arr, int i, int j) {
        while (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        }
    }
};

int main() {
    std::vector<int> cakes = {3, 2, 4, 1};
    Solution so;
    std::vector<int> result = so.pancakesSort(cakes);
    for (int i=0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
