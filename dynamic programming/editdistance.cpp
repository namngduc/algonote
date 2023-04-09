#include<bits/stdc++.h>
#define F(i,a,b) for(int i= (int) a; i < (int) b; i++)

int editDistance(std::string s1, std::string s2) {
    int m = s1.length();
    int n = s2.length();

    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));
    F(i,1,m+1){
        dp[i][0] = i;
    } 
    F(i,1,n+1){
        dp[0][i] = i;
    }
    F(i,1,m+1){
        F(j,1,n+1){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else
                dp[i][j] = 1 + std::min(dp[i-1][j-1],
                                        std::min(dp[i-1][j],
                                        dp[i][j-1]));

        }
    }
    F(i,0,m+1){
        F(j,0,n+1){
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }
    return dp[m][n];
}

int main() {
    std::string s1 = "sitting";
    std::string s2 = "kitten";
    int res = editDistance(s1, s2);
    std::cout << res << "\n";
    return res;
}