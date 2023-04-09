#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int ans = 1;
    int longestPath(vector<int>& parent, string s) {
        int N = parent.size();
        vector<vector<int>> graph(N);
        for (int i = 1; i < parent.size(); i++) {
            graph[parent[i]].push_back(i);
        }
        DFS(0, graph, s);
        return ans;
    }

    int DFS(int node, vector<vector<int>>& graph, string& s) {
        int best = 0, second_best = 0;
        for (int child : graph[node]) {
            if (s[node] == s[child]) continue;
            int length = DFS(child, graph, s);
            if (length > best) {
                second_best = best;
                best = length;
            } 
            else if (length > second_best) {
                second_best = length;
            }
        }
        int case1 = 1 + best;
        int case2 = 1 + best + second_best;
        ans = max({ans, case1, case2});
        return case1;
    }
};

int main() {
    // Input: parent = [-1,0,0,1,1,2], s = "abacbe"
    // Output: 3
    // Input: parent = [-1,0,0,0], s = "aabc"
    // Output: 3
    vector<int> parent = {
        // -1, 0, 0, 1, 1, 2
        -1, 0, 0, 0
    };
    // string s = "abacbe";
    string s = "aabc";
    Solution* so = new Solution();
    int res = so->longestPath(parent, s);
    cout << res << endl;
}