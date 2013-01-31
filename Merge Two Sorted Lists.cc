/*
Merge Two Sorted Lists

http://leetcode.com/onlinejudge#question_21

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *head, *end;
        if(l1->val<l2->val) {head = l1; l1 = l1->next;}
        else {head = l2; l2 = l2->next;}
        
        end = head;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val) {
                end->next = l1;
                l1 = l1->next;
                end = end->next;
            } else {
                end->next = l2;
                l2 = l2->next;
                end = end->next;
            }
        }
        
        if(l1!=NULL)
            end->next = l1;
        if(l2!=NULL)
            end->next = l2;
            
        return head;
    }
};