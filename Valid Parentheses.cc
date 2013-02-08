/*
Valid Parentheses

http://leetcode.com/onlinejudge#question_20

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid 
but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> match;
        
        for(int i=0; i<s.size(); i++) {
            switch(s[i]) {
            case ')':
                if(!match.empty() && match.top()=='(') match.pop();
                else return false;
                break;
            case ']':
                if(!match.empty() && match.top()=='[') match.pop();
                else return false;
                break;
            case '}':
                if(!match.empty() && match.top()=='{') match.pop();
                else return false;
                break;
            default:
                match.push(s[i]);
            } // end of: switch(s[i])
        } // end of: for(int i=0; i<s.size(); i++)
        
        return match.empty();
    } // end of: isValid(string s)
};