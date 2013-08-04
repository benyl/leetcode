/*
Sum Root to Leaf Numbers

http://leetcode.com/onlinejudge#question_129

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

// push root to path (not null)
// for each node in stack, add to path (not null)
    // if not left and right child, is leaf node
        // print path
        // while path.last node is right child of it's parent, pop path.last from path
        // while path.last node has not right child, pop path.last from path
        // pop path.last (the first left child in path) from path, push the right child to path
    // if has left child, push left child to stack
    // else if has right child, push right child to stack

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
    int sumNumbers(TreeNode *root) {
        // use DFS search every leaf to node path
        int sum = 0;
        vector<TreeNode *> path;
        
        if(!root) return sum;
        
        path.push_back(root);
       
        while(path.size()!=0) {
            if(path.back()->left) {
                path.push_back(path.back()->left);
            } else if(path.back()->right){
                path.push_back(path.back()->right);
            } else {
                // if leaf node, print path and then pop nodes
                int num = 0;
                for(int i=0; i<path.size(); ++i)
                    num = num*10 + path[i]->val;
                sum += num;
                
                // pop nodes if node is right child
                int last = path.size() - 1;
                while(last!=0) {
                    if((path[last] == path[last-1]->right) || 
                    (!path[last-1]->right)) {
                        path.pop_back();
                        last--;
                    } else 
                        break;
                }
                
                path.pop_back();
                
                if(path.size()!=0)
                    path.push_back(path.back()->right);
            } // end of : if(path.back()->left) {
        } // end of : while(path.size()!=0) {
        
        return sum;
    }
};



// ===============================================

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
    int sumNumbers(TreeNode *root, int path=0) {
        if(!root) return 0;
        
        path *= 10;
        path += root->val;
        
        // if leaf
        if(!root->left && !root->right)
            return path;
        else {
            int result=0;
            result += sumNumbers(root->left, path);
            result += sumNumbers(root->right, path);
            return result;
        }
    }
};
