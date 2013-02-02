/*
Search in Rotated Sorted Array

http://leetcode.com/onlinejudge#question_33

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/


#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
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
    
    
    int search2(int A[], int n, int target) {
        for(int i=0; i<n; i++)
            if(A[i]==target) return i;
            
        return -1;
    }
};


void main()
{
	int input[] = {4, 5, 6, 7, 0, 1, 2, 3};
	int target = 0;

	Solution sol;
	cout << sol.search(input, 7, target) << endl;
	getchar();
}