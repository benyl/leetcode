/*
Minimum Path Sum

http://leetcode.com/onlinejudge#question_64

Given a m x n grid filled with non-negative numbers, find a path from 
top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

// ========================================================
// 68 milli secs
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=1; i<m; i++)
            grid[i][0] += grid[i-1][0];
            
        for(int i=1; i<n; i++)
            grid[0][i] += grid[0][i-1];
        
        for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            grid[i][j] += (grid[i-1][j]<grid[i][j-1])?
                          grid[i-1][j]:grid[i][j-1];
        
        return grid[m-1][n-1];
    }
};

// ========================================================
// 68 milli secs
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> sum(n, 0);
        
        for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j) {
            int s = grid[i][j];
            
            if(j==0) s+=sum[j]; // sum of upper block
            else if(i==0) s+=sum[j-1]; // sum of left block
            else s+= min(sum[j], sum[j-1]); // else add min of two
            
            sum[j] = s;
        }
        
        return sum[n-1];
    }
};