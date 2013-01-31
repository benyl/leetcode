/*
=============================================
Combination Sum I

Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

=============================================
Combination Sum II
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int> > combinationSum1(vector<int> &candidates, int target)   {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > result;
  
    // if target == 0 return empty
    if(target <= 0) return result;
    if(candidates.size() == 0) return result;

    // check if the candidate is in order
    // if not, sort the candidate
    for(int i=1; i < candidates.size(); i++)
      if(candidates[i] < candidates[i-1]) {
        sort(candidates.begin(), candidates.end());
        break;
      }
  
    // if candidate[0] > target, return empty
    if(candidates[0] > target) return result;
  
    // we should remove duplicate candidates here
    vector<int> newcandidates;
    newcandidates.push_back(candidates[0]);

    for(int i=1; i<candidates.size(); i++) {
      if(candidates[i] != candidates[i-1])
        newcandidates.push_back(candidates[i]);
    }

    // for i: candidate[n] * 0 ~ target/n
    int x = *(newcandidates.end() - 1); // x is the max item
    newcandidates.erase(newcandidates.end() - 1); // erase the last

    for(int i=0; i * x <= target; i++)
    {
      if(i * x == target)
      {
        vector<int> temp;
        for(int m=0; m<i; m++){ temp.push_back(x); }
        result.push_back(temp);
        continue;
      } // end of: if(i * x == target)

      vector<vector<int> > re = combinationSum1(newcandidates, target - i * x);
      if(re.size()!= 0)
      {
        for(int j=0; j<re.size(); j++)
        {
          for(int m=0; m<i; m++){ re[j].push_back(x); }
          result.push_back(re[j]);
        }
      } // end of: if(re.size()!= 0)
    } // end of: for(int i=0; i * x <= target; i++)
    
    return  result;
  } // end of: combinationSum(vector<int> &candidates, int target)

  vector<vector<int> > combinationSum2(vector<int> &candidates, int target)   {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > result;
  
    // if target == 0 return empty
    if(target <= 0) return result;
    if(candidates.size() == 0) return result;

    // check if the candidate is in order
    // if not, sort the candidate
    for(int i=1; i < candidates.size(); i++)
      if(candidates[i] < candidates[i-1]) {
        sort(candidates.begin(), candidates.end());
        break;
      }
  
    // if candidate[0] > target, return empty
    if(candidates[0] > target) return result;
  
    // copy the candidate
    vector<int> newcandidates(candidates);
	int num = 0; // num

    // for i: candidate[n] * 0 ~ num
    int x = *(newcandidates.end() - 1); // x is the max item
	while(newcandidates.size() != 0 && x == *(newcandidates.end() - 1))
	{
	  newcandidates.erase(newcandidates.end() - 1); // erase the last
	  num++;
	}

    for(int i=0; i<=num ; i++) // let candidate appear 0 ~ num times
    {
      if(i * x == target)
      {
        vector<int> temp;
        for(int m=0; m<i; m++){ temp.push_back(x); }
        result.push_back(temp);
        continue;
      } // end of: if(i * x == target)

      vector<vector<int> > re = combinationSum2(newcandidates, target - i * x);
      if(re.size()!= 0)
      {
        for(int j=0; j<re.size(); j++)
        {
          for(int m=0; m<i; m++){ re[j].push_back(x); }
          result.push_back(re[j]);
        }
      } // end of: if(re.size()!= 0)
    } // end of: for(int i=0; i * x <= target; i++)
    
    return  result;
  } // end of: combinationSum(vector<int> &candidates, int target)
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
  int inputArray[] = {10,1,2,7,6,1,5}; //{2,3,6,7};
  vector<int> input(inputArray,end(inputArray));
  int target = 8;//7;

  Solution s;
  vector<vector<int> > result1 = s.combinationSum1(input, target);
  vector<vector<int> > result2 = s.combinationSum2(input, target);

  cout << endl << "result1: [" << endl;
  for(int i=0; i<result1.size(); i++)
  {
    cout << " ";
    PrintVec<int>(result1[i]);
  }
  cout << "]" << endl;
  

  cout << endl << "result2: [" << endl;
  for(int i=0; i<result2.size(); i++)
  {
    cout << " ";
	PrintVec<int>(result2[i]);
  }
  cout << "]" << endl;
  getchar();
  return 0;
}