#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree {
public:
    map<int, int> hashMap;
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        hashMap[start]++;
        hashMap[end]--;
        int res = 0, curr = 0;
        for (auto x : hashMap) {
            res = max(res, curr += x.second);
        }
        return res;

    }
};

int main() {
    vector<vector<int>> arr = { 
        {10, 20}, {50, 60}, {10, 40}, {5, 15}, {5, 10}, {25, 55}
    };
    // [null, 1, 1, 2, 3, 3, 3]
    MyCalendarThree* obj = new MyCalendarThree();
    for (vector<int> x : arr) {
        int start = x[0], end = x[1];
        int param_1 = obj->book(start,end);
        // cout << param_1 << " ";
    }
    // cout << "\n";
}