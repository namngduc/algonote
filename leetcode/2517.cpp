#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int N = price.size();
        int lo = 0, hi = price[N-1] - price[0];
        int res = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (check(mid, price, k)) {
                res = mid;
                lo = mid+1;
            } 
            else hi = mid-1;
        }
        return res;
    }

    bool check(int x, vector<int>& price, int k) {
        int last = price[0], count = 1, i = 1;
        while (count < k && i < price.size()) {
            if (price[i] - last >= x) {
                last = price[i];
                count++;
            }
            i++;
        }
        return count == k;
    }
};

int main() {
    // Input: price = [13,5,1,8,21,2], k = 3
    // Output: 8
    // Input: price = [1,3,1], k = 2
    // Output: 2
    // For some x, we can use a greedy strategy to check if it is possible to pick k distinct candies with tastiness being at least x.
    // Sort prices and iterate from left to right. For some price[i] check if the price difference between the last taken candy and price[i] is at least x.
    // If so, add the candy i to the basket.
    // So, a candy basket with tastiness x can be achieved if the basket size is bigger than or equal to k.
    vector<int> price = {
        // 13, 5, 1, 8, 21, 2
        1, 3, 1
    };
    int k = 2;
    Solution* so = new Solution();
    int res = so->maximumTastiness(price, k);
    cout << res << endl;
}