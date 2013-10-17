/*
http://leetcode.com/onlinejudge#question_110

Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary 
tree in which the depth of the two subtrees of every node never differ 
by more than 1.
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
    bool isBalanced(TreeNode *root) {
        return (getTreeHeight(root)!=-1);
    }
    
    // get belance tree height
    int getTreeHeight(TreeNode *root) {
        if(root==NULL) return 0;
        
        int lh = getTreeHeight(root->left);
        if(lh==-1) return -1;
        int rh = getTreeHeight(root->right);
        if(rh==-1) return -1;
        
        if(lh-rh>1 || rh-lh>1) return -1; // unbalanced
        return max(lh, rh) + 1;
    }
};


// version 2, use pointer
class Solution {
public:
    bool isBalanced(TreeNode *root, int *height = NULL) {
        if(!root) return true;
        
        int lh=0, rh=0;
        if(!isBalanced(root->left, &lh) || !isBalanced(root->right, &rh) || abs(lh-rh)>1)
            return false;
            
        if(height) *height = max(lh, rh) + 1;
        return true;
    }
};