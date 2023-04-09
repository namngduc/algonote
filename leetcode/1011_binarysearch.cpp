#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        for (int w : weights) right+=w;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (checkWeight(weights, mid, days)) {
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return left;
    }

    bool checkWeight(vector<int>& weights, int cap, int D) {
        int total = 0, day = 1;
        for (int w : weights) {
            total += w;
            if (total > cap) {
                day += 1;
                total = w;
            }
        }
        if (day > D) return false;
        return true;
    }
};


int main() {
// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
    vector<int> weights = {
        1,2,3,4,5,6,7,8,9,10
    };
    int days = 5;
    Solution* so = new Solution();
    int res = so->shipWithinDays(weights, days);
    cout << res << endl;
}