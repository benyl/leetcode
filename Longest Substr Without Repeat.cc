/*
Longest Substring Without Repeating Characters

http://leetcode.com/onlinejudge#question_3

Given a string, find the length of the longest substring without 
repeating characters. For example, the longest substring without 
repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) return s.size();
        int sub = lengthOfLongestSubstring(s.substr(0,s.size()-1));
        if(isRepeating(s.substr(s.size()-sub-1)))
            return sub+1;
        else 
            return sub;
    }
    
    bool isRepeating(string s) {
        vector<bool> occur(26, false);
        for(int i=0; i<s.size(); i++) {
            if(occur[s[i]-'a']) return false;
            occur[s[i]-'a'] = true;
        }
    }
};


// version 2, use sliding window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        
        vector<int> found(256, 0); // number of char found
        int repeat = 0; // number of repeat char
        int start=0, end=0, maxlen=0;
        
        while(end<s.size())
            if(repeat==0) {
                if(found[s[end]]==1) ++repeat;
                ++found[s[end]];
                ++end;
                if(repeat==0) maxlen = max(maxlen, end-start);
            } else {
                if(found[s[start]]==2) --repeat;
                --found[s[start]];
                ++start;
            }
        
        return maxlen;
    }
};