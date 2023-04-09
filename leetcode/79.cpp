#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int M = board.size(), N = board[0].size();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (DFS(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>>& board, int i, int j, int x, string word) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '.') {
            return false;
        }
        if (x == word.size()) return true;
        if (board[i][j] != word[x]) return false;
        char tmp = board[i][j];
        board[i][j] = '.';
        bool flag = DFS(board, i+1, j, x+1, word) || DFS(board, i, j+1, x+1, word) \
        || DFS(board, i-1, j, x+1, word) || DFS(board, i, j-1, x+1, word);
        board[i][j] = tmp;
        return flag;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
        // {'a'}
        // {'a','a','b','a','a','b'},
        // {'a','a','b','b','b','a'},
        // {'a','a','a','a','b','a'},
        // {'b','a','b','b','a','b'},
        // {'a','b','b','a','b','a'},
        // {'b','a','a','a','a','b'}
        // {'A','A','A','A','A','A'},
        // {'A','A','A','A','A','A'},
        // {'A','A','A','A','A','A'},
        // {'A','A','A','A','A','A'},
        // {'A','A','A','A','A','A'},
        // {'A','A','A','A','A','A'}
        // {'C','A','A'},
        // {'A','A','A'},
        // {'B','C','D'}
    };
    string word = "ABCCED";
    // string word = "a";
    // string word = "bbbaabbbbbab";
    // string word = "AAAAAAAAAAAAAAB";
    // string word = "AAB";
    Solution* so = new Solution();
    bool res = so->exist(board, word);
    cout << (res == 1 ? "True" : "False") << endl;
}