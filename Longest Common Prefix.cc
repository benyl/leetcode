/*
Longest Common Prefix

http://leetcode.com/onlinejudge#question_14

Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix = "";
        if(strs.size()==0) return prefix;
        if(strs.size()==1) return strs[0];
        
        int index=0;
        bool flag = true;
        while(flag){
            for(int i=0; i<strs.size(); i++) {
                if(index==strs[i].size()){
                    flag=false;
                    break;
                } else if(strs[i][index]!=strs[0][index]){
                    flag=false;
                    break;
                }
            }
            if(flag) index++;
        }
        return strs[0].substr(0,index);
    }
};


void main()
{
  Solution sol;
  
  vector<string> strs;
  string s = "ab";
  strs.push_back(s);
  s = "abc";
  strs.push_back(s);
  
  cout << sol.longestCommonPrefix(strs) << endl;
  getchar();
}


// ============================================================
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        size_t len = strs[0].size();
        
        for(int i=1; i<strs.size(); ++i) {
            len = min(len, strs[i].size());
            int l = 0;
            while(strs[0][l]==strs[i][l] && l<len)
                ++l;
            len = l;
            if(len==0) break;
        }
        
        return strs[0].substr(0, len);
    }
};