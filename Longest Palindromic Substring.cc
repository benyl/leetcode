/*
Longest Palindromic Substring

http://leetcode.com/onlinejudge#question_5

Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.

*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        string sub = longestPalindrome(s.substr(0, s.size()-1));
        
        if(s.size()-sub.size()>=2 && 
            isPalindrome(s.substr(s.size()-sub.size()-2)))
            return s.substr(s.size()-sub.size()-2);
            
        if(isPalindrome(s.substr(s.size()-sub.size()-1)))
            return s.substr(s.size()-sub.size()-1);
        
        return sub;
    }
    bool isPalindrome(string s) {
        for(int i=0; i<s.size()/2; i++)
            if(s[i] != s[s.size()-i-1]) return false;
        
        return true;
    }
};