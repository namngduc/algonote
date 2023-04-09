#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX;
        for (int n : nums) {
            if (n <= n1) {
                n1 = n;
            }
            else if (n <= n2) {
                n2 = n;
            }
            else 
                return true;
        }
        return false;
    }
};

int main() {
    // vector<int> nums = {
    //     1,2,3,4,5
    // };
    vector<vector<int>> arr = {
        // {1,2,3,4,5},
        // {5,4,3,2,1},
        // {2,1,5,0,4,6},
        {1,2,5,5,4,6},
        {20,100,10,12,13,5},
        {20,100,10,12,5,13},
        {1,5,0,4,1,3},
        {4,5,2147483647,1,2}
    };
    // true
    // [5,4,3,2,1]
    // false
    // [2,1,5,0,4,6]
    // true
    // [2,1,5,5,4,6]
    // true
    // [20,100,10,12,5,13]
    // true
    // [1,5,0,4,1,3]
    // true
    Solution* so = new Solution();
    for (vector<int> num : arr) {
        bool res = so->increasingTriplet(num);
        cout << (res == 1 ? "true" : "false") << endl;
    }
}