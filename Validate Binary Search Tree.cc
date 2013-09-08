/*
http://leetcode.com/onlinejudge#question_98

Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(!root) return true;
        stack<TreeNode *> s;
        
        int prev;
        while(root!=NULL) {
            prev = root->val;
            s.push(root->right);
            s.push(root);
            root=root->left;
        }
        
        prev = prev-1; // set to smaller than the left most child
        while(root!=NULL || !s.empty()) {
            if(root!=NULL) {
                if(prev >= root->val) return false;
                s.push(root->right);
                s.push(root);
                root=root->left;
            } else {
                root = s.top();
                s.pop();
                
                if(prev >= root->val) return false;
                prev = root->val;
                
                root = s.top();
                s.pop();
            }
        }
        
        return true;
    }
};

// ==========================================================================
class Solution {
public:
    bool isValidBST(TreeNode *root, int min=INT_MIN, int max=INT_MAX) {
        if(!root) return true;
        if(root->val<=min || root->val>=max) return false;
        return isValidBST(root->left, min, root->val) && 
               isValidBST(root->right, root->val, max);
    }
};