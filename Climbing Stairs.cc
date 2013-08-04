/*
Climbing Stairs

http://leetcode.com/onlinejudge#question_70

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n+1, 0);
        steps[1] = 1; steps[2] = 2;

        for(int i=3; i<=n; ++i)
            steps[i] = steps[i-1] + steps[i-2];

        return steps[n];
    }
};

void main()
{
    Solution sol;

    for(int i=0; i<10; i++)
        cout << "n = " << i <<" : step = "  << sol.climbStairs(i) << endl;
    getchar();
}