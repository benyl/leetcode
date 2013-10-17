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
                        int pre=0, int in=0, int len=-1) {
                        
        if(len==-1) len=inorder.size(); // initialize len
        if(len==0) return NULL;
        
        int pos = 0;
        while(inorder[in+pos] != preorder[pre]) ++pos;
        
        TreeNode *root = new TreeNode(inorder[in+pos]);
        root->left = buildTree(preorder, inorder, pre+1, in, pos);
        root->right = buildTree(preorder, inorder, pre+pos+1, in+pos+1, len-pos-1);
        
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
                        int in=0, int post=0, int len=-1) {
                        
        if(len==-1) len=inorder.size(); // initialize len
        if(len==0) return NULL;
        
        int pos = 0;
        while(inorder[in+pos] != postorder[post+len-1]) ++pos;
        
        TreeNode *root = new TreeNode(inorder[in+pos]);
        root->left = buildTree(inorder, postorder, in, post, pos);
        root->right = buildTree(inorder, postorder, in+pos+1, post+pos, len-pos-1);
        
        return root;
    }
};