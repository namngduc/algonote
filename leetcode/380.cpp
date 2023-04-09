#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (map.find(val) != map.end()) return false;
        nums.emplace_back(val);
        map[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) return false;
        int last = nums.back();
        map[last] = map[val];
        nums[map[val]] = last;
        nums.pop_back();
        map.erase(val);
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> map;
};

int main() {
    // Input
    // ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
    // [[], [1], [2], [2], [], [1], [2], []]
    // Output
    // [null, true, false, true, 2, true, false, 2]
    vector<string> input = {"insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"};
    vector<int> val = {1, 2, 2, -6699, 1, 2, -6699};
    RandomizedSet* obj = new RandomizedSet();
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == "insert") {
            bool param_1 = obj->insert(val[i]);
            cout << (param_1 == 1 ? "True" : "False") << endl;
        }
        else if (input[i] == "remove") {
            bool param_2 = obj->remove(val[i]);
            cout << (param_2 == 1 ? "True" : "False") << endl;
        }
        else if (input[i] == "getRandom") {
            int param_3 = obj->getRandom();
            cout << param_3 << endl;
        }
    }
}