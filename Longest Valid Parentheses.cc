/*
Longest Valid Parentheses

http://leetcode.com/onlinejudge#question_32

Given a string containing just the characters '(' and ')', find the 
length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which 
has length = 2.

Another example is ")()())", where the longest valid parentheses 
substring is "()()", which has length = 4.
*/


// using stack
// time complexity o(n), space complexity o(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int len=0, maxLen=0;
        
        for(int i=0; i<s.size(); ++i) {
            if(s[i]=='(') {
                stk.push(i-len); // push the farest left valid Parentheses
                len = 0; // reset current valid Parentheses length
            } else {
                if(!stk.empty() && s[stk.top()]=='(') {
                    len = i-stk.top()+1;
                    maxLen = max(maxLen, len);
                    stk.pop();
                } else {
                    stk.push(i);
                    len = 0; // reset current valid Parentheses length
                }
            }
        }
        
        return maxLen;
    }
};


// using dynamic programming
// time complexity o(n), space complexity o(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int maxLen=0;
        
        for(int i=s.size()-2; i>=0; --i) {
            if(s[i]=='(') {
                int j=i+1+dp[i+1]; // find the char after valid Parentheses
                if(j<s.size()&&s[j]==')') {
                    dp[i]=dp[i+1]+2;
                    if(j<s.size()-1)
                        dp[i]+=dp[j+1]; // extand the valid Parentheses
                }
            }
            maxLen= max(maxLen, dp[i]);
        }
        return maxLen;
    }
};