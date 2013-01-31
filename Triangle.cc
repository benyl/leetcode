/*
http://leetcode.com/onlinejudge#question_120

Triangle:

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        
        // consider only alphanumeric characters and ignoring cases
        for(int i=0; i<s.length(); i++)
        {
            if((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z'))
                t += s[i];
            else if(s[i]>='A' && s[i]<='Z')
                t += s[i] + 32; // 'a' = 'A' + 32
        }
        
        // check palindrome
        for(int i=0; i<t.length()/2; i++)
        {
            if(t[i] != t[t.length() - 1 - i])
                return false;
        }
        
        return true;
    } // end of: bool isPalindrome(string s)
};

int main()
{
  string s = "A man, a plan, a canal: Panama";
  
  Solution sol;
  cout << "Input data : " << s << endl
       << "Is palindrome? " 
       << (sol.isPalindrome(s)? "True" : "False") << endl;

  getchar();
  return 0;
}