/*
Median of Two Sorted Arrays

http://leetcode.com/onlinejudge#question_4

There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 

The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // assume that m >= n
        if(m<n) return findMedianSortedArrays(B, n, A, m);
        
        if(n==0) { 
            if(m%2==1) return A[m/2];
            else return (A[m/2-1] + A[m/2])/2.0;
            }
        if(n==1) {
            if (m==1) return (A[0] + B[0])/2.0;
            if (m%2==1) return (A[m/2] + findMedian(A[m/2-1], A[m/2+1], B[0]))/2.0;
            else return findMedian(A[m/2-1], A[m/2], B[0]);
        }
        if(n==2) {
            if (m==2) return findMedian(A[0], A[1], B[0], B[1]);
            if (m%2==1) return findMedian(A[m/2], max(A[m/2-1], B[1]), min(A[m/2+1], B[0]));
            else return findMedian(A[m/2-1], A[m/2], min(A[m/2+1], B[0]), max(A[m/2-2], B[1]));
        }
        
        if(A[m/2] <= B[n/2]) {
            int minDel = (m%2==0) ? min(m/2-1, n/2+n%2-1) : min(m/2, n/2+n%2-1);
            return findMedianSortedArrays(A+minDel, m-minDel, B, n-minDel);
        } else {
            int minDel = (n%2==0) ? min(m/2+m%2-1, n/2-1) : min(m/2+m%2-1, n/2);
            return findMedianSortedArrays(A, m-minDel, B+minDel, n-minDel);
        }
    }
    
    double findMedian(int a, int b, int c) {
        int maxVal = max(a, max(b,c));
        int minVal = min(a, min(b,c));
        return (a+b+c-maxVal-minVal);
    }
    
    double findMedian(int a, int b, int c, int d) {
        int maxVal = max(a, max(b,max(c,d)));
        int minVal = min(a, min(b,min(c,d)));
        return (a+b+c+d-maxVal-minVal)/2.0;
    }
};