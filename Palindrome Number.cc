/*
Palindrome Number

http://leetcode.com/onlinejudge#question_9

Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        return IsPalindrome(&x, x);
    }
    
    bool IsPalindrome(int* data, int min)
    {
        if(min == 0) return true;

        if(IsPalindrome(data, min/10) && ((*data)%10 == (min%10))) {
            (*data) /= 10;
            return true;
        }

        return false;
    }
};


//====================================================================

#include <stdio.h>
#include <iostream>

using namespace std;

typedef unsigned int uint;

uint GetMinDigit(uint data)
{
  return data % 10;
}

uint GetMaxDigit(uint data)
{
  while(data>=10)
  {
    data /= 10; 
  }
  return data;
}

uint RemoveMinDigit(uint data)
{
  return data /= 10;
}

uint RemoveMaxDigit(uint data)
{
  int size = 1, remain = data;
  while(data>=10)
  {
    data /= 10;
    size *= 10;
  }
  return remain - data * size;
}

bool IsPalindrome(uint data)
{
  if(data < 10) return true;

  if(GetMinDigit(data) ==
          GetMaxDigit(data))
  {
    data = RemoveMaxDigit(data);
    data = RemoveMinDigit(data);
    return IsPalindrome(data);
  }

  // max and min digit does not match
  return false;
}

int main()
{
  int data = 123454321;
  cout << "Input data          : " << data << endl
       << "Get Max Digit       : " << GetMaxDigit(data) << endl
       << "Get Min Digit       : " << GetMinDigit(data) << endl
       << "Remove Max Digit    : " << RemoveMaxDigit(data) << endl
       << "Remove Min Digit    : " << RemoveMinDigit(data) << endl
       << "Is palindrome number? " 
       << (IsPalindrome(data)? "True" : "False") << endl;

  getchar();
  return 0;
}

//====================================================================

#include <stdio.h>
#include <iostream>

using namespace std;

typedef unsigned int uint;

bool IsPalindrome(uint* data, uint min)
{
  if(min == 0) return true;

  if(IsPalindrome(data, min/10) && ((*data)%10 == (min%10)))
  {
    (*data) /= 10;
    return true;
  }

  return false;
}

int main()
{
  int data = 123454321;
  cout << "Input data          : " << data << endl
       << "Is palindrome number? " 
       << (IsPalindrome(&data, data)? "True" : "False") << endl;

  getchar();
  return 0;
}