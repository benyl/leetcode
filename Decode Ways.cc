/*
http://leetcode.com/onlinejudge#question_91

Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

*/

// recursive version, Time Limit Exceeded
class Solution {
public:
    int numDecodings(string s) {
        if(s.size()<1) return 0;
        if(s[0]<='0' || s[0]>'9') return 0;
        if(s.size()==1) return 1;
        
        int num = numDecodings(s.substr(1));
        if(s[0]=='1' || (s[0]=='2' && s[1]<='6'))
            num += (s.size()==2) ? 1: numDecodings(s.substr(2));
        
        return num;
    }
};


// use dynamic programming
class Solution {
public:
    int numDecodings(string s) {
        if(s.size()<1 || s[0]=='0') return 0;
        
        int sum1=1, sum2=1;
        for(int i=1; i<s.size(); ++i) {
            int sum = 0;
            if(s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')) sum += sum1;
            if(s[i]!='0') sum += sum2;
            if(sum == 0) return 0;
            sum1 = sum2;
            sum2 = sum;
        }
        
        return sum2;
    }
};