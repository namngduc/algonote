#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minVal = INT_MAX;
        for (int n : nums) {
            if (n % 2 == 1) {
                n *= 2;
            }
            pq.push(n);
            minVal = min(minVal, n);
        }
        int minDevi = INT_MAX;
        while (true) {
            int top = pq.top(); pq.pop();
            minDevi = min(minDevi, top - minVal);
            if (top % 2 == 1) {
                break;
            }
            top /= 2;
            minVal = min(minVal, top);
            pq.push(top);
        }
        return minDevi; 
    }
};

int main() {
    vector<int> nums = {    
        4,1,5,20,3
    };
    Solution* so = new Solution();
    int res = so->minimumDeviation(nums);
    cout << res << endl;
}