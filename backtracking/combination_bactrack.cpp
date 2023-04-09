#include<bits/stdc++.h>

std::vector<std::vector<int>> res;
 
void backtrack(int n, int k, int start, std::vector<int>& track) {
    if (track.size() == k) {
        res.push_back(track);
        return;
    }
    for (int i=start; i <=n; i++) {
        track.push_back(i);
        backtrack(n, k, i+1, track);
        track.pop_back();
    }
}

std::vector<std::vector<int>> combination(int n, int k) {
    if (k<=0 || n<=0) return res;
    std::vector<int> track;
    backtrack(n, k, 1, track);
    return res;
}

int main() {
    int n=4, k=2;
    std::vector<std::vector<int>> result = combination(n, k);
    for (int i=0; i < result.size(); i++){
        for (int j=0; j<result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
} 