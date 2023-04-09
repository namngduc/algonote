#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int res = 0;
        for (int p : piles) {
            pq.push(p);
            res += p;
        }
        while (k > 0 && !pq.empty()) {
            int top = pq.top();
            pq.pop();
            pq.push(top - top/2);
            res -= top/2;
            k--;
        }
        return res;
    }
};

int main() {
    // Input: piles = [5,4,9], k = 2
    // Output: 12
    // Input: piles = [4,3,6,7], k = 3
    // Output: 12
    vector<int> piles = {
        // 5, 4, 9
        4, 3, 6, 7
    };
    int k = 3;
    Solution* so = new Solution();
    int res = so->minStoneSum(piles, k);
    cout << res << endl;
}