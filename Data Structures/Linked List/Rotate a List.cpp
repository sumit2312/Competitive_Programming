/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL


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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode* curr = head;
        int len = 1;
        while(curr->next && len++) curr = curr->next;
        curr -> next = head;
        k = len - k%len;
        while(k--) curr = curr->next;
        head = curr -> next;
        curr -> next = nullptr;
        return head;
    }
};

// --------------------------------- ALTER   --------------------------------------------
/*This is a function problem.You only need to complete the function given below*/
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
/*  This function should rotate list counter-clockwise
    by k and return new head (if changed) */
Node* rotate(Node* head, int k) {
    vector<int> vec;
    Node* curr = head;
    
    while(curr!= nullptr){
        vec.push_back(curr->data);
        curr = curr->next;
    }
    k = k%(vec.size());
    rotate(vec.begin(),vec.begin() + k, vec.end());
    Node* temp = head;
    int index=0;
    while(temp!=NULL){
        temp->data =vec[index++];
        temp = temp->next;
    }
    return head;
}
