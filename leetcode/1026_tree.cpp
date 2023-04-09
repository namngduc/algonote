#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        val = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insertOrder(vector<int> arr, int i, int N) {
    TreeNode* root = nullptr;
    if (i < N) {
        root = new TreeNode(arr[i]);
        root->left = insertOrder(arr, 2*i+1, N);
        root->right = insertOrder(arr, 2*i+2, N);
    } 
    return root;
}

void printLevel(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int nodeCount = q.size();
        for (int i = 0; i < nodeCount; i++) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        cout << endl;
    }
}

class Solution {
public:
    int res = INT_MIN;
    int maxAncestorDiff(TreeNode* root) {
        DFS(root);
        return res;
        
    }
    pair<int, int> DFS(TreeNode* node) {
        if (!node || node->val == -1) {
            return {INT_MAX, INT_MIN};
        }
        if (!node->left && !node->right) {
            return {node->val, node->val};
        }
        pair<int, int> v_l = DFS(node->left);
        pair<int, int> v_r = DFS(node->right);
        int minVal = min({v_l.first, v_r.first, node->val});
        int maxVal = max({v_l.second, v_r.second, node->val});
        cout << minVal << " " << maxVal << endl;
        res = max({node->val - minVal, maxVal - node->val, res});
        return {minVal, maxVal};
    }

};

int main() {
    vector<int> lis = {8,3,10,1,6,-1,14,-1,-1,4,7,13};
    TreeNode* root = insertOrder(lis, 0, lis.size());
    // printLevel(root);
    Solution* so = new Solution();
    int res = so->maxAncestorDiff(root);
    cout << "Res: " << res << endl;
}