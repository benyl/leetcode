/*
3Sum
Given an array S of n integers, are there elements a, b, c in S 
such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. 
(ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
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
    vector<vector<int> > threeSum(vector<int> &num) {
		int target = 0;
		vector<vector<int> > result;
		if(num.size() < 3) return result;
				
		// sort the num if the num is not in order
		for(int i=1; i < num.size(); i++)
			if(num[i] < num[i-1]) {
				sort(num.begin(), num.end());
				break;
			}

		int size = num.size();
		for(int p1=0; p1<num.size()-2;p1++)
		{
			if(num[p1] + num[p1+1] + num[p1+2] > target) break;
			if(num[size-3] + num[size-2] + num[size-1] < target) break;
			if(p1>0 && num[p1] == num[p1-1]) continue;
			for(int p2=p1+1; p2<num.size()-1;p2++)
			{
				if(num[p1] + num[p2] + num[p2+1] > target) break;
				if(num[size-2] + num[size-1] < target - num[p1]) break;
				if(p2>p1+1 && num[p2] == num[p2-1]) continue;
				for(int p3=p2+1; p3<num.size();p3++)
				{
					if(num[p1] + num[p2] + num[p3]> target) break;
					if(num[size-1] < target - num[p1] - num[p2]) break;
					if(p3>p2+1 && num[p3] == num[p3-1]) continue;
					if(num[p1] + num[p2] + num[p3] == target)
					{
						vector<int> temp;
						temp.push_back(num[p1]);
						temp.push_back(num[p2]);
						temp.push_back(num[p3]);
						result.push_back(temp);
					}
				}
			}
		}
		return result;
    } // end of: threeSum(vector<int> &num)
};

void main()
{
	int inputArray[] = {1, 0, -1, 0, -2, 2};
	vector<int> input(inputArray,end(inputArray));

	Solution s;
	vector<vector<int> > result = s.threeSum(input);

	cout << endl << "result: [" << endl;
	for(int i=0; i<result.size(); i++)
	{
		cout << " ";
		PrintVec<int>(result[i]);
	}
	
	cout << "]" << endl;
	getchar();
}