/*
First Missing Positive

http://leetcode.com/onlinejudge#question_41

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/


// ==========================================================
// 12 milli secs pass large judge
// time complexity o(n), space complexity o(1)

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // for each number in the array, move it to the related index, i.e. 1->A[0], 5 -> A[4]
        for(int i=0; i<n; ++i)
            while(A[i] >0 && A[i] <= n && A[A[i]-1]!=A[i])
                swap(A[A[i]-1], A[i]);
        
        // pass thru the array again to find the first value that A[i] != i
        for(int i=0; i<n; ++i)
            if(A[i] != i+1) return i+1;
            
        // return n+1 if every numbers are in place
        return n+1;
    }
};