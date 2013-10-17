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
        ListNode *prev = new ListNode(0);
        prev->next = head;
        head = prev;
        
        // find the node before reverse part
        while(m!=1) {
            prev = prev->next;
            --m; --n;
        }
        
        // the first node of reverse part will be the last node
        ListNode *last = prev->next;
        
        // insert the nodes at the head of reverse part
        while(--n!=0) {
            ListNode *temp = last->next;
            last->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        
        // remove dummy head and reaturn real head
        prev = head->next;
        delete head;
        return prev;
    }
};