/*
Remove Duplicates from Sorted List

http://leetcode.com/onlinejudge#question_83

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

=======================================================================

Remove Duplicates from Sorted List II

http://leetcode.com/onlinejudge#question_82

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//======================================================================= 
// Remove Duplicates from Sorted List
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return head;
        ListNode *p = head;
        
        // travel the linked list
        while(p->next!=NULL) {
            // if found duplicate node
            if(p->next->val == p->val) {
                // remove the duplicate node
                p->next = p->next->next;
            } else {
                // else move to next node
                p = p->next;
            }
        }
        
        return head;
    }
};

//=======================================================================
// Remove Duplicates from Sorted List II
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return head;
        
        // use flag to mark if a node is duplicated
        ListNode *pre = head;
        bool flag = false;
        
        // add a dummy head before head
        head = new ListNode(head->val-1);
        head->next = pre;
        pre = head;
        
        // use only pre to store the pre for iteration
        while(pre->next->next!=NULL) {
            ListNode *p = pre->next;
            // if found duplicate node, delete the later one
            if(p->next->val == p->val) {
                p->next = p->next->next;
                flag = true;
            } else {
                // remove the head of duplicate chain
                if(flag)
                    pre->next = p->next;
                else
                    pre = pre->next;
                flag = false;
            }
        }
        
        // remove the last node that is duplicated
        if(flag) 
            pre->next = pre->next->next;
        
        // real head is the next node after dummy head
        return head->next;
    }
};