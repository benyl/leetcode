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
        
        // return head if not need to rotate
        k %= length;
        if(k == 0) return head;
        
        // connect the tail to head
        tail->next = head;
        
        // rotate the list to the k-th node
        for(int i=0; i<length-k; ++i)
            tail = tail->next;
        
        // cut the list at tail
        head = tail->next;
        tail->next = NULL;
        
        return head;
    }
};