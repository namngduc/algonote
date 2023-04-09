#include <bits/stdc++.h>
using namespace std;


class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while (!st.empty() && st.top().first <= price) {;
            cnt += st.top().second;
            st.pop();
        }
        st.push({price, cnt});
        return cnt;
    }
};

int main() {
    vector<int> stocks = {
        100,80,60,70,60,75,85
        // 31,41,48,59,79
    };
    // (100, 100, 1), (80, 80, 1), (60, 60, 1), (70, 60, 2), (60, )  
    StockSpanner* st = new StockSpanner();
    for (int n : stocks) {
        st->next(n);
        // cout << st->next(n) << endl;
    }
}