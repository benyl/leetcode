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

class Solution {
public:
    int longestValidParentheses(string s) {
        // stack of parentheses and remember length of valid right part
        stack<pair<char, int> > sp; 
        sp.push(make_pair(')', 0));
        
        for(int i=0; i<s.size(); i++) {
            if(s[i]==')' && sp.top().first == '(') {
                int current = sp.top().second + 2;
                sp.pop();
                sp.top().second += current;
            } else {
                sp.push(make_pair(s[i], 0));
            }
        }
        
        int max=0;
        while(!sp.empty()) {
            max = (max>sp.top().second) ? max : sp.top().second;
            sp.pop(); 
        }
        
        return max;
    }
};