#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    list<int> dq;
    unordered_map<int, list<int>::iterator> map;
    int c_size;
public:
    LRUCache(int);
    void refer(int);
    void display();
};

LRUCache::LRUCache(int n) {
    c_size = n;
}

void LRUCache::refer(int x) {
    // Not present in deque
    if (map.find(x)==map.end()) {
        if (dq.size()==c_size) {
            int last = dq.back();
            dq.pop_back();
            map.erase(last);
        }
    }
    // Present in deque
    else {
        dq.erase(map[x]);
    }
    // Update reference
    dq.push_front(x);
    map[x] = dq.begin();
}

void LRUCache::display() {
    for (auto it=dq.begin(); it != dq.end(); it++) {
        std::cout << (*it) << "\n";
    }
}

int main() {
    LRUCache ca(4);
    ca.refer(1);
    ca.refer(2);
    ca.refer(5);
    ca.refer(1);
    ca.refer(6);
    ca.refer(8);
    ca.display();
    return 0;
}
