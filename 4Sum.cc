/*
4Sum
Given an array S of n integers, are there elements a, b, c, 
and d in S such that a + b + c + d = target Find all unique 
quadruplets in the array which gives the sum of target.

Note
Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
(ie, a ¡Ü b ¡Ü c ¡Ü d)
The solution set must not contain duplicate quadruplets.

For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

class Solution {
public:

    vector<vector<int> > fourSum(vector<int> &candidates, int target) {

		vector<vector<int> > result;
		if(candidates.size() < 4) return result;
		
		
		// sort the candidates if the candidates is not in order
		for(int i=1; i < candidates.size(); i++)
			if(candidates[i] < candidates[i-1]) {
				sort(candidates.begin(), candidates.end());
				break;
			}

		int size = candidates.size();
		for(int p1=0; p1<candidates.size()-3;p1++)
		{
			if(candidates[p1] + candidates[p1+1] + candidates[p1+2] + candidates[p1+3] > target) break;
			if(candidates[size-4] + candidates[size-3] + candidates[size-2] + candidates[size-1] < target) break;
			if(p1>0 && candidates[p1] == candidates[p1-1]) continue;
			for(int p2=p1+1; p2<candidates.size()-2;p2++)
			{
				if(candidates[p1] + candidates[p2] + candidates[p2+1] + candidates[p2+2] > target) break;
				if(candidates[size-3] + candidates[size-2] + candidates[size-1] < target - candidates[p1]) break;
				if(p2>p1+1 && candidates[p2] == candidates[p2-1]) continue;
				for(int p3=p2+1; p3<candidates.size()-1;p3++)
				{
					if(candidates[p1] + candidates[p2] + candidates[p3] + candidates[p3+1] > target) break;
					if(candidates[size-2] + candidates[size-1] < target - candidates[p1] - candidates[p2]) break;
					if(p3>p2+1 && candidates[p3] == candidates[p3-1]) continue;
					for(int p4=p3+1; p4<candidates.size();p4++)
					{
						if(candidates[p1] + candidates[p2] + candidates[p3] + candidates[p4] > target) break;
						if(candidates[size-1] < target - candidates[p1] - candidates[p2] - candidates[p3]) break;
						if(p4>p3+1 && candidates[p4] == candidates[p4-1]) continue;
						if(candidates[p1] + candidates[p2] + candidates[p3] + candidates[p4] == target)
						{
							vector<int> temp;
							temp.push_back(candidates[p1]);
							temp.push_back(candidates[p2]);
							temp.push_back(candidates[p3]);
							temp.push_back(candidates[p4]);
							result.push_back(temp);
						}
					}
				}
			}
		}
		return result;
    } // end of: fourSum(vector<int> &candidates, int target)

    vector<vector<int> > fourSum2(vector<int> &candidates, int target) {

		vector<vector<int> > result;
		if(candidates.size() < 4) return result;
		
		// sort the candidates if the candidates is not in order
		for(int i=1; i < candidates.size(); i++)
			if(candidates[i] < candidates[i-1]) {
				sort(candidates.begin(), candidates.end());
				break;
			}
		
		vector<int> prefix;
		numSum(candidates, target, 4, prefix, 0, result);
		return result;
    } // end of: fourSum(vector<int> &candidates, int target)

	// get the numbers that just sum up to the target
    void numSum(vector<int> &candidates, int target, int num, 
		vector<int> &prefix, int start, vector<vector<int> > &result) {

		if(candidates.size()<start+num || num<=0) return;

		int tempsum1 = 0;
		int tempsum2 = 0;
		for(int i=0; i< num; i++)
		{
			tempsum1 += candidates[start + i];
			tempsum2 += candidates[candidates.size()-1-i];
		}
		
		if(tempsum1 > target || tempsum2 < target) return;
		
		for(int i=start; i<=candidates.size()-num; i++)
		{
			if(i>start && candidates[i] == candidates[i-1]) continue;
			
			prefix.push_back(candidates[i]);
			
			if(num == 1 && candidates[i] == target)
				result.push_back(prefix);
			else if(num > 1)
				numSum(candidates, target-candidates[i], num-1, prefix, i+1, result);
			
			prefix.erase(prefix.end()-1);
		}
    } // end of: numSum(vector<int> &candidates, int target)
};

void main()
{
	int inputArray[] = {1, 0, -1, 0, -2, 2};
	vector<int> input(inputArray,end(inputArray));
	int target = 0;

	Solution s;
	vector<vector<int> > result = s.fourSum(input, target);

	cout << endl << "result: [" << endl;
	for(int i=0; i<result.size(); i++)
	{
		cout << " ";
		PrintVec<int>(result[i]);
	}
	
	cout << "]" << endl;
	getchar();
}