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
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        if(s == "") return 0;
        if(valid(s.substr(0,1)) == 0) return 0;

        int sum1=1, sum2=1;
        for(int i=1; i<s.size(); i++) {
            int sum = 0;
            if(valid(s.substr(i-1,2))) sum +=sum1;
            if(valid(s.substr(i,1))) sum +=sum2;
            if(sum == 0) return sum;
            sum1 = sum2;
            sum2 = sum;
        }
        
        return sum2;
    }
    
    bool valid(string s) {
        if(s=="" || s.size()>2) return false;
        if(s[0]=='0') return false;
        stringstream s_str(s);
        int x;
        s_str >> x;
        if(x>0 && x<27) return true;
        else return false;
    }
};

void main()
{
    Solution sol;
    
    string s1 = "227";
    cout << sol.numDecodings(s1) << endl;
    
    getchar();
}