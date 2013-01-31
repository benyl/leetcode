/*

http://leetcode.com/onlinejudge#question_100

Same Tree

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical 
and the nodes have the same value.

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
    bool isSameTree(TreeNode *a, TreeNode *b) {
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val != b->val) return false;
        
        return (isSameTree(a->left, b->left) && 
                isSameTree(a->right, b->right));
    }
    
    // iterative version
    bool isSameTree2(TreeNode *a, TreeNode *b) {
        queue<TreeNode *> qa;
        queue<TreeNode *> qb;
        qa.push(a);
        qb.push(b);
        
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
            
            qb.push(b->left);
            qb.push(b->right);
        }
        
        return true;
    }
};