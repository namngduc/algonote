#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public: 
    TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    Trie() {
        
    }
    void insert(string word) {
        int n = word.length();
        TrieNode* p = root;
        for (int i = 0; i < n; i++) {
            int nxt = word[i] - 'a';
            if (p->child[nxt] == NULL) {
                p->child[nxt] = new TrieNode();
            }
            p = p->child[nxt];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        int n = word.length();
        TrieNode* p = root;
        for (int i = 0; i< n; i++) {
            int nxt = word[i] - 'a';
            if (p->child[nxt] == NULL) {
                return false;
            }
            p = p->child[nxt];
        }
        return p->isEnd;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        TrieNode* p = root;
        for (int i = 0; i < n; i++) {
            int nxt = prefix[i] - 'a';
            if (p->child[nxt] == NULL) {
                return false;
            }
            p = p->child[nxt];
        }
        return true;
    }
};


