/*
http://leetcode.com/onlinejudge#question_100

Same Tree

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical 
and the nodes have the same value.

=======================================================================

http://leetcode.com/onlinejudge#question_101

Symmetric Tree

Given a binary tree, check whether it is a mirror of itself 
(ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
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
 

//====================================================
// Same Tree
//====================================================
 
// Same Tree : recursive version
class Solution {
public:
    bool isSameTree(TreeNode *a, TreeNode *b) {
        if(!a && !b) return true;
        if(!a || !b || a->val != b->val) return false;
        return (isSameTree(a->left, b->left) && 
                isSameTree(a->right, b->right));
    }
}

// Same Tree : iterative version
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> que;
        que.push(p);
        que.push(q);
        
        while(!que.empty()) {
            p = que.front(); que.pop();
            q = que.front(); que.pop();
            
            if(!p && !q) continue;
            if(!p || !q || p->val!=q->val) return false;
            
            que.push(p->left);
            que.push(q->left);

            que.push(p->right);
            que.push(q->right);
        }
        
        return true;
    }
};

//====================================================
// Symmetric Tree
//====================================================

// Symmetric Tree : recursive version
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *a, TreeNode *b) {
        if(!a && !b) return true;
        if(!a || !b || a->val != b->val) return false;
        return (isSymmetric(a->left, b->right) && 
                isSymmetric(a->right, b->left));
    }
};


// Symmetric Tree: iterative version
class Solution {
public:
    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if(!root) return true;
    
        queue<TreeNode *> que;
        que.push(root->left);
        que.push(root->right);
        
        while(!que.empty()) {
            TreeNode *p = que.front(); que.pop();
            TreeNode *q = que.front(); que.pop();
            
            if(!p && !q) continue;
            if(!p || !q || p->val!=q->val) return false;
            
            que.push(p->left);
            que.push(q->right);

            que.push(p->right);
            que.push(q->left);
        }
        
        return true;
    }
};