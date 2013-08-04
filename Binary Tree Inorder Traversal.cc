/*
Binary Tree Inorder Traversal

http://leetcode.com/onlinejudge#question_94

Given a binary tree, return the inorder traversal of its nodes' values.

For example
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note Recursive solution is trivial, could you do it iteratively?
*/

#include <stdio.h>
#include <iostream>
#include <vector>
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

// ===============================================
// Recursive version
class Solution {
public:
    vector<int> inorderTraversalTrial(TreeNode *root) {
        vector<int> result;
        if(root != NULL) {
            result = inorderTraversalTrial(root->left);
            result.push_back(root->val);
            vector<int> post = inorderTraversalTrial(root->right);
            result.insert(result.end(), post.begin(), post.end());
        }
        return result;
    }
};

// ===============================================
// Iterative version
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *curr = root;
        stack<TreeNode *> mid_stk, right_stk;
        
        while(curr || !mid_stk.empty()) {
            if(curr) {
                right_stk.push(curr->right);
                mid_stk.push(curr);
                curr = curr->left;
            } else {
                result.push_back(mid_stk.top()->val);
                curr = right_stk.top();
                mid_stk.pop();
                right_stk.pop();
            }
        }
        
        return result;
    }
};


// ------------------------------------------------
// test code
template <class T>
void PrintVec(vector<T> vec)
{
  for(int i=0; i<vec.size(); i++)  
  {
    cout << vec[i];
    if(i!=vec.size()-1)
      cout << ", ";
  }
  cout << endl;
}

void main()
{
  TreeNode n1(1);
  TreeNode n2(2);
  TreeNode n3(3);
  
  n1.right = &n2;
  n2.left = &n3;
  TreeNode *root = &n1;
  
  Solution s;
  
  vector<int> result = s.inorderTraversal(root);
  PrintVec<int>(result);

  getchar();
}