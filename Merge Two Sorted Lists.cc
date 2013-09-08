/*
Merge Two Sorted Lists

http://leetcode.com/onlinejudge#question_21

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // return other list if found a null list
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *head, *tail;
        
        // get the head node from smaller one of l1 / l2
        if(l1->val<l2->val) {
            head = tail = l1;
            l1 = l1->next;
        } else {
            head = tail = l2;
            l2 = l2->next;
        }
        
        // merge the node from l1 / l2
        while(l1!=NULL && l2!=NULL){
            // add the smaller node to tail of new list
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // add the rest nodes into new list
        if(l1)
            tail->next = l1;
        else
            tail->next = l2;
            
        return head;
    }
};

// ====================================================
// compact version using pointer of pointer
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // return the other list if found a null list
        if(!l1) return l2;
        if(!l2) return l1;
        
        // get the head node from smaller one of l1 / l2
        ListNode **smaller = (l1->val < l2->val) ? &l1 : &l2;
        ListNode *head = *smaller, *tail = *smaller;
        *smaller = (*smaller)->next;
        
        // add the smaller node to tail of new list
        while(l1 && l2) {
            smaller = (l1->val < l2->val)? &l1 : &l2;
            tail->next = *smaller;
            *smaller = (*smaller)->next;
            tail = tail->next;
        }
        
        // add the rest nodes into new list
        if(l1)
            tail->next = l1;
        else
            tail->next = l2;
        
        return head;
    }
};

// ====================================================
// recursive version
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // return the other list if found a null list
        if(!l1) return l2;
        if(!l2) return l1;
        
        // get the head node from smaller one of l1 / l2
        ListNode **smaller = (l1->val < l2->val) ? &l1 : &l2;
        ListNode *head = *smaller;
        *smaller = (*smaller)->next;
        
        head->next = mergeTwoLists(l1, l2);
        return head;
    }
};