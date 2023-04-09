#include<bits/stdc++.h>

std::vector<std::vector<int>> res;
 
void backtrack(std::vector<int>& nums, std::vector<int>& track) {
    if (track.size() == nums.size()) {
        res.push_back(track);
        return;
    }
    for (int i=0; i < nums.size(); i++) {
        if (std::find(track.begin(), track.end(), nums[i]) != track.end())
            continue;
        track.push_back(nums[i]);
        backtrack(nums, track);
        track.pop_back();
    }
}

std::vector<std::vector<int>> permutation(std::vector<int>& nums) {
    std::vector<int> track;
    backtrack(nums, track);
    return res;
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> result = permutation(nums);
    for (int i=0; i < result.size(); i++){
        for (int j=0; j<result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
}