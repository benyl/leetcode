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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */ 
 
// iterative version
class Solution {
public:
	int maxPathSum(TreeNode *root) {
		queue<TreeNode *> nqueue;
		stack<TreeNode *> nstack;
		
		if(root==NULL) return 0;
		
		nqueue.push(root);
		
		while(!nqueue.empty()) {
			TreeNode *p = nqueue.front();
			nqueue.pop();
		
			if(p!=NULL) {
				nqueue.push(p->left);
				nqueue.push(p->right);
				nstack.push(p);
			}
		} // end of: while(!nqueue.empty())
		
		int maxPath = root->val;
		
		while(!nstack.empty()) {
			TreeNode *p = nstack.top();
			nstack.pop();
		
			if(p==NULL) continue;
			
			int maxSum = p->val; // max path sum that go thru p
			int maxSide = 0; // max path sum that end at p
			
			if(p->left!=NULL) {
				if(p->left->val > 0) 
					maxSum += p->left->val;

				if(p->left->val > maxSide) 
					maxSide = p->left->val;
			}
			
			if(p->right!=NULL) {
				if(p->right->val > 0) 
					maxSum += p->right->val;

				if(p->right->val > maxSide) 
					maxSide = p->right->val;
			}
			
			p->val += maxSide;
			
			maxPath = (maxSum > maxPath) ? maxSum : maxPath;
		} // end of: while(!nstack.empty())
		
        return maxPath;
    } // end of: maxPathSum(TreeNode *root)
};


// recursive version
class Solution {
public:
    int maxPathSum(TreeNode *root, int *rootSum=NULL) {
        if(!root) return INT_MIN;
        
        int lrs=0, rrs=0; // max sum from root
        int lps = maxPathSum(root->left, &lrs);
        int rps = maxPathSum(root->right, &rrs);
        int sum = root->val + max(lrs, 0) + max(rrs, 0);
        sum = max({sum, lps, rps});
        
        if(rootSum)
           *rootSum = root->val + max({0, lrs, rrs});
        
        return sum;
    }
};


// test code
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
