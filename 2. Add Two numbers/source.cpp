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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        int carry = 0;
        ListNode *head = new ListNode();
        ListNode *tail = head;
        while (l1 != NULL && l2 != NULL)
        {
            tail->next = new ListNode(l1->val + l2->val + carry);
            tail = tail->next;
            carry = tail->val / 10;
            tail->val = tail->val % 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL)
        {
            tail->next = new ListNode(l1->val + carry);
            tail = tail->next;
            carry = tail->val / 10;
            tail->val = tail->val % 10;
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            tail->next = new ListNode(l2->val + carry);
            tail = tail->next;
            carry = tail->val / 10;
            tail->val = tail->val % 10;
            l2 = l2->next;
        }
        if (carry > 0)
        {
            tail->next = new ListNode(carry);
        }
        return head->next;
    }
};