/*
Unique Paths

http://leetcode.com/onlinejudge#question_62

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

//=====================================================================
Unique Paths II

http://leetcode.com/onlinejudge#question_63

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++)
            dp[i][0] = 1;
            
        for(int i=0; i<n; i++)
            dp[0][i] = 1;
        
        for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }

    // it's the combinateion of C(m+n-2, n-1), overflowed
    int uniquePathsVer2(int m, int n) {
        int sum = 1;
        
        for(int i=1; i<=n-1; i++) {
            sum *= m-1+i;
            sum /= i;
        }
        
        return sum;
    }
    

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        
        if(obstacleGrid[0][0] != 1)
            dp[0][0] = 1;
        else
            return 0;
        
        for(int i=1; i<m; i++)
            if(obstacleGrid[i][0] != 1)
                dp[i][0] = dp[i-1][0];
            
        for(int i=1; i<n; i++)
            if(obstacleGrid[0][i] != 1)
                dp[0][i] = dp[0][i-1];
        
        for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            if(obstacleGrid[i][j] != 1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }
};

void main()
{
  Solution sol;
  cout << sol.uniquePaths(2,2) << endl;
  getchar();
}