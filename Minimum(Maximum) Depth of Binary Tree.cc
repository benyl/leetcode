/*
http://leetcode.com/onlinejudge#question_111

Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest 
path from the root node down to the nearest leaf node.

=======================================================================
http://leetcode.com/onlinejudge#question_104

Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest 
path from the root node down to the farthest leaf node.
*/

#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>
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
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        queue<pair<TreeNode *, int> > q;
        q.push(make_pair(root,1));
        
        while(!q.empty()) {
            TreeNode *node = q.front().first;
            int depth = q.front().second;
            q.pop();
            
            if(!node->left && !node->right)
                return depth;
                
            if(node->right)
                q.push(make_pair(node->right,depth+1));
            if(node->left)
                q.push(make_pair(node->left,depth+1));
        }
    }
    

    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        queue<pair<TreeNode *, int> > q;
        q.push(make_pair(root,1));
        int max = 1;
        
        while(!q.empty()) {
            TreeNode *node = q.front().first;
            int depth = q.front().second;
            q.pop();
            
            if(!node->left && !node->right)
                max = (depth>max)?depth:max;
                
            if(node->right)
                q.push(make_pair(node->right,depth+1));
            if(node->left)
                q.push(make_pair(node->left,depth+1));
        }
        
        return max;
    }
};



// =====================================================
// recursive version
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(!root->left) return minDepth(root->right) + 1;
        if(!root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    
    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};