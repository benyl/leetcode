/*
Trapping Rain Water

http://leetcode.com/onlinejudge#question_42

Given n non-negative integers representing an elevation map where the 
width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. 
*/

class Solution {
public:
    int trap(int A[], int n) {
        if(n<3) return 0;
        vector<int> maxleft(n, 0);
        
        // 0->n: search max left height for each node
        maxleft[0] = A[0];
        for(int i=1; i<n; i++)
            maxleft[i] = max(maxleft[i-1], A[i-1]);
        
        // n->0: water += min(right bound, maxleft) - A[i]
        //       right bound = max(A[i], right bound);
        int rightbound = A[n-1];
        int water = 0;
        
        for(int i=n-2; i>0; i--) {
            int bound = min(rightbound, maxleft[i]);
            water += bound - min(A[i], bound);
            rightbound = max(A[i], rightbound); // update right bound
        }
        
        return water;
    }
};