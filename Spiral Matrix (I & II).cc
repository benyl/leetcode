/*
Spiral Matrix

http://leetcode.com/onlinejudge#question_54

Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

=======================================================================

Spiral Matrix II

http://leetcode.com/onlinejudge#question_59

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    // Spiral Matrix
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if(matrix.size()==0) return vector<int>(0);
        if(matrix[0].size()==0) return vector<int>(0);
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        for(int r=0; r * 2 < min(m,n); r++) {
            for(int i=r; i<n-r; i++)            // A[r][r] ~ A[r][n-1-r]
                result.push_back(matrix[r][i]);
            for(int i=r+1; i<m-r; i++)          // A[r+1][n-1-r] ~ A[m-1-r][n-1-r]
                result.push_back(matrix[i][n-1-r]); 
            
            if(m-1-r==r || n-1-r==r) break;
            
            for(int i=n-2-r; i>=r; i--)         // A[m-1-r][n-2-r] ~ A[m-1-r][r]    
                result.push_back(matrix[m-1-r][i]); 
            for(int i=m-2-r; i>=r+1; i--)       // A[m-2-r][r] ~ A[r+1][r]
                result.push_back(matrix[i][r]); 
        }
        return result;
    }
    
    // Spiral Matrix II
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        if(n==0) return matrix;
        
        int id = 1;
        for(int r=0; r * 2 < n; r++) {
            for(int i=r; i<n-r; i++)            // A[r][r] ~ A[r][n-1-r]
                matrix[r][i] = id++;
            for(int i=r+1; i<n-r; i++)          // A[r+1][n-1-r] ~ A[n-1-r][n-1-r]
                matrix[i][n-1-r] = id++; 
            
            if(n-1-r==r) break;
            
            for(int i=n-2-r; i>=r; i--)         // A[n-1-r][n-2-r] ~ A[n-1-r][r]    
                matrix[n-1-r][i] = id++; 
            for(int i=n-2-r; i>=r+1; i--)       // A[n-2-r][r] ~ A[r+1][r]
                matrix[i][r] = id++;
        }
        
        return matrix;
    }
};