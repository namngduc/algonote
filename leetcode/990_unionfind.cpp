#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;
    int count;
public:
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
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }

    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    int components() {
        return count;
    }
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind UF(26);
        for (string s : equations) {
            if (s[1] == '=') {
                UF.Union(s[0] - 'a', s[3] - 'a');
            }
        }
        for (string s : equations) {
            if (s[1] == '!') {
                if (UF.connected(s[0] - 'a', s[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;       
    }
};

int main() {
    vector<string> equations = {
        // "a==b","b!=a"
        // "a==b", "b==a"
        "e!=c","b!=b","b!=a","e==d"
    };
    Solution so;
    bool res = so.equationsPossible(equations);
    cout << (res == 1 ? "True" : "False") << "\n"; 
    // cout << res;
}