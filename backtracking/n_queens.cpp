#include<bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<std::string>> res;
    std::vector<std::vector<std::string>> solvedNQueens(int n) {
        std::vector<std::string> board (n, std::string(n, '.'));
        for (int i=0; i < board.size(); i++) {
            for (int j=0; j < board[i].size(); j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
        backtrack(board, 0);
        return res;
    }
    void backtrack(std::vector<std::string>& board, int row) {
        // trigger the End Condition
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        int n = board[row].size();
        for (int col=0; col < n; col++) {
            // exclude illegal seletions
            if (!isValid(board, row, col)) 
                continue;
            // select
            board[row][col] = 'Q';
            // enter next row decision
            backtrack(board, row+1);
            // deselect
            board[row][col] = '.';
        }
    }
    bool isValid(std::vector<std::string>& board, int row, int col) {
        // Check if share the same column
        for (int i=0; i < row; i++) {
            if (board[i][col]=='Q') {
                return false;
            }
        }
        int n = board.size();
        // Check if share the same right diagonal
        for (int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if (board[i][j]=='Q')
                return false;
        }
        // Check if share the same left diagonal
        for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if (board[i][j]=='Q')
                return false;
        }
        return true;
    }
};
int main() {
    int n = 4;
    Solution so;
    std::vector<std::vector<std::string>> result = so.solvedNQueens(n);
    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            std::cout << result[i][j] << std::endl;
        }
        std::cout << "\n";
    }
    return 0;
}
