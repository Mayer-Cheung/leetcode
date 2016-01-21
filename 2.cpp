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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* prev = &dummy;
        int carry = 0;
        for (ListNode *a = l1, *b = l2; a != NULL || b != NULL; a = a == NULL? NULL : a->next, b = b == NULL? NULL : b->next, prev = prev->next)
        {
        	int ta = a == NULL? 0 : a->val;
        	int tb = b == NULL? 0 : b->val;
        	prev->next = new ListNode((ta + tb + carry) % 10);
        	carry = (ta + tb + carry) / 10;
        }
        if (carry)
        	prev->next = new ListNode(1);
        return dummy.next;
    }
};