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

class Solution {
public:
    // version 1, use O(m + n) space
    void setZeroes1(vector<vector<int> > &matrix) {
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

    // version 2, use constant space
    void setZeroes(vector<vector<int> > &matrix) {
        int zerorow = matrix.size();
        int zerocol = matrix[0].size();
        
        for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix[0].size(); j++)
            if(matrix[i][j]==0) {
                zerorow = i;
                zerocol = j;
                break;
                }
        
        if(zerorow == matrix.size()) return;
        
        
        for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix[0].size(); j++)
            if(i!=zerorow && j!=zerocol && matrix[i][j]==0) {
                matrix[zerorow][j] = 0;
                matrix[i][zerocol] = 0;
            }
        
        for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix[0].size(); j++)
            if(i!=zerorow && j!=zerocol) {
                if(matrix[zerorow][j]==0) matrix[i][j]=0;
                if(matrix[i][zerocol]==0) matrix[i][j]=0;
            }
            
        for(int i=0; i<matrix.size(); i++)
            matrix[i][zerocol]=0;
            
        for(int j=0; j<matrix[0].size(); j++)
            matrix[zerorow][j]=0;
    }
};