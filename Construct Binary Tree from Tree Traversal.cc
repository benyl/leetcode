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

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    // Construct Binary Tree from Preorder and Inorder Traversal
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() != inorder.size() || 
           !preorder.size() || !inorder.size())
            return NULL;
            
        TreeNode *root = new TreeNode(preorder.front());
        
        if(inorder.size() == 1) {
            return root;
        } else if(preorder.front() == inorder.front()) {
            preorder.erase(preorder.begin());
            inorder.erase(inorder.begin());
            root->right = buildTree(preorder, inorder);
            return root;
        } else if(preorder.front() == inorder.back()) {
            preorder.erase(preorder.begin());
            inorder.erase(inorder.end()-1);
            root->left = buildTree(preorder, inorder);
            return root;
        } else {
            // iterin points to the root node in inorder
            vector<int>::iterator iterin = 
                find(inorder.begin(), inorder.end(), preorder.front());
            
            // iterpre points to the first right node in preorder
            vector<int>::iterator iterpre = 
                preorder.begin() + (iterin - inorder.begin()) + 1;
        
            vector<int> pre1(preorder.begin()+1, iterpre);
            vector<int> pre2(iterpre, preorder.end());
            
            vector<int> in1(inorder.begin(), iterin);
            vector<int> in2(iterin+1, inorder.end());
            
            root->left = buildTree(pre1, in1);
            root->right = buildTree(pre2, in2);
            
            return root;
        }
    }
    
    // Construct Binary Tree from Inorder and Postorder Traversal
    TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder) {
        if(postorder.size() != inorder.size() || 
           !postorder.size() || !inorder.size())
            return NULL;
            
        TreeNode *root = new TreeNode(postorder.back());
        
        if(inorder.size() == 1) {
            return root;
        } else if(postorder.back() == inorder.front()) {
            postorder.erase(postorder.end()-1);
            inorder.erase(inorder.begin());
            root->right = buildTree(inorder, postorder);
            return root;
        } else if(postorder.back() == inorder.back()) {
            postorder.erase(postorder.end()-1);
            inorder.erase(inorder.end()-1);
            root->left = buildTree(inorder, postorder);
            return root;
        } else {
            // iterin points to the root node in inorder
            vector<int>::iterator iterin = 
                find(inorder.begin(), inorder.end(), postorder.back());
            
            // iterpost points to the first right node in postorder
            vector<int>::iterator iterpost = 
                postorder.begin() + (iterin - inorder.begin());
        
            vector<int> post1(postorder.begin(), iterpost);
            vector<int> post2(iterpost, postorder.end()-1);
            
            vector<int> in1(inorder.begin(), iterin);
            vector<int> in2(iterin+1, inorder.end());
            
            root->left = buildTree(in1, post1);
            root->right = buildTree(in2, post2);
            
            return root;
        }
    }
};