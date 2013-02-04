/*
Next Permutation

http://leetcode.com/onlinejudge#question_31

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
*/

#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int id = num.size()-1;
        while(id > 0) {
            if(num[id] > num[id-1]) break;
            id--;
        }
        
        sort(num.begin()+id, num.end());
        
        if(id!=0) {
            for(int i=num.size()-1;i>0;i--) {
                if(num[i-1]<=num[id-1]) {
                    int temp = num[i];
                    num[i] = num[id-1];
                    num[id-1] = temp;
                    break;
                }
            }
        }
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

int main()
{
  int inputArray[] = {1,2,3};
  vector<int> input(inputArray,end(inputArray));

  Solution sol;
  sol.nextPermutation(input);

  PrintVec<int>(input);
  getchar();
  return 0;
}