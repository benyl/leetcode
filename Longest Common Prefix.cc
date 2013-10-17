/*
Longest Common Prefix

http://leetcode.com/onlinejudge#question_14

Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()==0) return "";
        
        for(int len=0; len<strs[0].size(); ++len)
            for(int i=1; i<strs.size(); ++i)
                if(strs[i].size()==len || strs[i][len]!=strs[0][len])
                    return strs[0].substr(0, len);
        
        return strs[0];
    }
};