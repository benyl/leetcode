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

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    // Pascal's Triangle:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        for(int i=0; i<numRows; i++)
        {
            vector<int> level(i+1);
            level[0] = 1;
            level[level.size()-1] = 1;
            
            for(int j=1; j<level.size()-1; j++)
            {
                level[j] = result[i-1][j-1] + result[i-1][j];
            }
            
            result.push_back(level);
        }
        return result;
    }
    
    // Pascal's Triangle II:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1);
        result[0] = 1;
        for(int i=1; i<rowIndex+1; i++)
        {
            int old = result[0];
            for(int j=1; j<i; j++)
            {
                if(j > i/2)
                    result[j] = result[i - j];
                else
                {
                    int temp = result[j];
                    result[j] += old;
                    old = temp;
                }
            }
            result[i] = 1;
        }
        
        return result;
    }

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
};

void main()
{
	Solution sol;
	for(int n=0; n<10; n++)
	{
		vector<int> re = sol.getRow(n);
		for(int k=0; k<re.size(); k++)
		{
			cout << re[k] << " ";
		}
		cout << endl;
	}

	for(int n=0; n<10; n++)
	{
		for(int k=0; k<=n; k++)
		{
			cout << sol.combination(n,k) << " ";
		}
		cout << endl;
	}
	getchar();
}