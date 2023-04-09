#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* child[26];
        int cnt;
        bool isEnd;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            cnt = 0;
            isEnd = false;
        } 
    };
    TrieNode* root = new TrieNode();
    void TrieInsert(const string& s) {
        int n = s.length();
        TrieNode* p = root;
        for (int i = 0; i < n; i++) {
            int nxt = s[i] - 'a';
            if (p->child[nxt]==NULL) {
                p->child[nxt] = new TrieNode(); 
            }
            p = p->child[nxt];
            p->cnt += 1;
        }
        p->isEnd = true;
    }
    int TrieSearch(const string& s) {
        int n = s.length();
        int res = 0;
        TrieNode* p = root;
        for (int i = 0; i < n; i++) {
            int nxt = s[i] - 'a';
            if (p->child[nxt] == NULL) {
                return -1;
            }
            p = p->child[nxt];
            res += p->cnt;
        }
        return res;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        for (string w : words) {
            TrieInsert(w);
        }
        for (string w : words) {
            int cnt = TrieSearch(w);
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main() {
    vector<string> words = {
        // "abc","ab","bc","b"
        "abcd"
    };
    Solution so;
    vector<int> res = so.sumPrefixScores(words);
    for (int r : res) {
        cout << r << " ";
    }
    cout << "\n";
}