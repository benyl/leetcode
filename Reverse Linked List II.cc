/*
http://leetcode.com/onlinejudge#question_92

Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 <= m <= n <= length of list.
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
        // add a dummy head before head
        ListNode *dhead = new ListNode(0);
        dhead->next = head;
        
        ListNode *pre = dhead; // node before reverse part
        // find the node before reverse part
        while(m!=1) {
            pre = pre->next;
            --m; --n;
        }
        
        // the first node of reverse part will be the last node
        ListNode *curr = pre->next; // current node for iteration
        ListNode *last = curr; // remember the last node of reverse part
        
        // insert the nodes at the head of reverse part
        for(int i=0; i<n; ++i) {
            ListNode *temp = curr->next;
            curr->next = pre->next;
            pre->next = curr;
            curr = temp;
        }
        
        // link the last node to the rest of the linked list
        last->next = curr;
        
        // remove dummy head
        head = dhead->next;
        delete dhead;
        return head;
    }
};