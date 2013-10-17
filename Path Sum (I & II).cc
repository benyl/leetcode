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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// ============================================
// Path Sum
//
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        sum -= root->val;
        if(!root->left && !root->right) // for leaf node
            return (sum==0);
        return hasPathSum(root->left, sum) ||
                hasPathSum(root->right, sum);
    }
};

// ============================================
// Path Sum II
// 

// version 1, one function
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(root==NULL) return vector<vector<int> >();
        
        // if is leaf node
        if(!root->left && !root->right && root->val==sum)
            return vector<vector<int> >(1, vector<int>(1, sum));
        
        // get the result of both left and right sub-tree
        vector<vector<int> > left = pathSum(root->left, sum-root->val);
        vector<vector<int> > right = pathSum(root->right, sum-root->val);
        
        // add the root node to paths
        for(int i=0; i<left.size(); ++i)
            left[i].insert(left[i].begin(), root->val);
        for(int i=0; i<right.size(); ++i)
            right[i].insert(right[i].begin(), root->val);
            
        vector<vector<int> > result;
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());
            
        return result;
    }
};


// version 2, avoid copying
class Solution {
public:
    vector<int> path; // store current path
    vector<vector<int> > result;
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        path.clear();
        result.clear();
        findPathSum(root, sum);
        return result;
    }
    
    void findPathSum(TreeNode *root, int sum) {
        if(!root) return;
        
        sum -= root->val;
        path.push_back(root->val); // save node in path
        
        if(!root->left && !root->right && sum==0) // leaf node
            result.push_back(path);
        
        findPathSum(root->left, sum);
        findPathSum(root->right, sum);
        
        path.pop_back(); // back tracking
    }
};