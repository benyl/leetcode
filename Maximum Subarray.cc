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

// =============================================
// version 1, dynamic programming
// 44 milli secs pass large judge
// time complexity: O(n), space complexity: O(1)

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = INT_MIN; // remember current sum
        for(int i=0, sum=0; i<n; i++){
            sum += A[i];
            maxSum = max(sum, maxSum);
            sum = max(sum, 0);
        }
        return maxSum;
    }
};

// =============================================
// version 2, divide and conquer
// 60 milli secs pass large judge
// time complexity: O(n*log(n)), space complexity: O(n)

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==1) return A[0];
        if(n<=0) return INT_MIN;
        
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