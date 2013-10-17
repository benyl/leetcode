/*
Permutations

http://leetcode.com/onlinejudge#question_46

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

=======================================================================
Permutations II

http://leetcode.com/onlinejudge#question_47

Given a collection of numbers that might contain duplicates, 
return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:

    //=======================================================================
    // Permutations
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        
        if(num.size()==0) return result;
        if(num.size()==1) {
            result.push_back(num);
            return result;
            }
        
        int x = num[0], size = num.size();
        num.erase(num.begin());
        vector<vector<int> > re=permute(num);
        
        // insert x to all the possiable position in re
        for(int i=0; i<size; i++) {
            for(int j=0; j<re.size(); j++) {
                vector<int> temp(re[j]);
                temp.insert(temp.begin()+i, x);
                result.push_back(temp);
            }
        }
        
        return result;
    }
    
    //=======================================================================
    // Permutations II
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        
        if(num.size()==0) return result;
        if(num.size()==1) {
            result.push_back(num);
            return result;
            }
            
        sort(num.begin(), num.end());
        
        for(int i=0; i<num.size(); i++) {
            if(i==0 || (i!=0 && num[i] != num[i-1])) {
                vector<int> temp(num);
                temp.erase(temp.begin()+i);
                vector<vector<int> > re=permuteUnique(temp);
                
                for(int j=0; j<re.size(); j++) {
                    re[j].insert(re[j].begin(), num[i]);
                    result.push_back(re[j]);
                }
            }
        }
        
        return result;
    }
};


//=======================================================================
// test code
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
  int inputArray[] = {1,2,1};
  vector<int> input(inputArray,end(inputArray));

  Solution sol;
  vector<vector<int> > result1 = sol.permuteUnique(input);

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


//=======================================================================
// Permutations
// compact version, avoid copying

class Solution {
public:
    vector<vector<int> > result;
    
    vector<vector<int> > permute(vector<int> &num) {
        result.clear();
        getPermute(num, 0);
        return result;
    }
    
    void getPermute(vector<int> &num, int step) {
        if(step == num.size()-1)
            result.push_back(num);
            
        for(int i=step; i<num.size(); ++i) {
            swap(num[step], num[i]); // choose the rest of candidate
            getPermute(num, step+1);
            swap(num[step], num[i]); // recover for back tracking
        }
    }
};


//=======================================================================
// Permutations II
// compact version, avoid copying

class Solution {
public:
    vector<vector<int> > result;
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        result.clear();
        getPermuteUni(num, 0);
        return result;
    }
    
    void getPermuteUni(vector<int> &num, int step) {
        if(step == num.size()-1)
            result.push_back(num);
        sort(num.begin()+step, num.end());
        for(int i=step; i<num.size(); ++i) {
            if(i!=step && num[i]==num[i-1]) continue;
            swap(num[step], num[i]); // choose the rest of candidate
            getPermuteUni(num, step+1);
            sort(num.begin()+step, num.end());
        }
    }
};

