/*
Set Matrix Zeroes

http://leetcode.com/onlinejudge#question_73

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/


// ==============================================
// version 1, use O(m + n) space
// time complexity o(m*n), space complexity o(m+n)

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        vector<int> zerorow = vector<int>(matrix.size(), 1);
        vector<int> zerocol = vector<int>(matrix[0].size(), 1);
        
        for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix[0].size(); j++)
            if(matrix[i][j]==0) {
                zerorow[i] = 0;
                zerocol[j] = 0;
                }
        
        for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix[0].size(); j++)
            if(zerorow[i]==0 || zerocol[j]==0) {
                matrix[i][j]=0;
            }
    }
};


// ==============================================
// version 2, use constant space
// time complexity o(m*n), space complexity o(1)

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(!matrix.size() || !matrix[0].size()) return;
        
        int zerorow = -1, zerocol = -1;
        
        for(int i=0; i<matrix.size() && zerorow==-1; i++)
        for(int j=0; j<matrix[0].size() && zerorow==-1; j++)
            if(matrix[i][j]==0) {
                zerorow = i;
                zerocol = j;
            }
        
        if(zerorow == -1) return;
        
        for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix[0].size(); j++)
            if(matrix[i][j]==0) {
                matrix[zerorow][j] = 0;
                matrix[i][zerocol] = 0;
            }
        
        for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix[0].size(); j++)
            if(i!=zerorow && j!=zerocol && 
               (!matrix[i][zerocol] || !matrix[zerorow][j]))
                matrix[i][j]=0;
            
        for(int i=0; i<matrix.size(); i++) matrix[i][zerocol]=0;
        for(int j=0; j<matrix[0].size(); j++) matrix[zerorow][j]=0;
    }
};