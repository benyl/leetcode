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
        // return other list if found a null list
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *head, *tail;
        
        // get the head node from smaller one of l1/l2
        if(l1->val<l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        tail = head;
        
        // merge the node from l1/l2
        while(l1!=NULL && l2!=NULL){
            // add the smaller node to tail of new list
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // add the rest nodes into new list
        if(l1!=NULL)
            tail->next = l1;
        else
            tail->next = l2;
            
        return head;
    }
};