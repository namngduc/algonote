#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<pair<int, int>> tmp;
        for (int i = M-1; i >= 0; i--) {
            tmp.push_back({i, 0});
        }
        for (int j = 1; j < N; j++) {
            tmp.push_back({0, j});
        }
        for (auto& p : tmp) {
            int i = p.first, j = p.second;
            int prev = matrix[i][j];
            i+=1;
            j+=1;
            while (checkOk(i, j, M, N)) {
                if (matrix[i][j] != prev) 
                    return false;
                prev = matrix[i][j];
                i+=1;
                j+=1;
            }
        }
        return true;

    }
    bool checkOk(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,1,2,3},
        {9,5,1,2}
    };
    Solution* so = new Solution();
    bool res = so->isToeplitzMatrix(matrix);
    cout << (res == 1 ? "true" : "false") << endl;;
}