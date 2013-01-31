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


#include <stdio.h>
#include <iostream>
#include <vector>
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
    int numTrees(int n) {
        vector<int> num(n+1, 0);
        num[0] = 1;
        num[1] = 1;
        for(int i=2; i<=n; i++) {
            for(int k=0; k<i; k++){
                num[i] += num[k]*num[i-k-1];
            }
        }
        
        return num[n];
    }
    
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(n, 1);
    }
    
    vector<TreeNode *> generateTrees(int n, int start) {
        vector<TreeNode *> result;
        if(n==0) result.push_back(NULL);
        else if(n==1) result.push_back(new TreeNode(start));
        else {
            for(int i=0; i<n; i++) {
                vector<vector<TreeNode *> > left;
                vector<vector<TreeNode *> > right;
                left.push_back(generateTrees(i, start));
                right.push_back(generateTrees(n-i-1, start+i+1));
                
                int leftnum = left[0].size();
                int rightnum = right[0].size();
                
                for(int j=1; j<rightnum; j++)
                    left.push_back(generateTrees(i, start));
                
                for(int j=1; j<leftnum; j++)
                    right.push_back(generateTrees(n-i-1, start+i+1));
                
                for(int j=0; j<rightnum; j++) {
                for(int k=0; k<leftnum; k++) {
                        TreeNode *root = new TreeNode(start+i);
                        root->left = left[j][k];
                        root->right = right[k][j];
                        result.push_back(root);
                }
                }
            }
        }
        return result;
    }
};


void main()
{
    Solution sol;
    
	int n = 2;
    vector<TreeNode *> result = sol.generateTrees(n);
	cout << sol.numTrees(n) << ":" << result.size() << endl;
    getchar();
}
