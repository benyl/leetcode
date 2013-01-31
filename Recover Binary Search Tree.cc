/*
http://leetcode.com/onlinejudge#question_99

Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. 
Could you devise a constant space solution?

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
    // use O(n) space
    vector<TreeNode *> nodes;
    
    // inorder traversal
    void traversal(TreeNode *root) {
        if(!root) return;
        traversal(root->left);
        nodes.push_back(root);
        traversal(root->right);
    }
    
    // use O(n) space version
    void recoverTree(TreeNode *root) {
        nodes.clear();
        traversal(root);
        
        TreeNode *a=NULL, *b=NULL;
        
        for(int i=0; i<nodes.size()-1; i++)
            if(nodes[i]->val>nodes[i+1]->val) {
                a = nodes[i]; break;
            }
        
        for(int i=nodes.size()-1; i>0; i--)
            if(nodes[i]->val<nodes[i-1]->val) {
                b = nodes[i]; break;
            }
            
        if(a && b) {
            int temp = a->val;
            a->val = b->val;
            b->val = temp;
        }
    }
    
    // use constraint space
    void treeWalk(TreeNode* root, TreeNode*& prv, 
                  TreeNode*& first, TreeNode*& second) {
        if(!root) return;
        
        treeWalk(root->left,prv,first,second);
        
        if((prv!=NULL)&&(prv->val>root->val)) {
            if(!first) first=prv;
            second=root;
        }
        
        prv=root;
        treeWalk(root->right,prv,first,second);
        
    }
 
    void recoverTree2(TreeNode *root) {
        TreeNode *first=NULL, *second=NULL, *prv=NULL;
        treeWalk(root,prv,first,second);
        int tmp=first->val;
        first->val=second->val;
        second->val=tmp;
    }
};