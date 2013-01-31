/*
Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;
	
	// check valid inputs
	if(k>n || k<1 || n<1) return result;
	if(k==n) {
	  vector<int> temp;
	  for(int i=0; i<n; i++)
	    temp.push_back(i+1);
      result.push_back(temp);
	  return result;
	}
	
	result = combine(n-1, k); // combinations that contains no "n"
	
	// then we construct combinations that contains "n"
	vector<vector<int> > temp = combine(n-1, k-1);
	for(int i=0; i<temp.size(); i++)
	{
	  temp[i].push_back(n);
	  result.push_back(temp[i]);
	}
	
	if(k==1) {
	  vector<int> temp;
	  temp.push_back(n);
      result.push_back(temp);
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

int main()
{
  Solution s;
  vector<vector<int> > result = s.combine(4, 2);

  cout << endl << "result: [" << endl;
  for(int i=0; i<result.size(); i++)
  {
    cout << " ";
    PrintVec<int>(result[i]);
  }
  cout << "]" << endl;
  
  getchar();
  return 0;
}