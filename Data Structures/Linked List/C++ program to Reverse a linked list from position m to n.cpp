// https://leetcode.com/problems/reverse-linked-list-ii/solution/

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
    ListNode* reverseBetween(ListNode* A, int m, int n) {
        if (!A || m == n) {
        return A;
    }
    

    ListNode *prev_beg = A;
    int i = 1;
    if (m == 1) {
        i = 0;
        prev_beg = NULL;
    } else {
        for (i = 1; i < m - 1; ++i) {
            prev_beg = prev_beg->next;
        }
    }
    
    ListNode *beg = A;
    if (prev_beg) {
        beg = prev_beg->next;
    }
    ListNode *cur = beg;
    ListNode *new_next = NULL;
    ++i;
    while (i < n) {
        ListNode *old_next = cur->next;
        cur->next = new_next;
        new_next = cur;
        cur = old_next;
        ++i;
    }
    
    ListNode *old_next = cur->next;
    cur->next = new_next;
    if (prev_beg) {
        prev_beg->next = cur;
    }
    beg->next = old_next;
    
    ListNode *head = A;
    if (m == 1) {
        head = cur;
    }
    
    return head;
        
    }
};
