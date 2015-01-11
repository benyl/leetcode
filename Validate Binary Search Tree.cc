/*
http://leetcode.com/onlinejudge#question_98

Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode *root) {
        if(!root) return true;
        stack<TreeNode *> s;
        
        int prev;
        while(root!=NULL) {
            prev = root->val;
            s.push(root->right);
            s.push(root);
            root=root->left;
        }
        
        prev = prev-1; // set to smaller than the left most child
        while(root!=NULL || !s.empty()) {
            if(root!=NULL) {
                if(prev >= root->val) return false;
                s.push(root->right);
                s.push(root);
                root=root->left;
            } else {
                root = s.top();
                s.pop();
                
                if(prev >= root->val) return false;
                prev = root->val;
                
                root = s.top();
                s.pop();
            }
        }
        
        return true;
    }
};

// ==========================================================================
// version 1, pass with 19 ms
// resurcive, space complexity is o(n), time complexity is o(n), for n is number of tree nodes (that is, 2^h)
class Solution {
public:
    bool isValidBST(TreeNode *root, int min = 0, int max = 0, 
                    bool has_min = false, bool has_max = false) {
        if(!root) return true;
        if(has_min && root->val<=min) return false; // check if min bound exists and value is smaller than min bound
        if(has_max && root->val>=max) return false; // check if max bound exists and value is bigger than max bound
        return isValidBST(root->left, min, root->val, has_min, true) && 
               isValidBST(root->right, root->val, max, true, has_max); // passdown the bound
    }
};

// version 2, pass with 64 ms, slower than version 1 because pointer address access, but with lesser parameters.
// resurcive, space complexity is o(n), time complexity is o(n), for n is number of tree nodes (that is, 2^h)
class Solution {
public:
    bool isValidBST(TreeNode *root, TreeNode *min=NULL, TreeNode *max=NULL) {
        if(!root) return true;
        if((min && root->val <= min->val) || (max && root->val >= max->val)) return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};
