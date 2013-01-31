/*
http://leetcode.com/onlinejudge#question_92

Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head || n==m) return head;
        
        ListNode *first = NULL; // first to reverse
        ListNode *last = NULL; // last to reverse
        ListNode *begin = NULL; // node before first node
        ListNode *end = NULL; // node after last node
        
        first = head;
        while(m!=1) {
            begin = first;
            first = first->next;
            m--; n--;
        }
        
        ListNode *prev = first;
        last=first->next;
        end=last->next;
        
        for(m=2;m<n;m++) {
            last->next = prev;
            
            prev = last;
            last = end;
            end = end->next;
        }
        
        last->next = prev;
        first->next = end;
        
        if(begin) {
            begin->next = last;
            return head;
        }
        else return last;
    }
};