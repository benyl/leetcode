/*
Remove Duplicates from Sorted Array

http://leetcode.com/onlinejudge#question_26

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

=======================================================================

Remove Duplicates from Sorted Array II

http://leetcode.com/onlinejudge#question_80

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

// =================================================
// Remove Duplicates from Sorted Array I
// 100 milli secs pass lerge judge
// time complexity o(n), space complexity o(1)

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<2) return n;
        int anchor=0;
        for(int i=1; i<n; ++i)
            if(A[anchor]!=A[i]) // check no duplicates
                A[++anchor]=A[i]; // copy the node into new place
        return anchor+1;
    }
};

// =================================================
// Remove Duplicates from Sorted Array II, allow twice duplicates
// 84 milli secs pass lerge judge
// time complexity o(n), space complexity o(1)

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<3) return n;
        int anchor=1;
        for(int i=2; i<n; ++i)
            if(A[anchor]!=A[i] || A[anchor]!=A[anchor-1]) // allow twice duplicates
                A[++anchor] = A[i]; // copy the node into new place
        return anchor+1;
    }
};