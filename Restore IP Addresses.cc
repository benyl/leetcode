/*
http://leetcode.com/onlinejudge#question_93

Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return restore(s, 4);
    }

    vector<string> restore(string s, int n){
        vector<string> result;
        if(n==1){
            if(s.size()>1 && s[0]=='0') return result;
            stringstream s_str(s);
            int x;
            s_str >> x;
            if(x>=0 && x<256) result.push_back(s);
            return result;
        }

        int start, end;
        if(s.size() == n){start = 1; end = 2;}
        else if(s.size() == n+1){start = 1; end = 3;}
        else if(s.size() == n*3-1){start = 2; end = 4;}
        else if(s.size() == n*3){start = 3; end = 4;}
        else if(s.size()>n+1 && s.size()<n*3-1){start = 1; end = 4;}
        else return result;
        
        for(int i=start; i<end; i++){
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            vector<string> r1 = restore(s1, 1);
            if(r1.size() == 0) continue;
            vector<string> r2 = restore(s2, n-1);
            for(int i=0; i< r2.size(); i++)
                result.push_back(s1+"."+r2[i]);
        }
        return result;
    }
};

template <class T>
void PrintVec(vector<T> vec)
{
  for(int i=0; i<vec.size(); i++)  
  {
    cout << vec[i];
    if(i!=vec.size()-1)
      cout << ", ";
  }
  cout << endl;
}

void main()
{
    Solution sol;
    
    string s1 = "25525511135";
    PrintVec<string>(sol.restore(s1, 4));
    
    getchar();
}