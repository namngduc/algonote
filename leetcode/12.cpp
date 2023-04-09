#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> map = {{1, "I"}, {4, "VI"}, {5, "V"}, {9, "XI"}, {10, "X"}, {40, "LX"}, {50, "L"}, {90, "CX"}, \
        {100, "C"}, {400, "DC"}, {500, "D"}, {900, "MC"}, {1000, "M"}};
        string res = "";
        int div = 10;
        while (num > 0) {
            int curr = num % div;
            if (curr == 0) {
                while (curr == 0) {
                    div *= 10;
                    curr = num % div;
                }
                cout << "check: " << div << ", " << curr << endl;
                div /= 10;
                curr = (curr != div * 4 && curr != div * 9 && curr != div * 5) ? div : curr;
            }
            if (curr == num && curr > 1000) {
                // cout << "Debug: " << curr << ", " << div << endl;
                div /= 10;
                curr = div;
            }
            // cout << "Curr: " << curr  << ", " << num << endl;
            num -= curr;
            if (map.find(curr) != map.end()) {
                res += map[curr];
            }
            else {
                while (map.find(curr) == map.end()) {
                    if (curr < 10) {
                        curr -= 1;
                        res += map[1];
                    }
                    else if (curr < 100) {
                        curr -= 10;
                        res += map[10];
                    }
                    else {
                        curr -= 100;
                        res += map[100];
                    }
                }
                res += map[curr];
            }
            div *= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {
    int num = 100;
    // "LVIII"
    //  1994
    // "MCMXCIV"
    Solution* so = new Solution();
    string res = so->intToRoman(num);
    cout << res << endl;
    // for (int i = 1; i < 4000; i++) {
    //     cout << "Num: " << i << endl;
    //     string res = so->intToRoman(i);
    //     cout << res << endl;
    // }
}

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000