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

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        for(int i=0;i<n;i++){
            if(A[i]>=target)
                return i;
        }
        return n;
    }
};