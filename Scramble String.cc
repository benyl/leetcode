/*
Scramble String

http://leetcode.com/onlinejudge#question_87

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        
        int hash = 0, len = 1, rm = 0;
        for(int i=0; i<s1.size(); i++) {
            hash += s1[i] * s1[i] - s2[i] * s2[i];
            if(hash == 0 && len!=s1.size()) {
                string sub1 = s1.substr(i-len+1, len);
                string sub2 = s2.substr(i-len+1, len);
                if(isScramble(sub1, sub2)) {
                    rm += len;
                }
                len = 1;
            } else {
                len ++;
            }
        }
        
        if(hash!=0) return false;
        if(rm == s1.size()) return true;
        
        hash = 0; len = 1; rm = 0;
        for(int i=0; i<s1.size(); i++) {
            hash += s1[i] * s1[i] - s2[s2.size()-1-i] * s2[s2.size()-1-i];
            if(hash == 0 && len!=s1.size()) {
                string sub1 = s1.substr(i-len+1, len);
                string sub2 = s2.substr(s2.size()-1-i, len);
                if(isScramble(sub1, sub2)) {
                    rm += len;
                }
                len = 1;
            } else {
                len ++;
            }
        }
        
        if(hash!=0) return false;
        if(rm == s1.size()) return true;
        
        return false;
    }
};

// =================================================================
// simple version
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;
        if(!isAnagram(s1,s2)) return false;
        
        for(int i=1; i<s1.size(); ++i)
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i)))
                return true;
                
        for(int i=1; i<s1.size(); ++i)
            if(isScramble(s1.substr(0, i), s2.substr(s1.size()-i)) &&
                isScramble(s1.substr(i), s2.substr(0, s1.size()-i)))
                return true;
    }
    
    bool isAnagram(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        vector<int> found(256);
        for(int i=0; i<s1.size(); ++i) ++found[s1[i]];
        for(int i=0; i<s2.size(); ++i) --found[s2[i]];
        for(int i=0; i<256; ++i) 
            if(found[i]!=0) return false;
        return true;
    }
};