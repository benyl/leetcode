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

// ============================================================
// version 1
// using dynamic programming
// time complexity o(n), space complexity o(n)
class Solution {
public:
    // ============================================================
    // Jump Game
    bool canJump(int A[], int n) {
        vector<bool> reach (n, false); // remember if this place is reachable
        int maxJump = 1; // record the last index that can reach now
        reach[0] = true; // initialize: #0 can be reach
        
        for(int i=0; i<n && reach[i] && maxJump<n; ++i) // stop if #i can't be reach or reach #n
            while(maxJump<=A[i]+i && maxJump<n)
                reach[maxJump++] = true;  // mark reach and increase the last index that can be reached
                
        return reach[n-1];
    }
    
    // ============================================================
    // Jump Game II
    int jump(int A[], int n) {
        vector<int> minStep (n, -1);    // remember the step to each place
        int maxJump = 1; // record the last index that can reach now
        minStep[0] = 0; // initialize: #0 can be reach in 0 step
        
        for(int i=0; i<n && i<=maxJump && maxJump<n; ++i) // stop if #i can't reach or reach #n
            while(maxJump<=A[i]+i && maxJump<n)
                minStep[maxJump++] = minStep[i] + 1; // save steps and increase the last index that can be reached

        return minStep[n-1];
    }
};


// ==============================================
// Jump Game
// version 2
// time complexity o(n), space complexity o(1)

class Solution {
public:
    bool canJump(int A[], int n) {
        int maxJump = 0; // record the last index that can reach now
        for(int i=0; i<n && i<=maxJump && maxJump<n; ++i)  // stop if #i can't be reach or reach #n
                maxJump = max(A[i] + i, maxJump); // increase the last index that can be reached
        return (maxJump >= n-1);
    }
};

// ==============================================
// Jump Game II
// version 2
// time complexity o(n), space complexity o(1)

class Solution {
public:
    int jump(int A[], int n) {
        int thisStep=0, nextStep=0, step=0;  
        for(int i=0; i<n && nextStep<n; ++i) { // stop if reach #n
            if(i>thisStep) { // if exceed the last index of this step, go to nextstep
                ++step;
                thisStep = nextStep; // record the last index that can reach in this step
            }
            nextStep = max(A[i] + i, nextStep); // record the last index that can reach in next step
        }
        return (thisStep<n-1) ? step+1 : step; // corner case: if already reach #n in this step
    }
};