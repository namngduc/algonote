#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        vector<int> visited(N, 0);
        visited[0] = -1;
        queue<int> queue;
        queue.push(0);
        while (!queue.empty()){
            int top = queue.front();
            queue.pop();
            for (int next : rooms[top]) {
                if (visited[next] != -1) {
                    visited[next] = -1;
                    queue.push(next);
                }
            }
        }
        for (int i : visited) {
            // cout << i << " ";
            if (i != -1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Input: rooms = [[1],[2],[3],[]]
    // Output: true
    // Input: rooms = [[1,3],[3,0,1],[2],[0]]
    // Output: false
    vector<vector<int>> rooms = {
        {1}, {2}, {3}, {}
        // {1, 3}, {3, 0, 1}, {2}, {0}
    };
    Solution* so = new Solution();
    bool res = so->canVisitAllRooms(rooms);
    cout << (res == 0 ? "False" : "True") << endl; 
}