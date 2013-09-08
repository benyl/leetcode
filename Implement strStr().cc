/*
Implement strStr()

http://leetcode.com/onlinejudge#question_28

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, 
or null if needle is not part of haystack.
*/

// ====================================================
// brack tracking solution
// time complexity: o(hlen * nlen), space complexity: o(1)

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!haystack || !needle) return NULL;
        if(*needle=='\0') return haystack; // return haystack if needle is empty
        
        for(;*haystack!='\0'; ++haystack) // iterative the start point of matching
            for(int idx=0; haystack[idx]==needle[idx]; ++idx) // start matching
                if(needle[idx+1]=='\0') return haystack;      // return if reach end of needle
                else if(haystack[idx+1]=='\0') return NULL;  // return if reach end of haystack
                
        return NULL;
    }
};

// ====================================================
// KMP solution
// time complexity: o(hlen + nlen), space complexity: o(nlen)
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!haystack || !needle) return NULL;
        int hlen=strlen(haystack), nlen=strlen(needle);
        if(nlen==0) return haystack;
        if(hlen==0) return NULL;

        int pattern[nlen]; 
        GeneratePattern(needle, nlen, pattern); 
        return Match(haystack, hlen, needle, nlen, pattern); 
    }
    
    // KMP: Generate pattern
    void GeneratePattern(char* needle, int nlen, int* pattern) {
        pattern[0] = -1;
        for(int k=-1, j=1; j<nlen; ++j) {
            while(k>-1 && needle[k+1] != needle[j])
                k = pattern[k];
            if(needle[k+1] == needle[j]) ++k;
            pattern[j] = k;
        }
    }
    
    // KMP: Match pattern
    char* Match(char* haystack, int hlen, char* needle, int nlen, int* pattern) {
        for(int k=-1, j=0; j<hlen; ++j) {
            while(k>-1 && needle[k+1] != haystack[j])
                k = pattern[k];
            if(needle[k+1] == haystack[j]) ++k;
            if(k == nlen-1) return haystack+j-k;
        }
        return NULL;
    }
};