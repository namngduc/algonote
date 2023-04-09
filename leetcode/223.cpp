#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = abs(ax1 - ax2) * abs(ay1 - ay2);
        int area2 = abs(bx1 - bx2) * abs(by1 - by2);
        int total_area = area1 + area2;
        int overlap_area = 0;
        int x_dist = min(ax2, bx2) - max(ax1, bx1);
        int y_dist = min(ay2, by2) - max(ay1, by1);
        if (x_dist > 0 && y_dist > 0) {
            overlap_area = x_dist * y_dist;
        }
        cout << total_area << endl;
        cout << overlap_area << endl;
        return total_area - overlap_area;


    }
};

int main() {
    // int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -4, bx2 = 2, by2 = -2;
    // int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -1, by1 = -1, bx2 = 1, by2 = 1;
    int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2;
    // int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
    // (-3, 0), (3, 4), (0, -1), (9, 2)
    // (-2, -2), (2, 2), (2, -2), (2, 2)
    Solution* so = new Solution();
    int res = so->computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    cout << res << endl;
}