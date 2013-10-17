/*
Median of Two Sorted Arrays

http://leetcode.com/onlinejudge#question_4

There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 

The overall run time complexity should be O(log (m+n)).
*/


// =====================================================================
// recursive solution
// 196 milli secs pass large solution
// time complexity o(log(m+n)), space complexity (1)

/*
    make sure m < n
    // corner cases when m = 0, 1, 2
    
    if(mid_a == mid_b) {
        return mid_a
    } else if(mid_a < mid_b) {
        return findMedian(A+m/2, m/2, B, n-m/2);
    } else // mid_a >= mid_b {
        return findMedian(A, m/2, B+m/2, n-m/2);
    }
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


// =====================================================================
// extand solution to find kth element of two sorted arrays
// 200 milli secs pass large solution
// time complexity o(log(m+n)), space complexity (1)

class Solution {
public:
    double findKth(int a[], int m, int b[], int n, int k) {
        if (m > n) return findKth(b, n, a, m, k);
        
        if (m == 0) return b[k-1];
        if (k == 1) return min(a[0], b[0]);
        
        int pa = min(k/2, m), pb = k - pa;
        if (a[pa-1] < b[pb-1])
            return findKth(a+pa, m-pa, b, n, k-pa);
        else 
            return findKth(a, m, b+pb, n-pb, k-pb);
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m+n;
        if (total % 2 != 0)
            return findKth(A, m, B, n, total/2+1);
        else
            return ((double) findKth(A, m, B, n, total/2) + 
                     (double) findKth(A, m, B, n, total/2+1))/2;
    }
};

