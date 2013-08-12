/*
http://leetcode.com/onlinejudge#question_102

Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

=======================================================================
http://leetcode.com/onlinejudge#question_107

Binary Tree Level Order Traversal II

Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).


For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7]
  [9,20],
  [3],
]

=======================================================================
http://leetcode.com/onlinejudge#question_103

Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
     / \
   15   7
return its zigzag level order traversal as
[
  [3],
  [20,9],
  [15,7]
]
*/

#include <stdio.h>
#include <iostream>
#include <vector>
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
  // ===============================================================
  // Binary Tree Level Order Traversal
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > result;
    queue<pair<int, TreeNode *> > nqueue; // queue of node with level
    nqueue.push(make_pair(0, root));
    
    while(!nqueue.empty()) {
      int level = nqueue.front().first;
      TreeNode *p = nqueue.front().second;
      nqueue.pop();
      
      if(p!=NULL) {
        nqueue.push(make_pair(level+1, p->left));
        nqueue.push(make_pair(level+1, p->right));
        
        if(result.size() < level+1)
          result.push_back(vector<int>());
        
        result[level].push_back(p->val);
      } // end of: if(p!=null)
    } // end of: while(!nqueue.empty())
    
    return result;
  }// end of: levelOrder(TreeNode *root)

  
  // ===============================================================
  // Binary Tree Level Order Traversal II
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > result;
    queue<pair<int, TreeNode *> > nqueue; // queue of node with level
    nqueue.push(make_pair(0, root));
    
    while(!nqueue.empty()) {
      int level = nqueue.front().first;
      TreeNode *p = nqueue.front().second;
      nqueue.pop();
      
      if(p!=NULL) {
        nqueue.push(make_pair(level+1, p->left));
        nqueue.push(make_pair(level+1, p->right));
        
        if(result.size() < level+1)
          result.push_back(vector<int>());
        
        result[level].push_back(p->val);
      } // end of: if(p!=null)
    } // end of: while(!nqueue.empty())
    
    reverse(result.begin(), result.end());
	return result;
  }// end of: levelOrderBottom(TreeNode *root) 

  // ===============================================================
  // Binary Tree Zigzag Level Order Traversal
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > result;
    queue<pair<int, TreeNode *> > nqueue; // queue of node with level
    nqueue.push(make_pair(0, root));
    
    while(!nqueue.empty()) {
      int level = nqueue.front().first;
      TreeNode *p = nqueue.front().second;
      nqueue.pop();
      
      if(p!=NULL) {
        nqueue.push(make_pair(level+1, p->left));
        nqueue.push(make_pair(level+1, p->right));
        
        if(result.size() < level+1)
          result.push_back(vector<int>());
        
        result[level].push_back(p->val);
      } // end of: if(p!=null)
    } // end of: while(!nqueue.empty())
    
    for(int i=1; i<result.size(); i+=2)
      reverse(result[i].begin(), result[i].end());
      
    return result;
  }// end of: zigzagLevelOrder(TreeNode *root)  
};


//========================================================
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
  TreeNode n1(3);
  TreeNode n2(9);
  TreeNode n3(20);
  TreeNode n4(15);
  TreeNode n5(7);
  
  n1.left  = &n2;
  n1.right = &n3;
  n3.left  = &n4;
  n3.right = &n5;
  TreeNode *root = &n1;
  
  Solution s;
  
  vector<vector<int> > result1 = s.levelOrder(root);
  cout << endl << "result1: [" << endl;
  for(int i=0; i<result1.size(); i++)
  {
    cout << " ";
    PrintVec<int>(result1[i]);
  }
  cout << "]" << endl;


  vector<vector<int> > result2 = s.levelOrderBottom(root);
  cout << endl << "result2: [" << endl;
  for(int i=0; i<result2.size(); i++)
  {
    cout << " ";
    PrintVec<int>(result2[i]);
  }
  cout << "]" << endl;
  
  getchar();
}