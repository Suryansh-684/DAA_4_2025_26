/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionsort(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        while (head) {
            ListNode* c = head;
            head = head->next;
            ListNode* p = dummy;
            while (p->next && p->next->val < c->val) {
                p = p->next;
            }
            c->next = p->next;
            p->next = c;
        }

        return temp->next;
    }
};
