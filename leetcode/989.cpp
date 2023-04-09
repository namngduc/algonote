#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> m;
        while (k > 0) {
            int remain = k % 10;
            m.push_back(remain);
            k /= 10;
        }
        reverse(m.begin(), m.end());
        int carry = 0;
        vector<int> res;
        int i = num.size()-1, j = m.size()-1;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) sum += num[i];
            if (j >= 0) sum += m[j];
            carry = (sum > 9) ? 1 : 0;
            int tmp = (0 <= sum && sum <=9) ? sum : (sum % 10);
            res.push_back(tmp);
            i--;
            j--;
        }
        if (carry != 0) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};

// Input: num = [2,1,5], k = 806
// Output: [1,0,2,1]

int main() {
    vector<int> num = {
        2, 1, 5
        // 9,9,9,9,9,9,9,9,9,9
    };
    int k = 806;
    Solution* so = new Solution();
    vector<int> res = so->addToArrayForm(num, k);
    for (int n : res) cout << n << " ";
    cout << "\n";
}