/*
http://leetcode.com/onlinejudge#question_97

Interleaving String

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

We think in generalities, but we live in details.
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1 == "") return s2 == s3;
        if(s2 == "") return s1 == s3;
        if(s3.size() != s1.size() + s2.size()) return false;
        
        // use dynamic programming
        vector< vector<bool> > dp(s1.size() + 1, 
                                  vector<bool>(s2.size() + 1, false));
        
        dp[0][0] = true;
		for(int i=1; i<s1.size()+1; i++) {
            if(s1[i-1] == s3[i-1]) dp[i][0] = true;
            else break;
        }
		for(int i=1; i<s2.size()+1; i++) {
            if(s2[i-1] == s3[i-1]) dp[0][i] = true;
            else break;
        }
        
        if(!dp[0][1] && !dp[1][0]) return false;
        
        for(int i=1; i<s1.size()+1; i++)
        for(int j=1; j<s2.size()+1; j++)
            dp[i][j] = (s1[i-1] == s3[i+j-1] && dp[i-1][j]) ||
                       (s2[j-1] == s3[i+j-1] && dp[i][j-1]);
        
        return dp[s1.size()][s2.size()];
    }
    
    // a recursive solution, Time Limit Exceeded
	bool isInterleave2(string s1, string s2, string s3) {
        if(s1 == "") return s2 == s3;
        if(s2 == "") return s1 == s3;
        
        if(s1[0] == s3[0] && s2[0] == s3[0])
            return (isInterleave(s1.substr(1), s2, s3.substr(1)) ||
                    isInterleave(s1, s2.substr(1), s3.substr(1)));
        if(s1[0] == s3[0])
            return isInterleave(s1.substr(1), s2, s3.substr(1));
        if(s2[0] == s3[0])
            return isInterleave(s1, s2.substr(1), s3.substr(1));
        
        return false;
    }
};

void main()
{
    Solution sol;
    
	string s1 = "aabd";
	string s2 = "abdc";
	string s3 = "aabdabcd";
	cout << sol.isInterleave(s1,s2,s3) << endl;
    
    getchar();
}


// ================================================================

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        if(s1.size() == 0) return s2 == s3;
        if(s2.size() == 0) return s1 == s3;
        
        vector< vector<bool> > dp(s1.size()+1, vector<bool>(s2.size()+1, true));
        
        for(int i=1; i<=s1.size(); ++i)
                dp[i][0] = (s1[i-1] == s3[i-1]);
        for(int j=1; j<=s2.size(); ++j)
                dp[0][j] = (s2[j-1] == s3[j-1]);
                
        for(int i=1; i<=s1.size(); ++i)
        for(int j=1; j<=s2.size(); ++j)
            dp[i][j] = ((s1[i-1] == s3[i+j-1]) && dp[i-1][j]) || 
                       ((s2[j-1] == s3[i+j-1]) && dp[i][j-1]);
                       
        return dp[s1.size()][s2.size()];
    }
};


