/*
Maximum Subarray

http://leetcode.com/onlinejudge#question_53

Find the contiguous subarray within an array (containing at least one number) 
which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution 
using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    // version 1, dynamic programming, O(n)
    int maxSubArray(int A[], int n) {
        int max = A[0], sum = 0; // remember current sum
        for(int i=0; i<n; i++){
            sum += A[i];
            max = (sum > max) ? sum : max;
            sum = (sum > 0) ? sum : 0;
        }
        return max;
    }
    
    // version 2, divide and conquer, O(n*log(n))
    int maxSubArray(int A[], int n) {
        if(n==1) return A[0];
        if(n<=0) return (-2147483647-1); // MIN_INT
        
        int mid = n/2, lmax = 0, rmax = 0;
        
        for(int i=mid-1, sum = 0; i>=0; i--){
            sum += A[i];
            lmax = (sum > lmax) ? sum : lmax;
        }
        
        for(int i=mid+1, sum = 0; i<n; i++){
            sum += A[i];
            rmax = (sum > rmax) ? sum : rmax;
        }
        
        int mmax = A[mid] + lmax + rmax;
        lmax = maxSubArray(A, mid); // 0 ~ mid-1
        rmax = maxSubArray(A + mid + 1, n - mid - 1); // mid+1 ~ n-1
        
        return max(mmax, max(lmax, rmax));
    }
};