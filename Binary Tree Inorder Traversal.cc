/*
Binary Tree Inorder Traversal

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

class Solution {
public:
  // Recursive version
  vector<int> inorderTraversalTrial(TreeNode *root) {
    vector<int> result;
    if(root != NULL)
    {
      vector<int> pre = inorderTraversalTrial(root->left);
      vector<int> post = inorderTraversalTrial(root->right);
      result.insert(result.end(), pre.begin(), pre.end());
      result.push_back(root->val);
      result.insert(result.end(), post.begin(), post.end());
    }
       
    return result;
  }

  // Iterative version
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    TreeNode *p = root;
    stack<TreeNode *> nstack;

    if(root== NULL) return result;
  
    while(p!=NULL || !nstack.empty())
    {
      if(p!=NULL)
      {
        nstack.push(p->right);
        nstack.push(p);
        p = p->left;
      }
      else if(!nstack.empty())
      {
        p=nstack.top();
        nstack.pop();
        result.push_back(p->val);
        p=nstack.top();
        nstack.pop();
      }
    }
  
    return result;
  }  
};

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