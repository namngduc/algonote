#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m[100005] = {};
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int left = 0;
        int right = chargeTimes.size();

        while (left <= right) {
            int mid = left + (right - left)/2;
            if (checkBudget(mid, chargeTimes, runningCosts, budget)) {
                left = mid+1;
            } 
            else {
                right = mid-1;
            }
        }
        return left-1;

    }
    bool checkBudget(int k, vector<int>& charge, vector<int> costs, long long budget) {
        if (k == 0) return true;
        int N = costs.size();
        long long runCost = 0;
        fill(m, m + 100005, 0);
        priority_queue<int> q;
        for (int i = 0; i < k; i++) {
            runCost += costs[i];
            q.push(charge[i]);
            m[charge[i]]++;
        }
        if (q.top() + k * runCost <= budget) return true;
        for (int i = k; i < N; i++) {
            q.push(charge[i]);
            m[charge[i]]++;
            m[charge[i-k]]--;
            runCost = runCost + costs[i] - costs[i-k];
            while (!q.empty() && m[q.top()] == 0) q.pop();
            if (q.top() + k * runCost <= budget) return true;
        }
        return false;

    }
};

int main() {
    vector<int> chargeTimes = {3,6,1,3,4};
    vector<int> runningCosts = {2,1,3,4,5};
    long long budget = 25;
    Solution solution;
    int res = solution.maximumRobots(chargeTimes, runningCosts, budget);
    cout << res << "\n";
}
