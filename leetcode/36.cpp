#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> set_row, set_col;
        int M = board.size(), N = board[0].size();
        cout << M << " " << N << endl;
        for (int i = 0 ; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    // cout << board[i][j] << " ";
                    if (set_row.find(board[i][j]) != set_row.end()) {
                        return false;
                    }
                    set_row.insert(board[i][j]);
                }
            }
            // cout << "\n";
            set_row.clear();
        }
        // cout << "Set row: " << set_row.size() << endl;
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                if (board[i][j] != '.') {
                    if (set_col.find(board[i][j]) != set_col.end()) {
                        return false;
                    }
                    set_col.insert(board[i][j]);
                }
            }
            set_col.clear();
        }
        // cout << "Set col: " << set_col.size() << endl;
        for (int i = 0; i < M; i += M/3) {
            for (int j = 0; j < N; j += N/3) {
                // cout << "(i, j): " << i << ", " << j << endl;
                if (!checkBox(board, i, j)) {
                    return false;
                }
            }
        }
        return true; 
    }
    bool checkBox(vector<vector<char>>& board, int startRow, int startCol) {
        set<char> setBox;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c = board[startRow + i][startCol + j];
                if (c != '.') {
                    if (setBox.find(c) != setBox.end()) {
                        return false;
                    }
                    setBox.insert(c);
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        // {'5','3','.','.','7','.','.','.','.'},
        // {'6','.','.','1','9','5','.','.','.'},
        // {'.','9','8','.','.','.','.','6','.'},
        // {'8','.','.','.','6','.','.','.','3'},
        // {'4','.','.','8','.','3','.','.','1'},
        // {'7','.','.','.','2','.','.','.','6'},
        // {'.','6','.','.','.','.','2','8','.'},
        // {'.','.','.','4','1','9','.','.','5'},
        // {'.','.','.','.','8','.','.','7','9'}
        {'.','.','4','.','.','.','6','3','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'5','.','.','.','.','.','.','9','.'},
        {'.','.','.','5','6','.','.','.','.'},
        {'4','.','3','.','.','.','.','.','1'},
        {'.','.','.','7','.','.','.','.','.'},
        {'.','.','.','5','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'}
    };
    Solution* so = new Solution();
    bool res = so->isValidSudoku(board);
    cout << ((res == 1) ? "True" : "False") << endl; 
}