/*
Count and Say

http://leetcode.com/onlinejudge#question_38

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    // itoa function
    string ToStr (int Number) {
        ostringstream ss;
        ss << Number;
        return ss.str();
    }
    
    string countAndSay(int n) {
        string result("1");
        
        for(int i=1;i<n;i++){
            string text(result);
            result = "";
            int num = 1;
        
            for(int j=1;j<text.size();j++){
                if(text[j]==text[j-1]) {
                    num++;
                } else {
                    result += ToStr(num) + text[j-1];
                    num=1;
                }
            }
            
            result += ToStr(num) + text.back();
        }
        return result;
    }
};


void main()
{
    Solution sol;
    
    for(int x=1;x<10;x++)
        cout << sol.countAndSay(x) << endl;
    
    getchar();
}


// =================================================
// compact version using std::to_string(int x)

class Solution {
public:
    string countAndSay(int n) {
        string say = "1";
        while(--n>0){
            string next = "";
            int count = 1;
            for(int i=1; i<say.size(); ++i) {
                if(say[i]!=say[i-1]) {
                    next += to_string(count) + say[i-1];
                    count = 0;
                }
                ++count;
            }
            next += to_string(count) + say.back();
            say = next;
        }
        
        return say;
    }
};