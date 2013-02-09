/*
Implement strStr()

http://leetcode.com/onlinejudge#question_28

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, 
or null if needle is not part of haystack.
*/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!haystack || !needle) return NULL;
        if(needle[0] == '\0') return haystack;
        if(haystack[0] == '\0') return NULL;
        
        int idx=0;
        while(haystack[idx] != '\0') {
            if(haystack[idx] == needle[0]) {
                int i = 0;
                while(haystack[idx+i] == needle[i]){
                    if(needle[i+1] == '\0') return haystack + idx;
                    if(haystack[idx+i+1] == '\0') return NULL;
                    i++;
                }
            }
            idx++;
        }
        
        return NULL;
    }
};
