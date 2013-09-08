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
        int length = 1;
        ListNode *tail = head;
        
        // get the length of list
        while(tail->next!=NULL) {
            ++length;
            tail = tail->next;
        }
        
        // connect the tail to head
        tail->next = head;
        
        // rotate the list rigth to the k-th node
        for(k = length - k % length; k>0; --k)
            tail = tail->next;
        
        // cut the list at tail
        head = tail->next;
        tail->next = NULL;
        
        return head;
    }
};