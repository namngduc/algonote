#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool checkValid(int i, int j, int M, int N) {
    return (i >= 0 && j >= 0 && i < M && j < N);
}

void BFS(vector<vector<char>>& matrix, int i, int j) {
    int M = matrix.size();
    int N = matrix[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int m = q.front().first;
            int n = q.front().second;
            q.pop();
            for (int idx = 0; idx < 4; idx++) {
                int x = m + dirs[idx][0];
                int y = n + dirs[idx][1];
                if (checkValid(x, y, M, N)) {
                    if (matrix[x][y] == 'G'){
                        int cnt = 0; 
                        for (int z = 0; z < 4; z++) {
                            int l = x + dirs[z][0];
                            int k = y + dirs[z][1];
                            if (checkValid(l, k, M, N) && matrix[l][k] == 'G') cnt++;
                        }
                        if (cnt < 2) {
                            matrix[x][y] = 'B';
                            q.push({x, y});
                        }
                    }
                }
            }
        }
    }
}

void makeBad(vector<vector<char>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 'G') {
                int cnt = 0;
                for (int idx=0; idx < 4; idx++) {
                    int x = i + dirs[idx][0];
                    int y = j + dirs[idx][1];
                    if (checkValid(x, y, matrix.size(), matrix[0].size())) {
                        if (matrix[x][y] == 'G') {
                            cnt++;
                        }
                    }
                }
                if (cnt < 2) {
                    matrix[i][j] = 'B';
                }
            }
        }
    }
}
void solution(vector<vector<char>>& matrix, int c) {
    int M = matrix.size(), N = matrix[0].size();
    bool flag = true;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == '^'){
                flag = false;
                break;
            }
      }
    }
    if ((M==1 || N==1) && !flag){
        cout << "Case #" << c << ": Impossible\n";
        return;
    }
    if (flag) {
        cout << "Case #" << c << ": Possible\n";
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout << matrix[i][j];
            }
            cout << "\n";
        }
        return;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == '.' || matrix[i][j] == '^'){
                matrix[i][j] = 'G';
            }
        }
    }
    makeBad(matrix);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 'B') {
                BFS(matrix, i, j);
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 'B') {
                matrix[i][j] = '.';
            }
            else if (matrix[i][j] == 'G') {
                matrix[i][j] = '^';
            }
        }
    }
    cout << "Case #" << c << ": Possible\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j];
        }
        cout << "\n";
    }
}

int main() {
    freopen("second_second_friend_input.txt", "r", stdin);
    freopen("second_second_friend_output.txt", "w", stdout);
    int T, R, C;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cin >> R >> C;
        vector<vector<char>> matrix(R, vector<char>(C, 0));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> matrix[i][j];
            }
        }
        solution(matrix, c);
    }
    
}