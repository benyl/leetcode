/*
Rotate List

http://leetcode.com/onlinejudge#question_61

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head) return head;
        
        int len = 1;
        ListNode *p = head;
        while(p->next!=NULL) {
            p=p->next;
            len++;
        }
        
        k = len - k%len;
        if(k==len) return head;
        
        p->next=head;
        for(int i=0; i<k; i++) {
            p = p->next;
        }
        
        head = p->next;
        p->next = NULL;
        return head;
    }
};