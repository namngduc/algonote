#include <bits/stdc++.h>
using namespace std;

string solution(vector<int>& arr, int K, int c) {
    int N = arr.size();
    vector<int> cnt(105, 0);
    bool flag = true;
    for (int i = 0; i < arr.size(); i++) {
        cnt[arr[i]]++;
    }
    for (int x : cnt) {
        if (x > 2) {
            flag = false;
            break;
        }
    }
    if (2 * K < N)
        flag = false;
    string res = "";
    if (!flag) {
        res = "Case #" + to_string(c) + ": NO\n";
    }
    else
        res = "Case #" + to_string(c) + ": YES\n";
    return res;
}


int main() {
    freopen("second_hands_input.txt", "r", stdin);
    freopen("second_hands_output.txt", "w", stdout);
    int T, N, K;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cin >> N >> K;
        vector<int> arr(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        string res = solution(arr, K, c);
        cout << res;
    }
}