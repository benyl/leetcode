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

class Solution {
public:
    // Remove Duplicates from Sorted Array
    int removeDuplicates(int A[], int n) {
        if(n<2) return n;
        
        for(int i=n-1; i>0; i--)
            if(A[i]==A[i-1])
                A[i]=A[0];
        
        int k=1;
        for(int i=1; i<n; i++)
            if(A[i]!=A[0])
                A[k++]=A[i];
        
        return k;
    }
    
    // Remove Duplicates from Sorted Array II
    int removeDuplicates(int A[], int n) {
        if(n<3) return n;
        
        for(int i=n-1; i>1; i--)
            if(A[i]==A[i-2])
                A[i]=A[0];
        
        int k=2;
        for(int i=2; i<n; i++)
            if(A[i]!=A[0])
                A[k++]=A[i];
        
        return k;
    }
};