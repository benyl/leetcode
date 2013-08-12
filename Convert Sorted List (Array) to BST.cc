/*
http://leetcode.com/onlinejudge#question_108

Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert 
it to a height balanced BST.

For example:
Given the array: {1, 2, 3, 4, 5},

Return Balanced Binary Search Tree:
              3
            /   \
           1     5
          / \   /
         0   2 4

=======================================================================
http://leetcode.com/onlinejudge#question_109

Convert Sorted List to Binary Search Tree:

Given a singly linked list where elements are sorted in ascending order,
convert it to a height balanced BST.

For example:
Given the linked list: 1->2->3->4->5

Return Balanced Binary Search Tree:
              3
            /   \
           1     5
          / \   /
         0   2 4
*/

/*
              50
            /   \
         24       75
        /  \     /    \ 
       12   37   62   87
     6 18  31 43  56 68  81 93
   3       9
  1 5      8 11
 0 2 4 #  7 # 10 #
 
       5
  2        8
 1 4      7  9
0 # 3 #  6 # # # 
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head) return NULL;
        
        int len=0;
        for(ListNode *p=head; p!=NULL; p=p->next) ++len;
        if(len==1) return new TreeNode(head->val);
        
        ListNode *prev=head;
        for(int i=0; i<len/2-1; ++i) prev=prev->next;
        
        TreeNode *root = new TreeNode(prev->next->val);
        root->right = sortedListToBST(prev->next->next);
        prev->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num, int start=0, int end=-1) {
        if(num.size()==0) return NULL;
        if(end==-1) end = num.size();
        if(start >= end) return NULL;
        if(start == end-1) return new TreeNode(num[start]);
        TreeNode *root = new TreeNode(num[(start+end)/2]);
        root->left = sortedArrayToBST(num, start, (start+end)/2);
        root->right = sortedArrayToBST(num, (start+end)/2+1, end);
        return root;
    }
};