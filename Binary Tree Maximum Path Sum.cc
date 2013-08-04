/*
http://leetcode.com/onlinejudge#question_124

Binary Tree Maximum Path Sum
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example
Given the below binary tree,
       1
      / \
     2   3
Return 6.
*/

#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>

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
	int maxPathSum(TreeNode *root) {
		queue<TreeNode *> nqueue;
		stack<TreeNode *> nstack;
		
		if(root==NULL) return 0;
		
		nqueue.push(root);
		
		while(!nqueue.empty())
		{
			TreeNode *p = nqueue.front();
			nqueue.pop();
		
			if(p!=NULL)
			{
				nqueue.push(p->left);
				nqueue.push(p->right);
				nstack.push(p);
				//cout << p->val << endl;
			}
		} // end of: while(!nqueue.empty())
		
		int maxPath = root->val;
		
		while(!nstack.empty())
		{
			TreeNode *p = nstack.top();
			nstack.pop();
		
			if(p==NULL) continue;
			
			//cout << p->val << ":";
			
			int maxSum = p->val; // max path sum that go thru p
			int maxSide = 0; // max path sum that end at p
			
			if(p->left!=NULL)
			{
				if(p->left->val > 0) 
					maxSum += p->left->val;

				if(p->left->val > maxSide) 
					maxSide = p->left->val;
			}
			
			if(p->right!=NULL)
			{
				if(p->right->val > 0) 
					maxSum += p->right->val;

				if(p->right->val > maxSide) 
					maxSide = p->right->val;
			}
			
			p->val += maxSide;
			//cout << maxSum << " " << maxSide << " " << p->val << endl;
			
			maxPath = (maxSum > maxPath) ? maxSum : maxPath;
		} // end of: while(!nstack.empty())
		
        return maxPath;
    } // end of: maxPathSum(TreeNode *root)
};

void main()
{
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
  
	n1.left  = &n2;
	n1.right = &n3;
	TreeNode *root = &n1;
  
	Solution s;
  
	int result = s.maxPathSum(root);
  
	cout << "result: " << result << endl;
  
	getchar();
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//====================================================================
#define MIN_INT -2147483647

class Solution {
public:
    int maxPathSum(TreeNode *root, int *maxRootSum=NULL) { // 1,2
        if(!root) { 
            if(maxRootSum) *maxRootSum=MIN_INT; 
            return MIN_INT;
        }
        
        int maxPathSumLeft, maxPathSumRight, maxRootSumLeft, maxRootSumRight;
        
        maxPathSumLeft = maxPathSum(root->left, &maxRootSumLeft); //2-2
        maxPathSumRight = maxPathSum(root->right, &maxRootSumRight); //min-min
        
        int result = root->val; //1
        if(root->left) result += maxRootSumLeft; // 1+2
        if(root->right) result += maxRootSumRight;
        
        if(root->left) result = max(result, maxPathSumLeft); //1+2
        if(root->right) result = max(result, maxPathSumRight);
        
        result = max(result, root->val); // 1+2
        
        if(maxRootSum) {
            *maxRootSum = max(maxRootSumLeft, maxRootSumRight);
            if(*maxRootSum != MIN_INT) *maxRootSum += root->val;
            else *maxRootSum = root->val;
            
            *maxRootSum = (*maxRootSum>0) ? *maxRootSum : 0;
        }
        
        return result; //0
    }
};