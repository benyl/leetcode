/*
http://leetcode.com/onlinejudge#question_112

Path Sum
Given a binary tree and a sum, determine if the tree has a 
root-to-leaf path such that adding up all the values along 
the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 
5->4->11->2 which sum is 22.

=======================================================================
http://leetcode.com/onlinejudge#question_113

Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each 
path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <stack>

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
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        
        // if leaf node = sum
        if(root->left==NULL && root->right==NULL && root->val==sum)
            return true;
        
        //check left subtree
        if(root->left && hasPathSum(root->left, sum-root->val))
            return true;
            
        //check right subtree
        if(root->right && hasPathSum(root->right, sum-root->val))
            return true;
            
        return false;
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        if(!root) return result;
        
        vector<TreeNode *> path; // remember current path
        stack<pair <TreeNode *,TreeNode *> > s; // stack of node
        
        if(root->left==NULL && root->right==NULL && root->val==sum) {
            vector<int> valpath;
            valpath.push_back(root->val);
            result.push_back(valpath);
            return result;
        } else {
            path.push_back(root);
            if(root->right)
                s.push(make_pair(root->right, root));
            if(root->left)
                s.push(make_pair(root->left, root));
        } // end of: if(root->left==NULL && root->right==NULL ...
        
        while(!s.empty()) {
            TreeNode *child = s.top().first;
            TreeNode *parent = s.top().second;
            s.pop();
            
            while(path.size() && (path.back() != parent))
                path.pop_back();
                
            // if it's leaf node check path sum
            if(child->left==NULL && child->right==NULL) {
                int pathsum = 0;
                for(int i=0; i!=path.size(); i++)
                    pathsum += path[i]->val;
                pathsum += child->val;
                
                if(pathsum == sum) {
                    vector<int> valpath;
                    for(int i=0; i!=path.size(); i++)
                        valpath.push_back(path[i]->val);
                    valpath.push_back(child->val);
                    result.push_back(valpath);
                }
            } else {
                path.push_back(child);
                if(child->right)
                    s.push(make_pair(child->right, child));
                if(child->left)
                    s.push(make_pair(child->left, child));
            }
        } // end of: while(!s.empty())
        
        return result;
    }
};
