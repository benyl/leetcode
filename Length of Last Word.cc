/*
Length of Last Word

http://leetcode.com/onlinejudge#question_58

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(!s) return 0;
        
        int last = 0; // length of last word
        
        for(int i=0; s[i]!=NULL; i++) {
            if(s[i] != ' ') {
                if(i!=0 && s[i-1]!=' ') {
                    last ++;
                } else {
                    last = 1;
                }
            }
        }
        return last;
    }
};