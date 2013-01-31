/*
Plus One

http://leetcode.com/onlinejudge#question_66

Given a number represented as an array of digits, plus one to the number.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if(digits.size() == 0) return digits;
        
        int index = digits.size()-1;
        while(index != -1 && digits[index]==9) {
            digits[index] = 0;
            index--;
        }
        
        if(index != -1) {
            digits[index] += 1;
        } else {
            digits[0] = 1;
            digits.push_back(0);
        }
        
        return digits;
    }
};

//====================================================================

#include<stdio.h>


#define MAXITEM 100

bool plusone(int *arr, int *last)
{
  if(*last < 0 || *last >= MAXITEM) 
    return false;
  
  int index = *last;
 
  //add to the upper digit if it was 9
  while(index != -1 && arr[index] == 9)
  {
    arr[index] = 0;
    index --;
  }
  
  if(index != -1)
  {
    arr[index]++;
  }
  else if(*last != MAXITEM -1)
  {
    arr[0] = 1;
    arr[*last+1] = 0;
    (*last)++;
  }
  else // overflow
  {
    *last = 0;
    return false;
  }

  return true;
}

int main()
{
  int arr[MAXITEM];
  arr[0] = 9;
  arr[1] = 9;
  arr[2] = 9;

  int last=2;    

  for(int i=0; i<=last; i++)
    printf("%d", arr[i]);

  plusone(arr, &last);

  printf("\n");
  for(int i=0; i<=last; i++)
    printf("%d", arr[i]);

  getchar();
  return 0;
}