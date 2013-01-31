/*
http://leetcode.com/onlinejudge#question_114

Flatten Binary Tree to Linked List:

Given a binary tree, flatten it to a linked list in-place.

For example,
Given
         1
        / \
       2   5
      / \   \    
     3   4   6
The flattened tree should look like
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

#include <stdio.h>
#include <iostream>
#inlcude <stack>

using namespace std;

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
    void flatten(TreeNode *root) {
        if(root == NULL) return;
        
        stack<TreeNode *> s;
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode *p = s.top();
            s.pop();
            
            if(p->right)s.push(p->right);
            if(p->left)s.push(p->left);
            
            if(!s.empty())
				p->right = s.top();
			else
				p->right = NULL;

            p->left = NULL;
        }
    }
};