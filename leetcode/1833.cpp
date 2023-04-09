#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (int cost : costs) {
            if (coins >= cost) { 
                coins -= cost;
                res++;
            }
            else {
                break;
            }
        }
        return res;
    }
};

int main() {
    // Input: costs = [1,3,2,4,1], coins = 7
    // Output: 4
    // Input: costs = [10,6,8,7,7,8], coins = 5
    // Output: 0
    // Input: costs = [1,6,3,1,2,5], coins = 20
    // Output: 6
    vector<int> costs = {
        // 1, 3, 2, 4, 1
        // 10, 6, 8, 7, 7, 8
        1, 6, 3, 1, 2, 5
    };
    int coins = 20;
    Solution* so = new Solution();
    int res = so->maxIceCream(costs, coins);
    cout << res << endl;

}