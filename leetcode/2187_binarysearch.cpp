#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1, right = 1e14;
        while (left < right) {
            long long mid = left + (right - left)/2;
            if (checkTotal(time, mid) >= totalTrips) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
    long long checkTotal(vector<int>& arr, long long givenTime) {
        long long totalTrips = 0;
        for (int time : arr) {
            totalTrips += givenTime/time;
        }
        return totalTrips;
    }
};

int main() {
    vector<int> time = {
        1, 2, 3
    };
    int totalTrips = 5;
    Solution* so = new Solution();
    long long res = so->minimumTime(time, totalTrips);
    cout << res << endl;
}