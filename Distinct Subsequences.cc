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

/*
c 1 3 3
b 1 3 0
b 1 2 0
b 1 1 0
a 1 0 0
a 1 0 0
# 1 0 0
  # b c
 
*/

// use dynamic programming
// 32 milli secs pass large judge
// time complexity: o(m*n), space complexity: o(n)
class Solution {
public:
    int numDistinct(string S, string T) {
        if(T.size()>S.size()) return 0;
        vector<int> dp(T.size()+1, 0);
        
        dp[0] = 1;
        for(size_t i=1; i<=S.size(); ++i)
            for(size_t j=min(i, T.size()); j>0; --j)
                if(S[i-1] == T[j-1])
                    dp[j] += dp[j-1];
        
        return dp.back();
    }
};