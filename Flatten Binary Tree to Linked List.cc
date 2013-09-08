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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// =======================================
// iterative version: use stack for PreOrderTraversal
// time complexity: o(n), space complexity: o(log n)

class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == NULL) return;
        
        stack<TreeNode *> s;
        s.push(root);
        
        while(!s.empty()) {
            TreeNode *p = s.top();
            s.pop();
            
            if(p->right)s.push(p->right);
            if(p->left)s.push(p->left);
            
            p->right = (!s.empty()) ? s.top() : NULL;
            p->left = NULL;
        }
    }
};


// =======================================
// recursive version: 
// time complexity: o(n), space complexty: o(log n) for stack
class Solution {
public:
    TreeNode *flatten(TreeNode *root) {
        if(!root) return root;
        if(!root->left && !root->right) return root;
        
        TreeNode *left_end = flatten(root->left);
        TreeNode *right_end = flatten(root->right);
        
        if(left_end) {
            left_end->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        
        return (right_end) ? right_end : left_end;
    }
};