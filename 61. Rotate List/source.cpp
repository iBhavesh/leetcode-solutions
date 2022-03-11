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
    ListNode* rotateRight(ListNode* head, int k) {
        if( k == 0) return head;
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;

        ListNode* tail,*temp = head;
        int n=0;


        // Get the length of list
        while(temp != NULL) {
            n++;
            tail = temp;
            temp = temp->next;
        }
        
        // connect tail to head
        tail->next = head;

        k %= n;
        n -= k;
        temp = head;
        
        for (int i = 1; i < n; i++)
        {
            temp = temp->next;
        }

        tail = temp->next;
        temp->next = NULL;
        return tail;
        

    }
};