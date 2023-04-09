#include<bits/stdc++.h>

class Solution {
public:
    void printIndent(int n) {
        for (int i=0; i < n; i++){
            printf("  ");
        }
    }
    int count = 0;
    std::unordered_map<int, int> memo;
    int dp(std::vector<int>& coins, int n) {
        printIndent(count++);
        printf("n=%d\n", n);
        if (n==0) {
            printIndent(--count);
            printf("return 0\n");
            return 0;
        }
        if (n<0) {
            printIndent(--count);
            printf("return -1\n");
            return -1;
        }
        int res=INT_MAX;
        if (memo.find(n)!=memo.end()) return memo[n];
        for (int coin: coins) {
            int subproblem = dp(coins, n-coin);
            if (subproblem==-1) continue;
            res = std::min(res, 1+ dp(coins, n-coin));
        }
        memo[n] = (res != INT_MAX) ? res : -1;
        printIndent(--count);
        printf("return %d\n", memo[n]);
        return memo[n];
    }
};


int main() {
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution so;
    int result = so.dp(coins, amount);
    std::cout << result << "\n"; 
}