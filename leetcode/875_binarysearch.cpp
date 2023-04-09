#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left)/2;
            if (checkK(piles, mid, h)) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        return left;
    }
    bool checkK(vector<int>& piles, int k, int h) {
        int time = 0;
        for (int p : piles) {
            time += p/k;
            if (p%k > 0) time++;
        }
        return (time <= h);
    }
};


int main() {
    // Input: piles = [3,6,7,11], h = 8
    // Output: 4
    // Input: piles = [30,11,23,4,20], h = 5
    // Output: 30
    // Input: piles = [30,11,23,4,20], h = 6
    // Output: 23    
    vector<int> piles = {
        3, 6, 7, 11
    };
    int h = 8;
    Solution* so = new Solution();
    int res = so->minEatingSpeed(piles, h);
    cout << res << endl;
}




// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// 1 <= piles.length <= 10^4
// piles.length <= h <= 10^9
// 1 <= piles[i] <= 10^9