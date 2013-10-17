/*
Search for a Range

http://leetcode.com/onlinejudge#question_34

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/


// ==========================================================
// use binary search
// 60 milli secs pass large judge
// time complexity o(n), space complexity o(1)

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2, -1);
        
        // search lower bound
        for(int start=0, end=n-1; start<=end; ) {
            int mid = (start+end)/2;
            if(A[mid]<target)
                start = mid+1;
            else if(A[mid]>target)
                end = mid-1;
            else if (mid==0 || A[mid-1]<target) // Lower bound
                { result[0] = mid; break; }
            else // A[mid-1] == A[mid] == target, jump left
                end = mid-1;
        }
        
        if(result[0] == -1) return result;
        
        // search upper bound
        for(int start=result[0], end=n-1; start<=end; ) {
            int mid = (start+end)/2;
            if(A[mid]<target)
                start = mid+1;
            else if(A[mid]>target)
                end = mid-1;
            else if (mid==n-1 || A[mid+1]>target) // Upper bound
                { result[1] = mid; break; }
            else // A[mid+1] == A[mid] == target, jump right
                start = mid+1;
        }
        
        return result;
    }
};