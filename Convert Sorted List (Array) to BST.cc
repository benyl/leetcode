/*
http://leetcode.com/onlinejudge#question_108

Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert 
it to a height balanced BST.

For example:
Given the array: {1, 2, 3, 4, 5},

Return Balanced Binary Search Tree:
              3
            /   \
           1     5
          / \   /
         0   2 4

=======================================================================
http://leetcode.com/onlinejudge#question_109

Convert Sorted List to Binary Search Tree:

Given a singly linked list where elements are sorted in ascending order,
convert it to a height balanced BST.

For example:
Given the linked list: 1->2->3->4->5

Return Balanced Binary Search Tree:
              3
            /   \
           1     5
          / \   /
         0   2 4
*/

/*
              50
            /   \
         24       75
        /  \     /    \ 
       12   37   62   87
     6 18  31 43  56 68  81 93
   3       9
  1 5      8 11
 0 2 4 #  7 # 10 #
 
       5
  2        8
 1 4      7  9
0 # 3 #  6 # # # 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
 
// =======================================================================
// Convert Sorted Array to Binary Search Tree

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num, int n1=0, int n2=-1) {
        if(n2==-1) n2=num.size();
        if(n2<=n1) return NULL;
        
        int mid=(n1+n2)/2;
        TreeNode *root = new TreeNode(num[mid]);
        
        root->left = sortedArrayToBST(num, n1, mid);
        root->right = sortedArrayToBST(num, mid+1, n2);
        return root;
    }
};


// =======================================================================
// Convert Sorted List to Binary Search Tree

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        
        ListNode *pre=head, *run=head->next;
        while(run->next!=NULL && run->next->next!=NULL) {
            run = run->next; run = run->next;
            pre = pre->next;
        }
        
        TreeNode *root = new TreeNode(pre->next->val);
        root->right = sortedListToBST(pre->next->next);
        pre->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }
};