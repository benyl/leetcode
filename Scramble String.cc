/*
Scramble String

http://leetcode.com/onlinejudge#question_87

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

// =================================================================
// recursive solution
// 36 ms pass large judge
// time complexity o(n!), space complexity o(n)

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(!isAnagram(s1, s2)) return false;
        if(s1 == s2 || s1.size()<=3) return true;
        
        for(int i=1; i<s1.size(); ++i)
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i)))
                return true;
                
        for(int i=1; i<s1.size(); ++i)
            if(isScramble(s1.substr(0, i), s2.substr(s1.size()-i)) &&
                isScramble(s1.substr(i), s2.substr(0, s1.size()-i)))
                return true;
                
        return false;
    }
    
    int found[256];
    bool isAnagram(const string &s1, const string &s2) {
        if(s1.size() != s2.size()) return false;
        memset(found, 0, sizeof(found));
        for(int i=0; i<s1.size(); ++i) ++found[s1[i]];
        for(int i=0; i<s2.size(); ++i) --found[s2[i]];
        for(int i=0; i<256; ++i) 
            if(found[i]!=0) return false;
        return true;
    }
};

// =================================================================
// dynamic programming solution
// 36 ms pass large judge
// time complexity o(n^4), space complexity o(n^3)

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s1.size()) return false;
        if(s1 == s2) return true;
        int n = s1.size();
        bool dp[n][n][n+1];
        memset(dp, false, sizeof(dp));
        
        for(int len=1; len<=n; ++len)
        for(int i=0; i+len<=n; ++i)
        for(int j=0; j+len<=n; ++j)
            if(s1.substr(i, len) == s2.substr(j, len)) {
                dp[i][j][len] = true;
            } else {
                for(int l=1; l<len; ++l) {
                    if(dp[i][j][l] && dp[i+l][j+l][len-l]) {
                        dp[i][j][len] = true; break;
                    }
                    if(dp[i][j+len-l][l] && dp[i+l][j][len-l]) {
                        dp[i][j][len] = true; break;
                    }
                }
            }
        
        return dp[0][0][n];
    }
};
