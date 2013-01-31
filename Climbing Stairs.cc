/*
Climbing Stairs
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
        vector<int> steps;
        
        if(n<=0) return 0;
        
        for(int i=0; i<n; i++)
        {
            int step = 0;
            if(i == 0) step = 1;
            else if(i == 1) step = 2;
            else step = steps[i-1] + steps[i-2];
            
            steps.push_back(step);
        }
        
        return steps[n-1];
    }
};

void main()
{
    Solution sol;

    for(int i=0; i<10; i++)
        cout << "n = " << i <<" : step = "  << sol.climbStairs(i) << endl;
    getchar();
}