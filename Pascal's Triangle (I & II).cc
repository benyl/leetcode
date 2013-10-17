/*
-------------------------------------------------------
http://leetcode.com/onlinejudge#question_118

Pascal's Triangle:

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

-------------------------------------------------------
http://leetcode.com/onlinejudge#question_118

Pascal's Triangle II:

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

// ============================================
// Pascal's Triangle
// time complexity o(k^2), space complexity o(k^2)
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        
        for(int i=0; i<numRows; ++i) {
            result.push_back(vector<int>(i+1, 1));
            for(int j=1; j<i; ++j)
                result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
        
        return result;
    }
};

// ============================================
// Pascal's Triangle II
// time complexity o(k^2), space complexity o(k)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 1);
        
        for(int i=2; i<=rowIndex; ++i)
            for(int j=i-1; j>=1; --j)
                result[j] += result[j-1];
        
        return result;
    }
};

// ============================================
// reference: code to generate combination number (n, k)

unsigned long combination(unsigned long n, unsigned long k)
{
    if(k>n) return 0;
    if(k==0 || k==n) return 1;
    if(k>n/2) k=n-k;

    unsigned long result = 1;
    for(unsigned long i=1; i<=k; i++)
        result = result * (n-k+i)/i;
    
    return result;
}