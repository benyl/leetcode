/*
Swap Nodes in Pairs

http://leetcode.com/onlinejudge#question_24

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. 
You may not modify the values in the list, only nodes itself can be changed.
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
    // version 1, do it in iteration
    ListNode *swapPairs1(ListNode *head) {
        if(!head) return head;
        if(!(head->next)) return head;
        
        ListNode *p = head->next;
        head->next = p->next;
        p->next=head;
        head = p;
        p = p->next;
        
        while(p->next && p->next->next) {
            ListNode *q = p->next;
            p->next = q->next;
            q->next = p->next->next;
            p->next->next = q;
            p = q;
        }
        
        return head;
    }
    
    // version 2, do it in recursion
    ListNode *swapPairs(ListNode *head) {
        if(!head || !(head->next)) return head;
        
        ListNode *p = head->next->next;
        head->next->next = head;
        head = head->next;
        head->next->next = swapPairs(p);
        
        return head;
    }
};