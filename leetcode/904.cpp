#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> map;
        int N = fruits.size();
        int i = 0, j = 0;
        int res = 0;
        while (j < N) {
            map[fruits[j]]++;
            if (map.size() <= 2) {
                res = max(res, j-i+1);
            }
            else {
                map[fruits[i]]--;
                if (map[fruits[i]] == 0) map.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};

int main() {
    vector<int> fruits = {
        1, 2, 3, 2, 2
    };
    // Output 4
    Solution* so = new Solution();
    int res = so->totalFruit(fruits);
    cout << res << endl;
}