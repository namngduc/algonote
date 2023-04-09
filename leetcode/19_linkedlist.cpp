#include <bits/stdc++.h>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next && n == 1) return nullptr;
        ListNode *slow = head;
        ListNode* prev_slow;
        int i = 0;
        while (slow) {
            prev_slow = slow;
            slow = slow->next;
            i++;
        }

        int t = i - n + 1;
        if (t == i) prev_slow->next = nullptr;
        if (t == 1) return head->next;
        ListNode* curr = head;
        int k = 1; 
        while (curr && curr->next) {
            if (k + 1 == t) {
                curr->next = curr->next->next;
                curr = curr->next;
                break;
            }
            else {
                curr = curr->next;
                k++;
            }
        }
        return head;
    }
};

int main() {
    ListNode* node = new ListNode(0);
    ListNode* head = node;
    vector<int> lis = {
        1,2,3,4,5,6,7,8,9
    };
    int n = 1;
    for (int i = 0; i < lis.size(); i++) {
        ListNode* new_node = new ListNode(lis[i]);
        node->next = new_node;
        node = node->next;
        
    }
    printList(head->next);
    Solution so;
    ListNode* res = so.removeNthFromEnd(head->next, n);
    printList(res);
}