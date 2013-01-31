/*
http://leetcode.com/onlinejudge#question_72

Edit Distance

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // use dynamic programming
        vector< vector<int> > dp;
        for(int i=0; i<word1.size()+1; i++)
        {
            vector<int> temp(word2.size()+1);
            dp.push_back(temp);
        }
        
        for(int i=0; i<word1.size()+1; i++)
            dp[i][0] = i;
            
        for(int j=0; j<word2.size()+1; j++)
            dp[0][j] = j;
        
        for(int i=1; i<word1.size()+1; i++)
        for(int j=1; j<word2.size()+1; j++)
        {
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
            {
                int min = dp[i-1][j-1];
                if(min > dp[i][j-1]) min = dp[i][j-1];
                if(min > dp[i-1][j]) min = dp[i-1][j];
                dp[i][j] = min + 1;
            }
        }
        
        return dp[S.size()][T.size()];
    }
};

void main()
{
    Solution sol;
    string word1 = "hello";
    string word2 = "lo";
    
    cout << word1 << endl;
    cout << word2 << endl;
    
    cout << sol.minDistance(word1, word2) << endl;
    
    getchar();
}
