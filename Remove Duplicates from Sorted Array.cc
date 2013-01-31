/*
Remove Duplicates from Sorted Array

http://leetcode.com/onlinejudge#question_26

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        
        for(int i=n-1; i>0; i--)
            if(A[i]==A[i-1])
                A[i]=A[0];
        
        int k=1;
        for(int i=1; i<n; i++)
            if(A[i]!=A[0])
                A[k++]=A[i];
        
        return k;
    }
};