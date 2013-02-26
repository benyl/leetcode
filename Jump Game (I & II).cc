/*
Jump Game

http://leetcode.com/onlinejudge#question_55

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

=======================================================================

Jump Game II

http://leetcode.com/onlinejudge#question_45

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. 
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
public:
    // Jump Game
    bool canJump(int A[], int n) {
        if(n==1) return true;
        vector<bool> reach (n, false);  // remember if this place is reachable
        int last = 0;                   // record the last index that can reach now
        
        reach[0] = true;
        
        // using dynamic programming
        for(int i=0; i<n; i++) {
            if(!reach[i]) break;
            while(last<i+A[i]) {
                ++last;
                reach[last] = true;
                if(last==n-1) break;
            }
        }
        return reach[n-1];
    }
    
    // Jump Game II
    int jump(int A[], int n) {
        if(n==1) return 0;
        
        vector<int> step (n, 0);    // remember the step to each place
        int last = 0;               // record the last index that can reach now
        
        // using dynamic programming
        for(int i=0; i<n; i++) {
            while(last<i+A[i]) {
                ++last;
                step[last] = step[i] + 1;
                if(last==n-1) return step[last];
            }
        }
    }
};