#include<bits/stdc++.h>

std::vector<std::vector<int>> res;
 
void backtrack(std::vector<int>& nums, int start, std::vector<int>& track) {
    res.push_back(track);
    for (int i=start; i < nums.size(); i++) {
        track.push_back(nums[i]);
        backtrack(nums, i+1, track);
        track.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<int> track;
    backtrack(nums, 0, track);
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
}