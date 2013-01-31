/*
http://leetcode.com/onlinejudge#question_115

Distinct Subsequences

Given a string S and a string T, count the number of distinct 
subsequences of T in S.

A subsequence of a string is a new string which is formed from the 
original string by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. 
(ie, ACE is a subsequence of ABCDE while AEC is not).

Here is an example
S = rabbbit, T = rabbit

Return 3.
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        if(S.size() == 0) return 0;
        if(T.size() == 0) return 1;
        if(S.size() < T.size()) return 0;
        
        // use dynamic programming
        vector< vector<int> > dp;
        for(int i=0; i<S.size()+1; i++)
        {
            vector<int> temp(T.size()+1);
            dp.push_back(temp);
        }
        
        for(int j=0; j<T.size()+1; j++)
            dp[0][j] = 0;

        for(int i=0; i<S.size()+1; i++)
            dp[i][0] = 1;
        
        for(int i=1; i<S.size()+1; i++)
            for(int j=1; j<=i && j<T.size()+1; j++)
            {
                if(S[i-1] == T[j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
            }

        return dp[S.size()][T.size()];
    }
};

void main()
{
    Solution sol;
    
    string S = "aabbbc";
    string T = "bc";
    
    cout << S << endl;
    cout << T << endl;
    
    cout << sol.numDistinct(S,T) << endl;
    getchar();
}