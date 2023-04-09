#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // priority_queue<pr, vector<pr>, greater<pr>> pq;
        // for (int num : arr) {
        //     pr tmp;
        //     tmp.first = abs(x - num);
        //     tmp.second = num;
        //     pq.push(tmp);
        // }
        // vector<int> res;
        // res.resize(k);
        // int i = 0;
        // while (!pq.empty()) {
        //     pr top = pq.top();
        //     pq.pop();
        //     res[i] = top.second;
        //     i++;
        //     if (i == k) break;
        // }
        // sort(res.begin(), res.end());
        vector<int> res;
        int N = arr.size();
        int left = 0, right = N-k;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (x - arr[mid] > arr[mid+k] - x) {
                left = mid+1;
            }
            else
                right = mid;
        }
        for (int i = left; i < left+k; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};

int main() {
    vector<int> arr = {
        1,1,1,10,10,10
    };
    int k = 1;
    int x = 9;
    Solution so;
    vector<int> res = so.findClosestElements(arr, k, x);
    for (int x : res) {
        cout << x << " ";
    }
}