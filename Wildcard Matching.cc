/*
Wildcard Matching

http://leetcode.com/onlinejudge#question_44

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") returns: false
isMatch("aa","aa") returns: true
isMatch("aaa","aa") returns: false
isMatch("aa", "*") returns: true
isMatch("aa", "a*") returns: true
isMatch("ab", "?*") returns: true
isMatch("aab", "c*a*b") returns: false

*/

class Solution {
public:
    // version 4, use the same idea of recursion, in iteration and with backtracking
    bool isMatch(const char *s, const char *p) {
        bool star = false;
        const char *as, *ap;                     // anchor of s, p when star appear
        while(*s != '\0')
        {
            if(*p == '*') {                      // found *, place anchor and move on
                star = true;
                while(*p == '*') ++p;            // templory ignore the '*'
                if (*p == '\0') return true;
                as = s, ap = p;                  // remember the position for backtracking
            } else {
                if(*p == *s || *p == '?') {      // '?' match any character
                    ++s; ++p;
                } else if(star) {                // if not match, go back to anchor
                    s = ++as;                    // move anchor of s one char after
                    p = ap;                      // redo matching
                } else
                    return false;                // no star for backtracking
            }
        }                                        // left when *s = '\0'
        
        while (*p == '*') ++p;                   // reach char after *
        return (*p == '\0');                     
    }

    // version 1, use dynamic programming, Memory Limit Exceeded    
    bool isMatch1(const char *s, const char *p) {
        int m = 0, n = 0; // size of s, p
        
        while(s[m]!='\0') m++;
        while(p[n]!='\0') n++;
        
        // use dynamic programming
        vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
        
        if(s[0] == p[0] || p[0] == '?' || p[0] == '*') dp[0][0] = true;
        
        for(int i=1; i<=m; i++)
            dp[i][0] = (p[0] == '*') ? true : false;
        
        
        int minlen = (p[0]!='*') ? 1:0; // the min length of string that match p
        for(int j=1; j<=n; j++) {
            minlen += (p[j]!='*') ? 1:0;
            if(minlen > 1) break; 
            if(s[0] == p[j] || p[j] == '?' || p[j] == '*')
               dp[0][j] = dp[0][j-1];
        }
        
        for(int i=1; i<=m; i++) {
            minlen = (p[0]!='*') ? 1:0;
            for(int j=1; j<=n; j++) {
                minlen += (p[j]!='*') ? 1:0;
                if(minlen > i+1) break; 
                if(s[i] == p[j] || p[j] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j] == '*')
                    dp[i][j] = dp[i-1][j] | dp[i][j-1] | dp[i-1][j-1];
            }
        }
            
        return dp[m][n];
    }

    // version 2, use recursion, Time Limit Exceeded
    bool isMatch2(const char *s, const char *p) {
        if(s==NULL) return (p==NULL);
        if(*p=='\0') return (*s=='\0');
        
        if(*p!='*')
            if((*p == *s || *p == '?') && *s!='\0') 
                return isMatch(s+1, p+1);
            else 
                return false;
                
        while(*(p+1) == '*') p++;
        
        while(*s!='\0') {
            if(isMatch(s, p+1)) return true;
            s++;
        }
        
        return isMatch(s, p+1);
    }
    
    // version 3, use dynamic programming with less space, Time Limit Exceeded
    bool isMatch3(const char *s, const char *p) {
        int m = 0, n = 0; // size of s, p
        while(s[m]!='\0') m++;
        while(p[n]!='\0') n++;
        
        // use dynamic programming
        vector<bool> dp1(n+1, false);
        vector<bool> dp2(n+1, false);
        
        for(int i=0; i<=m; i++) {
            vector<bool> &curr = (i%2) ? dp2 : dp1;
            vector<bool> &prev = (i%2) ? dp1 : dp2;
            
            curr[0] = (p[0] == '*') ? true : false;
            if((i==0) && (s[0] == p[0] || p[0] == '?')) 
                curr[0] = true;
            
            int minlen = (p[0]!='*') ? 1:0;
            for(int j=1; j<=n; j++) {
                minlen += (p[j]!='*') ? 1:0;
                
                if(minlen > i+1)
                    curr[j] = false;
                else if(s[i] == p[j] || p[j] == '?')
                    curr[j] = (i==0)? curr[j-1] : prev[j-1];
                else if(p[j] == '*') 
                    curr[j] = prev[j] | prev[j-1] | curr[j-1];
                else 
                    curr[j] = false;
            }
        }
            
        return (m%2)?dp2[n]:dp1[n];
    }
};