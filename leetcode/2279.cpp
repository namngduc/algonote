#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int N = rocks.size();
        for (int i = 0; i < N; i++) {
            int add = capacity[i] - rocks[i];
            rocks[i] = add;
        }
        sort(rocks.begin(), rocks.end());
        int res = 0;
        for (int i = 0; i < N && additionalRocks - rocks[i] >= 0; i++) {
            res++;
            additionalRocks -= rocks[i];
        }
        return res; 
    }
};

int main() {
    // Input: capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
    // Output: 3
    // Input: capacity = [10,2,2], rocks = [2,2,0], additionalRocks = 100
    // Output: 3
    vector<int> capacity = {
        2, 3, 4, 5
        // 10, 2, 2
        // 91, 54, 63, 99, 24, 45, 78
    };
    vector<int> rocks = {
        1, 2, 4, 4
        // 2, 2, 0
        // 35, 32, 45, 98, 6, 1, 25
    };
    int addRocks = 2;
    Solution* so = new Solution();
    int res = so->maximumBags(capacity, rocks, addRocks);
    cout << res << endl;

}