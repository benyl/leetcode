/*
http://leetcode.com/onlinejudge#question_120

Triangle:

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

// =============================================================
// directly add the path sum on the triangle
// large judge: 36 milli secs
// time complexity: O(n), space complexity: O(1)

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 0) return 0;
        
        for(int row=triangle.size()-2; row>=0; --row)
            for(int col=0; col<row+1; ++col)
                triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);
        
        return triangle[0][0];
    }
};
