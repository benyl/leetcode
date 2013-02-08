/*
Generate Parentheses

http://leetcode.com/onlinejudge#question_22

Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    vector<string> generateParenthesis(int n, int left=0, int right=0) {
        if(left>n || right>=n || left<right) return vector<string>(0, "()");
        if(n-left==0 && n-right==1) return vector<string>(1, ")");
        
        if(left==right) {
            vector<string> result = generateParenthesis(n, left+1, right);
            for(int i=0; i<result.size(); i++)
                result[i] = "(" + result[i];
            return result;
        } else {
            vector<string> result;
            
            vector<string> re1 = generateParenthesis(n, left+1, right);
            for(int i=0; i<re1.size(); i++) 
                result.push_back("(" + re1[i]);
                
            vector<string> re2 = generateParenthesis(n, left, right+1);
            for(int i=0; i<re2.size(); i++) 
                result.push_back(")" + re2[i]);
                
            return result;
        }
    }
};