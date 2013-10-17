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


//=====================================================================
// Unique Paths
// result equal to combination number of C(m+n-1, m-1) or C(m+n-1, n-1)

// version 1, use o(m+n) time, o(m+n) spaces
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> comb(m+n-1, 1);
        for(int i=2; i<m+n-1; ++i)
            for(int j=i-1; j>0; --j)
                comb[j] += comb[j-1];
                
        return comb[m-1];
    }
};

// version 2
// directly calculate the combinateion of C(m+n-1, n-1), be awared of overflowed
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long sum = 1;
        
        for(int i=1; i<=n-1; i++) {
            sum *= m-1+i;
            sum /= i;
        }
        
        return sum;
    }
}

//=====================================================================
// Unique Paths II
// version 1, use o(m*n) time, o(n) spaces
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> paths(n, 0);
        paths[0] = 1;
        
        for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            if(obstacleGrid[i][j])
                paths[j] = 0;
            else if(j!=0)
                paths[j] += paths[j-1];
        
        return paths[n-1];
    }
};

// version 2, use o(m*n) time, o(1) spaces
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        
        for(int i=0; i<obstacleGrid.size(); ++i)
        for(int j=0; j<obstacleGrid[0].size(); ++j)
            if(obstacleGrid[i][j]) obstacleGrid[i][j] = 0;
            else if(j==0 && i==0) obstacleGrid[i][j] = 1;
            else {
                if(i!=0) obstacleGrid[i][j] += obstacleGrid[i-1][j];
                if(j!=0) obstacleGrid[i][j] += obstacleGrid[i][j-1];
            }
        return obstacleGrid.back().back();
    }
};