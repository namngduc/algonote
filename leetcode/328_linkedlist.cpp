#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

void printList(ListNode* head) {
    ListNode* node = head;
    while (node != NULL) {
        cout << node->val << "->";
        node = node->next;
    }
    cout <<  "NULL" <<"\n";
}

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* odd = head;
        ListNode *even = head->next, *evenHead = head->next;
        while (even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

int main() {
    ListNode* node = new ListNode(0);
    ListNode* head = node;
    vector<int> lis = {
        1,2,3,4,5
        // 2,1,3,5,6,4,7
    };
    // 1,3,5,2,4
    // 2,3,6,7,1,5,4
    for (int i = 0; i < lis.size(); i++) {
        ListNode* new_node = new ListNode(lis[i]);
        node->next = new_node;
        node = node->next;
        
    }
    printList(head->next);
    Solution* so = new Solution();
    ListNode* res = so->oddEvenList(head->next); 
    printList(res);
}