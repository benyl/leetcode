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

// use dynamic programming and only two pass
// 44 milli secs pass large set
// time complexity o(n), space complexity o(n)
class Solution {
public:
    int trap(int A[], int n) {
        if(n<3) return 0;
        vector<int> left_bound(n, 0);
        
        // 1) 1->n: search height of max left bound for each bar
        left_bound[0] = A[0];
        for(int i=1; i<n; i++)
            left_bound[i] = max(left_bound[i-1], A[i-1]);
        
        // 2) n->1: search height of max right bound for each bar
        // 3) water[i] = min(right_bound, left_bound) - A[i]
        //    no water trap if if bound is shorter than A[i]
        int right_bound = A[n-1], water = 0;
        for(int i=n-2; i>0; i--) {
            int bound = min(right_bound, left_bound[i]);
            water += (bound > A[i]) ? (bound - A[i]) : 0;
            right_bound = max(A[i], right_bound); // update right bound
        }
        
        return water;
    }
};