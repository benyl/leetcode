/*
Word Break 

http://oj.leetcode.com/problems/word-break/

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

=======================================================================
Word Break II

http://oj.leetcode.com/problems/word-break-ii/

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

*/


// =======================================================================
// Word Break I
// Use dynamic programming

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.size()<1) return false;
        vector<bool> wordOrBreak(s.size()+1, false);
        wordOrBreak[0] = true;
        
        for(int i=1; i<=s.size(); ++i)
            for(int j=i-1; j>=0; --j)
                if(dict.count(s.substr(j, i-j)) && wordOrBreak[j]) {
                    wordOrBreak[i] = true;
                    break;
                }

        return wordOrBreak[s.size()];
    }
};


// =======================================================================
// Word Break II
// Use dynamic programming

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if(s.size()<1) return vector<string>();
        
        vector<vector<int> > wordOrBreak(s.size()+1);
        
        for(int i=1; i<=s.size(); ++i) {
            string s1 = s.substr(0, i);
            if(dict.count(s1))
                wordOrBreak[i].push_back(0);
            
            for(int j=1; j<i; ++j) {
                string s2 = s.substr(j, i-j);
                if(dict.count(s2)) wordOrBreak[i].push_back(j);
            }
        }
        
        return genSentences(s, wordOrBreak, s.size());
    }
    
    vector<string> genSentences(string &s, vector<vector<int> > &wordOrBreak, int pos) {
        vector<string> result;
        
        for(int i=0; i<wordOrBreak[pos].size(); ++i) {
            if(wordOrBreak[pos][i] == 0) {
                result.push_back(s.substr(0, pos));
            } else {
                string s1 = s.substr(wordOrBreak[pos][i], pos - wordOrBreak[pos][i]);
                vector<string> sub = genSentences(s, wordOrBreak, wordOrBreak[pos][i]);
                for(int j=0; j<sub.size(); ++j)
                    result.push_back(sub[j] + " " + s1);
            }
        }
        
        return result;
    }
};