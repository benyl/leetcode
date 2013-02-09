/*
Remove Element

http://leetcode.com/onlinejudge#question_27

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        while(A[n-1]==elem && n>0) n--;
        
        for(int i=0; i<n; i++)
            if(A[i]==elem) {
                A[i]=A[n-1];
                n--;
                while(A[n-1]==elem && n>0) n--;
            }
            
        return n;
    }
};