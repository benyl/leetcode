/*
Merge Sorted Array

http://leetcode.com/onlinejudge#question_88

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. 
The number of elements initialized in A and B are m and n respectively.

*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        while(n!=0)
            if(m!=0 && A[m-1]>B[n-1])
                A[m+n-1] = A[--m];
            else
                A[m+n-1] = B[--n];
    }
};