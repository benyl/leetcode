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
    int getTreeHeight(TreeNode *root)
    {
        int height = 0;
        
        if(root!=NULL)
        {
            int lh = getTreeHeight(root->left);
            int rh = getTreeHeight(root->right);
            
            if(lh-rh>1 || rh-lh>1 || lh==-1 || rh==-1)
                height = -1; // unbalanced
            else
                height = ((lh>rh)?lh:rh) + 1;
        };
        
        return height;
    }
};