

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
// time complexity: o(n), space complexity: log(n) in stack, o(n) in result
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if(!root) return vector<int> ();
        
        vector<int> left = inorderTraversal(root->left);
        left.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        left.insert(left.end(), right.begin(), right.end());
        
        return left;
    }
};

// ===============================================
// Iterative version
// time complexity: o(n), space complexity: log(n) in stack, o(n) in result
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stk;
        
        while(root || !stk.empty()) {
            if(root) {
                stk.push(root->right);
                stk.push(root);
                root = root->left;
            } else {
                result.push_back(stk.top()->val);
                stk.pop();
                root = stk.top();
                stk.pop();
            }
        }
        
        return result;
    }
};


// ================================================
// Iterative version II (morris method, threading traversal)
// time complexity: o(n), space complexity: o(1) in function, o(n) in result

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *p = root;
        while(p!=NULL) {
            if(p->left==NULL) {
                result.push_back(p->val);
                p = p->right;
            } else {
                TreeNode *prev = p->left;
                while(prev->right!=NULL && prev->right!=p)
                    prev = prev->right;
                if(prev->right==NULL) {
                    prev->right = p;
                    p = p->left;
                } else {
                    result.push_back(p->val);
                    prev->right = NULL;
                    p = p->right;
                }
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