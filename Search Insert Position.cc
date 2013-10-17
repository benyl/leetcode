/*
Search Insert Position

http://leetcode.com/onlinejudge#question_35

Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
*/

// =====================================================
// simple solution
// 40 milli secs pass large judge
// time comlexity o(n), space complexity (1)

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        for(int i=0;i<n;i++)
            if(A[i]>=target)
                return i;
        return n;
    }
};

// =====================================================
// binary search solution
// 40 milli secs pass large judge
// time comlexity o(log n), space complexity (1)

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(target<=A[0]) return 0;
        if(target>A[n-1]) return n;
        
        int begin=0, end=n-1;
        while(begin<=end) {
            int mid = (begin+end)/2;
            if(A[mid] < target) {
                if(A[mid+1] >= target) return mid + 1;
                begin = mid + 1;
            } else {
                if(A[mid-1] < target) return mid;
                end = mid - 1;
            }
        }
        return -1;
    }
};