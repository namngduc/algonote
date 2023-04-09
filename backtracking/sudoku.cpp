#include<bits/stdc++.h>

class Solution {
public:
    void solvedSudoku (std::vector<std::vector<char>>& board) {
        backtrack(board, 0, 0);
    }
    bool backtrack(std::vector<std::vector<char>>& board, int row, int col) {
        if (row==board.size()-1 && col==board.size()) {
            return true; 
        }
        if (col==board.size()) {
            row++;
            col=0;
        }
        if (board[row][col] != '.'){
            return backtrack(board, row, col+1);
        }
        for (int num=1; num<10; num++) {
                char str = '0' + num;
                if (!isValid(board, row, col, str)) {
                    continue;
                }
                board[row][col] = str;
                if (backtrack(board, row, col+1)){
                    return true;
                }
                board[row][col] = '.';
        }
        return false;
    }
    bool isValid(std::vector<std::vector<char>>& board, int row, int col, char num) {
        int n = board.size();
        for (int i=0; i<n; i++) {
            if (board[i][col]==num)
                return false;
        }
        for (int j=0; j<n; j++) {
            if (board[row][j]==num) 
                return false;
        }
        int x=row - row%3, y=col-col%3;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                if (board[i+x][j+y]==num)
                    return false;
            }
        }
        return true;
    } 
};

int main() {
    std::vector<std::vector<char>> grid = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution so;
    so.solvedSudoku(grid);
    for (int i=0; i < grid.size(); ++i) {
        for (int j=0; j < grid[i].size(); ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }                     
    return 0;     
}

