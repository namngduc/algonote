#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        bool res = true;
        vector<vector<int>> arr;
        for (int d : data) {
            vector<int> t = convertBinary(d);
            arr.push_back(t);
        }
        if (arr.size() == 1 && arr[0][0] == 1) return false;
        int k = 0;
        while (k < arr.size()) {
            if (arr[k][0] == 0) {
                k++;
                continue;
            }
            else if (arr[k][0] == 1) {
                int cnt = 1;
                int i = 1;
                while (arr[k][i] == 1 && i < 4) {
                    i++;
                    cnt++;
                }
                cout << "Debug: " <<  cnt << "\n";
                if (cnt > 4 || k + cnt > arr.size() || cnt == 1) return false;
                k++;
                for (int a = 0; a < cnt-1; a++) {
                    // k++;
                    if (k < arr.size() && arr[k][0] == 1 && arr[k][1] == 0) { 
                        k++;
                        continue;
                    }
                    else if (arr[k][0] != 1 || arr[k][1] != 0)  {
                        res = false;
                        return res;
                    }
                }
            }
        }
        return res;
    }
    vector<int> convertBinary(int n) {
        vector<int> res(8, 0);
        int i = 7;
        while (n > 0) {
            int x  = n % 2;
            res[i] = x;
            n /= 2;
            i--;
        }
        for (int i = 0; i < 8; i++) {
            cout << res[i];
        }
        cout << "\t";
        return res;
    }
};

int main() {
    // 11000101 10000010 00000001
    // 11101011 10001100 00000100
    vector<int> data = {
        // 197,130,1
        // 235,140,4
        240,162,138,147,145
    };
    Solution so;
    bool res = so.validUtf8(data);
    string ans;
    ans = res == 0 ? "False" : "True";
    cout << "The result: " << ans;
}