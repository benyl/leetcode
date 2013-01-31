/*
Merge k Sorted Lists

http://leetcode.com/onlinejudge#question_23

Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // erase the NULL pointers
        for(int i=lists.size()-1; i>=0; i--)
            if(!lists[i]) lists.erase(lists.begin()+i);
        
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        
        int min = 0; // the id of minimum list head
        for(int i=0; i<lists.size(); i++) {
            if(lists[min]->val>lists[i]->val)
                min = i;
        }
        
        ListNode *head=lists[min];
        ListNode *end=head;
        
        // erase the node that was placed
        lists[min] = lists[min]->next;
        if(!lists[min]) lists.erase(lists.begin()+min);
        
        while(lists.size()!=0) {
            min = 0; // the id of minimum list head
            for(int i=0; i<lists.size(); i++) {
                if(lists[min]->val>lists[i]->val)
                    min = i;
            }
            
            end->next = lists[min];
            lists[min] = lists[min]->next;
            end = end->next;
            if(!lists[min]) lists.erase(lists.begin()+min);
        }
        
        return head;
    }
};