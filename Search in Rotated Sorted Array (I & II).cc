/*
Search in Rotated Sorted Array

http://leetcode.com/onlinejudge#question_33

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

=======================================================================

Search in Rotated Sorted Array II

http://leetcode.com/onlinejudge#question_81

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/


#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Search in Rotated Sorted Array
    int search(int A[], int n, int target) {
        int rotate=0; // find the rotate point
        if (A[0] > A[n-1]) {
            int min=0, max=n;
            while(min<=max) {
                int mid = (min+max)/2;
                if(A[mid]>=A[0])
                    min = mid+1;
                else if(A[mid-1]<A[0])
                    max = mid-1;
                else // A[mid]<A[0] && A[mid-1]>=A[0]
                    {rotate = mid;break;}
            }
        }
        
        int min=0, max=n;
        while(min<=max) {
            int mid = (min+max)/2;
            if(A[(mid+rotate)%n]<target)
                min = mid+1;
            else if(A[(mid+rotate)%n]>target)
                max = mid-1;
            else
                return (mid+rotate)%n;
        }
        
        return -1;
    }
    
    // Search in Rotated Sorted Array II
    bool search(int A[], int n, int target) {
        if(n<=0) return false;
        if(n==1) return A[0] == target;
        
        int mid = n/2;
        bool left=false, right=false;
        
        if(A[mid] == target) return true;
        if(A[0] == target) return true;
        if(A[n-1] == target) return true;
        
        if(A[0] == A[mid] && A[mid] == A[n-1]) {
            left = true; right = true;
        } else if(A[0] == A[mid]) {
            right = true;
        } else if(A[n-1] == A[mid]) {
            left = true;
        } else if(A[0] < A[mid] && A[mid] < target) {
            right = true;
        } else if(A[0] > A[mid] && A[mid] > target) {
            left = true;
        } else if(A[0] > target) {
            right = true;
        } else {
            left = true;
        }
        
        if(left) left = search(A, mid, target);
        if(left) return true;
        
        if(right) right = search(A+mid+1, n-mid-1, target);
        return right;
    }
};


void main()
{
    int input[] = {4, 5, 6, 7, 0, 1, 2, 3};
    int target = 0;

    Solution sol;
    cout << sol.search(input, sizeof(input)/sizeof(int), target) << endl;
    getchar();
}


// ==============================================
// Search in Rotated Sorted Array
// clear version
// time complexity o(log(n)), space complexity o(1)

class Solution {
public:
    int search(int A[], int n, int target) {
        if(n==0) return -1;
        for(int start=0, end=n-1; start<=end;) {
            int mid = (start+end)/2;
            if(A[mid]==target) return mid;
            if(A[mid]>=A[start]) { // rotate point is in right half
                if(target>=A[start] && target<=A[mid]) // in the left range
                    end = mid-1;
                else
                    start = mid+1;
            } else { // rotate point is in left half
                if(target>=A[mid] && target<=A[end]) // in the right range
                    start = mid+1;
                else
                    end = mid-1;
            }
        }
        return -1;
    }
};

// ==============================================
// Search in Rotated Sorted Array II
// clear version
// time complexity o(log(n)), worse case o(n), space complexity o(1)

class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n==0) return false;
        if(n==1) return A[0] == target;
        if(A[n/2]==target) return true;
        
        if(A[n/2]==A[0] && A[n/2]==A[n-1]) // search both site
            return search(A, n/2, target) || search(A+n/2, n-n/2, target);
        
        if(A[n/2]>=A[0] && A[n/2]>=A[n-1]) { // rotate point is in right half
            if(target>=A[0] && target<=A[n/2]) // in the left range
                return search(A, n/2, target);
            else
                return search(A+n/2, n-n/2, target);
        } else { // rotate point is in left half
            if(target>=A[n/2] && target<=A[n-1]) // in the right range
                return search(A+n/2, n-n/2, target);
            else
                return search(A, n/2, target);
        }
    }
};