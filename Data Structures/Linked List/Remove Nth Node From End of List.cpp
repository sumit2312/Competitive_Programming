/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
        int len=0;
        ListNode* cur=head;
        while(cur){
            cur=cur->next;
            len++;
        }
        // cout<<len;
        if(n>=len) return head->next;
        ListNode* temp=head;
        for(int i=0;i<len-n-1;i++){
            temp=temp->next;
        }
        temp->next = temp->next->next;
        
        return head;
        
    }
};
