/*
http://leetcode.com/onlinejudge#question_101

Symmetric Tree

Given a binary tree, check whether it is a mirror of itself 
(ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
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
    // recursive version
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *a, TreeNode *b) {
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val != b->val) return false;
        
        return (isSymmetric(a->left, b->right) && 
                isSymmetric(a->right, b->left));
    }
    
    // iterative version
    bool isSymmetric2(TreeNode *root) {
        if(!root) return true;
        queue<TreeNode *> qa;
        queue<TreeNode *> qb;
        
        qa.push(root->left);
        qb.push(root->right);
        
        while(!qa.empty() && !qb.empty()) {
            TreeNode *a = qa.front();
            TreeNode *b = qb.front();
            qa.pop();
            qb.pop();
            
            if(!a && !b) continue;
            if(!a || !b) return false;
            if(a->val != b->val) return false;
            
            qa.push(a->left);
            qa.push(a->right);
            
            qb.push(b->right);
            qb.push(b->left);
        }
        
        return true;
    }
};