#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
       int cntMax = 0;
       int sum = 0;
       int i = 0;
       while (i < colors.length()) {
            int j = i;
            int max = neededTime[j];
            while (colors[j] == colors[i]) {
                if (neededTime[j] > max) max = neededTime[j];
                sum += neededTime[j];
                j++;
            }
            i = j;
            cntMax += max;
       }
       int res = sum - cntMax;
       return res; 
    }
};

int main() {
    // colors = "abc", neededTime = [1,2,3]
    // colors = "aabaa", neededTime = [1,2,3,4,1]
    string colors = "aabaa";
    vector<int> needtimes = {
        1,2,3,4,1
    };
    // Expected 26
    Solution so;
    int res = so.minCost(colors, needtimes);
    cout << res;
}