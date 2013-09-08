/*
Partition List

http://leetcode.com/onlinejudge#question_86

Given a linked list and a value x, partition it such that all nodes 
less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each 
of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        // last is use to point to the last element that is smaller than X
        ListNode *last = NULL, *runner = head, *prev = NULL;
        
        // partition the linked list around x
        while(runner!=NULL) {
            if(runner->val < x) { 
                if(last == NULL) { // this is the first element smaller than X
                    last = runner;
                    
                    if(runner==head) { // if runner is head, just move forward
                        prev = runner;
                        runner = runner->next;
                    } else { // move the element to last
                        prev->next = runner->next;
                        runner->next = head;
                        head = runner;
                        runner = prev->next;
                    }
                } else if(last == prev) { // if there is no element bigger or equal to X
                    last = last->next;
                    prev = prev->next;
                    runner = runner->next;
                } else { // move the element to last
                    prev->next = runner->next;
                    runner->next = last->next;
                    last->next = runner;
                    last = runner;
                    runner = prev->next;
                }
            } else { // for element bigger or equal to X, move forward
                prev = runner;
                runner = runner->next;
            }
        }
        
        return head;
    }
};

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
    ListNode *partition(ListNode *head, int x) {
        // p1 is end of nodes smaller than x, p2 is end of nodes greater than or equal to x
        ListNode *p1=head, *p2=head;
        
        head = new ListNode(0); // add a dummy head before head
        head->next=p1;
        p1=p2=head;
        
        while(p2->next!=NULL) {
            if(p2->next->val<x) { // if val < x, move current node after p1
                if(p2==p1) { // if p2==p1, no nodes greater than or equal to x
                    p1=p1->next;
                    p2=p2->next;
                } else { // move current node after p1
                    ListNode *temp= p2->next;
                    p2->next = temp->next;
                    temp->next = p1->next;
                    p1->next = temp;
                    p1 = p1->next;
                }
            } else { // if val >= x, move current node after p2 (= do nothing)
                p2=p2->next;
            }
        }
        
        p1 = head->next;
        delete head; // remove dummy head
        return p1;
    }
};