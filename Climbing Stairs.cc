/*
Climbing Stairs

http://leetcode.com/onlinejudge#question_70

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        int step[2];
        step[0]=1; step[1]=1;

        for(int i=2; i<=n; ++i)
            step[i&1] = step[0] + step[1]; // finbonacci number
            
        return step[n&1]; // n&1 == n%2
    }
};