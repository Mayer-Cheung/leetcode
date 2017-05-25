/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* i = dummy, *j = dummy;
        while (j->next) {
            j = j->next;
            if (j->val != 9)
                i = j;
        }
        if (j->val != 9)
            j->val++;
        else {
            i->val++;
            i = i->next;
            while (i) {
                i->val = 0;
                i = i->next;
            }
        }
        if (dummy->val == 0)
            return dummy->next;
        else
            return dummy;
    }
};
