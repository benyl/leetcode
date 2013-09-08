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
        if(!head || !head->next) return head;
        ListNode *p = head;
        
        // travel the linked list
        while(p->next!=NULL) {
            // if found duplicate node
            if(p->next->val == p->val) {
                // remove the duplicate node
                ListNode *temp = p->next;
                p->next = p->next->next;
                delete temp;
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
        if(!head || !head->next) return head;
        
        // add a dummy head before head
        ListNode *pre = new ListNode(head->val-1);
        pre->next = head;
        head = pre;
        
        // use flag to mark if a node is duplicated
        bool duplicated = false;
        
        // use only pre to store the pre for iteration
        while(pre->next!= NULL) {
            ListNode *temp = pre->next;
            // if found duplicate node, delete the first one, and mark flag
            if(temp->next && temp->val == temp->next->val) {
                pre->next = pre->next->next;
                delete temp;
                duplicated = true;
            } else if(duplicated) { // delete the last one, and clear flag
                pre->next = pre->next->next;
                delete temp;
                duplicated = false;
            } else { // no duplicate, move forward
                pre = pre->next;
            }
        }
        
        // remove dummy head and return real head
        pre = head->next;
        delete head;
        return pre;
    }
};
