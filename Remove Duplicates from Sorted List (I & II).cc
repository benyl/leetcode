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
class Solution {
public:
    // Remove Duplicates from Sorted List
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return head;
        ListNode *p = head;
        
        while(p->next!=NULL) {
            if(p->next->val == p->val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        
        return head;
    }
    
    // Remove Duplicates from Sorted List II
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return head;
        ListNode *p = head, *pre = head;
        bool flag = false;
        
        while(p->next!=NULL) {
            if(p->next->val == p->val) {
                p->next = p->next->next;
                flag = true;
            } else if(flag) {
                if(p!=head) {
                    pre->next = p->next;
                } else {
                    head = p->next;
                }
                p = p->next;
                flag = false;
            } else {
                pre = p;
                p = p->next;
            }
        }
        
        if(flag) {
            if(p!=head) {
                pre->next = p->next;
            } else {
                head = p->next;
            }
            p = p->next;
        }
        
        return head;
    }
};