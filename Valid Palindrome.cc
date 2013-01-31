/*
http://leetcode.com/onlinejudge#question_125

Valid Palindrome:

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
 */

#include <stdio.h>
#include <iostream>
#include <string>

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