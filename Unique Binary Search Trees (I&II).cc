/*
http://leetcode.com/onlinejudge#question_96

Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

=======================================================================
http://leetcode.com/onlinejudge#question_96

Unique Binary Search Trees II

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/


/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// =======================================================
// Unique Binary Search Trees
// use dynamic programming

class Solution {
public:
    int numTrees(int n) {
        vector<int> num(n+1, 0);
        num[0] = 1; num[1] = 1;
        
        for(int i=2; i<=n; ++i)
            for(int j=1; j<=i; ++j)
                num[i] += num[j-1] * num[i-j];
        
        return num[n];
    }
};

// =======================================================
// Unique Binary Search Trees II

class Solution {
public:
    vector<TreeNode *> generateTrees(int n, int start=1) {
        if(n==0) return vector<TreeNode *>(1, (TreeNode *) NULL);
        if(n==1) return vector<TreeNode *>(1, new TreeNode(start));
        
        vector<TreeNode *> result;
        for(int i=1; i<=n; ++i) {
            vector<TreeNode *> left = generateTrees(i-1, start);
            vector<TreeNode *> right = generateTrees(n-i, start+i);
            
            for(int l=0; l<left.size(); ++l)
            for(int r=0; r<right.size(); ++r) {
                TreeNode *root = new TreeNode(start+i-1);
                root->left = left[l];
                root->right = right[r];
                result.push_back(root);
            }
        }
        
        return result;
    }
};