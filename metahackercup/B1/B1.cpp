#include <bits/stdc++.h>
using namespace std;

void solution(vector<vector<char>>& matrix, int c) {
    int M = matrix.size(), N = matrix[0].size();
    bool flag = false;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == '^'){
                flag = true;
            }
        }
    }
    if ((M==1 || N==1) && flag) {
        cout << "Case #" << c << ": Impossible\n";
        return;
    }
    if (!flag) {
        cout << "Case #" << c << ": Possible\n";
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout << matrix[i][j] << "";
            }
            cout << "\n";
        }
        return;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == '.'){
                matrix[i][j] = '^';
            }
        }
    }
    cout << "Case #" << c << ": Possible\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << "";
        }
        cout << "\n";
    }
}

int main() {
    freopen("second_friend_input.txt", "r", stdin);
    freopen("second_friend_output.txt", "w", stdout);
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