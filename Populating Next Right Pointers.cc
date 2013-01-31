/*
//----------------------------------------------
http://leetcode.com/onlinejudge#question_116

Populating Next Right Pointers in Each Node:

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree 
(ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

//----------------------------------------------
http://leetcode.com/onlinejudge#question_117

Populating Next Right Pointers in Each Node II:

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        
        queue<TreeLinkNode *> q1;
        queue<TreeLinkNode *> q2;
        
        queue<TreeLinkNode *> *curr = &q1;
        queue<TreeLinkNode *> *next = &q2;
        
        q1.push(root);
        
        while(!curr->empty())
        {
            TreeLinkNode *p = curr->front();
            curr->pop();
            if(p->left!=NULL) next->push(p->left);
            if(p->right!=NULL) next->push(p->right);
            
            if(!curr->empty())
                p->next = curr->front();
            else
            {
                queue<TreeLinkNode *> *temp = curr;
                curr = next;
                next = temp;
            }
        } // end of: while(!curr->empty())
    } // end of: connect(TreeLinkNode *root)
};