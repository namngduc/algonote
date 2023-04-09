#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int N = tasks.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < N; i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        vector<int> res;
        long long curr_time = tasks[0][0];
        int i = 0;
        while (res.size() < tasks.size()) {
            while (i < tasks.size() && tasks[i][0] <= curr_time) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            if (pq.size()) {
                vector<int> top = pq.top();
                pq.pop();
                curr_time += top[0];
                res.push_back(top[1]);
            }
            else {
                curr_time = tasks[i][0];
            } 
        } 
        return res;
    }
};

int main() {
// To simulate the problem we first need to note that 
// if at any point in time there are no enqueued tasks we need to wait to the smallest enqueue time of a non-processed element
// Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
// Output: [0,2,3,1]
// Explanation: The events go as follows: 
// - At time = 1, task 0 is available to process. Available tasks = {0}.
// - Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
// - At time = 2, task 1 is available to process. Available tasks = {1}.
// - At time = 3, task 2 is available to process. Available tasks = {1, 2}.
// - Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
// - At time = 4, task 3 is available to process. Available tasks = {1, 3}.
// - At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
// - At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
// - At time = 10, the CPU finishes task 1 and becomes idle
// Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
// Output: [4,3,2,0,1]
    vector<vector<int>> tasks = {
        {1, 2}, {2, 4}, {3, 2}, {4, 1}
    };
    Solution* so = new Solution();
    vector<int> res = so->getOrder(tasks);
    for (int n : res) cout << n << " ";
    cout << "\n";
}