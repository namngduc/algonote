#include<bits/stdc++.h>

std::vector<std::vector<int>> subsets(std::vector<int> nums) {
    if (nums.empty()) return {{}};
    int n = nums.back();
    nums.pop_back();
    std::vector<std::vector<int>> res = subsets(nums);
    int size = res.size();
    for (int i=0; i < size; i++) {
        res.push_back(res[i]);
        res.back().push_back(n);
    }
    return res;
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> result = subsets(nums);
    for (int i=0; i < result.size(); i++){
        for (int j=0; j<result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << nums.back() << "\n";
    return 0;
}