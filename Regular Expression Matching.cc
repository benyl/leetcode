/*
Regular Expression Matching

http://leetcode.com/onlinejudge#question_10

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(s==NULL) return (p==NULL);
        if(*p=='\0') return (*s=='\0');
        
        if(*(p+1)!='*')
            if(*p == *s || (*p == '.' && *s!='\0')) 
                return isMatch(s+1, p+1);
            else 
                return false;
            
        while(*p == *s || (*p == '.' && *s!='\0')) {
            if(isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    }
};