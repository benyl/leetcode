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


// version 1
// use iteration with backtracking
// cut the duplcate cases when multiple '*' appear, only remember the last '*'
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(!s || !p) return false;
        const char *as = NULL, *ap = NULL;      // anchor of s, p when star appear
        
        while(*s != '\0')                       // leave when *s = '\0'
            if(*p == '*') {                      // found *, place anchor and move on
                while(*p == '*') ++p;            // templory ignore the '*'
                if (*p == '\0') return true;    // leave if p has only '*' at the end
                as = s, ap = p;                  // remember the position for backtracking
            } else if(*p == *s || *p == '?') { // '?' match any character
                ++s; ++p;
            } else if(as!=NULL) {              // if not match, go back to anchor redo matching
                s = ++as; p = ap;               // move anchor of s one char after
            } else
                return false;                   // no '*' for backtracking
        
        while (*p == '*') ++p;                 // reach char after '*'
        return (*p == '\0');
    }
};


// compact version
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *as = NULL, *ap = NULL;
        while(true)
            if(*p=='*') {                        // found *, remember the position for backtracking
                as = s; ap = ++p;                // only remember the last '*'
            } else if(*s=='\0') {               // leave when reach end of s
                return (*p=='\0');
            } else if(*p==*s || *p=='?') {      // if p match s, move on
                ++p; ++s;
            } else if(as!=NULL) {              // if not match, go back to anchor redo matching
                s = ++as; p = ap;               // move anchor of s one step forward
            } else {
                return false;                   // no '*' for backtracking
            }
    }
};
