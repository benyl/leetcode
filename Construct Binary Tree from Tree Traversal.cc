/*
http://leetcode.com/onlinejudge#question_105

Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

=======================================================================
http://leetcode.com/onlinejudge#question_106

Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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

// =========================================================
// Construct Binary Tree from Preorder and Inorder Traversal
// pass large judge with 156 milli secs
// time complexity: o(n^2) worse case, space complexity: o(n) worse case

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, 
                        int pre=-1, int in=-1, int len=0) {
                        
        if(in==-1) { pre=0; in=0; len=inorder.size(); }
        if(len <= 0) return NULL;
        if(len == 1) return new TreeNode(inorder[in]);
        
        int privot = 0;
        while(inorder[in+privot] != preorder[pre]) ++privot;
        
        TreeNode *root = new TreeNode(inorder[in+privot]);
        
        root->left = buildTree(preorder, inorder, pre+1, in, privot);
        root->right = buildTree(preorder, inorder, pre+privot+1, in+privot+1, len-privot-1);
        
        return root;
    }
};

// ==========================================================
// Construct Binary Tree from Inorder and Postorder Traversal
// pass large judge with 156 milli secs
// time complexity: o(n^2) worse case, space complexity: o(n) worse case

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, 
                        int in=-1, int post=-1, int len=0) {
                        
        if(in==-1) { in=0; post=0; len=inorder.size(); }
        if(len <= 0) return NULL;
        if(len == 1) return new TreeNode(inorder[in]);
        
        int privot = 0;
        while(inorder[in+privot] != postorder[post+len-1]) ++privot;
        
        TreeNode *root = new TreeNode(inorder[in+privot]);
        
        root->left = buildTree(inorder, postorder, in, post, privot);
        root->right = buildTree(inorder, postorder, in+privot+1, post+privot, len-privot-1);
        
        return root;
    }
};