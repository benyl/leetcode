/*
Search a 2D Matrix

http://leetcode.com/onlinejudge#question_74

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int min = 0, max = matrix.size() * matrix[0].size() - 1;
        
        while(min <= max) {
            int mid = (min + max) / 2;
            int x = mid / matrix[0].size();
            int y = mid % matrix[0].size();
            
            if(matrix[x][y] > target) {
                max = mid-1;
            } else if(matrix[x][y] < target) {
                min = mid+1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};