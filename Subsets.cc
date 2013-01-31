/*
Subsets

http://leetcode.com/onlinejudge#question_78

Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

=======================================================================
Subsets II

http://leetcode.com/onlinejudge#question_90

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        if(S.size() == 0) {
            vector<int> empty;
            result.push_back(empty);
            return result;
        }
        
        // sort S if it's not in order
        for(int i=1; i < S.size(); i++)
            if(S[i] < S[i-1]) {
                sort(S.begin(), S.end());
                break;
            }
            
        vector<int> newS(S.begin(), S.end());
        
        int x = *(newS.end() - 1); // x is the max item
        newS.erase(newS.end() - 1); // erase the last
    
        for(int i=0; i<=1; i++) { // let candidate appear 0 or 1 time
            vector<vector<int> > re = subsets(newS);
            for(int j=0; j<re.size(); j++) {
                if(i!=0) re[j].push_back(x);
                result.push_back(re[j]);
            } // end of: for(int j=0; j<re.size(); j++)
        } // end of: for(int i=0; i * x <= target; i++)
        
        return  result;
    } // end of: vector<vector<int> > subsets(vector<int> &S)
    
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > result;
        if(S.size() == 0) {
            vector<int> empty;
            result.push_back(empty);
            return result;
        }
        
        // sort S if it's not in order
        for(int i=1; i < S.size(); i++)
            if(S[i] < S[i-1]) {
                sort(S.begin(), S.end());
                break;
            }
            
        // copy the candidate
        vector<int> newS(S);
        int num = 0;

        int x = *(newS.end() - 1); // x is the max item
        while(newS.size() != 0 && x == *(newS.end() - 1))
        {
          newS.erase(newS.end() - 1); // erase the last
          num++;
        }
    
        for(int i=0; i<=num ; i++) { // let candidate appear 0 ~ num times
            vector<vector<int> > re = subsetsWithDup(newS);
            for(int j=0; j<re.size(); j++) {
                for(int m=0; m<i; m++){ re[j].push_back(x); }
                result.push_back(re[j]);
            } // end of: for(int j=0; j<re.size(); j++)
        } // end of: for(int i=0; i<=num ; i++)
        
        return  result;
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

  Solution s;
  vector<vector<int> > result1 = s.subsets(input);

  cout << endl << "result1: [" << endl;
  for(int i=0; i<result1.size(); i++)
  {
    cout << " ";
    PrintVec<int>(result1[i]);
  }
  cout << "]" << endl;
  getchar();
  return 0;
}