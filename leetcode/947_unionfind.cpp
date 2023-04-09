#include<bits/stdc++.h>
using namespace std;


class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int count;
    UnionFind(int k) {
        parent.resize(k);
        size.resize(k);
        for (int i = 0; i < k; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        count = k;
    }

    void Union(int p, int q) {
        int u = find(p);
        int v = find(q);
        if (u == v) {
            return;
        }
        if (size[u] > size[v]) {
            parent[v] = u;
            size[u] += size[v];
        }
        else {
            parent[u] = v;
            size[v] += size[u];
        }
        count--;
    }

    bool connected(int p, int q) {
        int u = find(p);
        int v = find(q);
        return u == v;
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        vector<vector<int>> graph;
        graph.resize(N);
        UnionFind* UF = new UnionFind(N);
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    cout << "(i, j): " << i << ", " << j << endl;
                    UF->Union(i, j);
                }
            }
        }
        cout << UF->count << endl;
        vector<int> parent = UF->parent;
        vector<int> size = UF->size;
        cout << "Parent: ";
        for (int n : parent) cout << n << " ";
        cout << "\n";
        cout << "Size: ";
        for (int n : size) cout << n << " ";
        cout << "\n";
        int cnt = UF->count;
        if (N > cnt) return N - cnt;
        return 0;
    }
};

int main() {
    vector<vector<int>> stones = {
        {0,0}, {0,1}, {1,0}, {1,2}, {2,1}, {2,2}
        // {0,1}, {0, 0}, {1,0}, {2, 2}, {1,2}, {2,1}
        // {0,0},{0,2},{1,1},{2,0},{2,2}
        // {26,14},{11,4},{9,1},{24,20},{6,6},{3,0},{11,21},{11,11},{1,17},{19,15},{11,23},{27,1},{11,24},{15,19},{26,6},{27,29},{15,12},{10,8},{13,12},{14,5},{27,7},{13,25},{3,10},{17,11},{28,9},{1,12},{20,0},{27,16},{6,25},{23,21},{22,7},{7,28},{8,6},{22,10},{27,28},{5,29},{22,3},{24,19},{4,28},{3,2},{9,20},{12,2},{22,17},{14,24},{28,22},{23,1},{5,28},{22,0},{27,27},{18,13},{23,19},{22,25},{11,17},{28,11},{5,16},{8,12},{1,27},{12,19},{9,14},{6,20},{19,18},{29,24}

    };
    Solution* so = new Solution();
    int res = so->removeStones(stones);
    cout << res << endl;
}