/*
3Sum Closest
Given an array S of n integers, find three integers in S 
such that the sum is closest to a given number, target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
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
    int threeSumClosest(vector<int> &num, int target) {
		if(num.size() < 3) return 0;
				
		// sort the num if the num is not in order
		for(int i=1; i < num.size(); i++)
			if(num[i] < num[i-1]) {
				sort(num.begin(), num.end());
				break;
			}

		int size = num.size();
		int closest = num[0] + num[1] + num[2];
		int distance_closest = (closest>target)?(closest-target):(target-closest);

		for(int p1=0; p1<num.size()-2;p1++)
		{
			if(p1>0 && num[p1] == num[p1-1]) continue;
			for(int p2=p1+1; p2<num.size()-1;p2++)
			{
				if(p2>p1+1 && num[p2] == num[p2-1]) continue;
				for(int p3=p2+1; p3<num.size();p3++)
				{
					if(p3>p2+1 && num[p3] == num[p3-1]) continue;
					int sum = num[p1] + num[p2] + num[p3];
					int distance = (sum>target)? (sum-target):(target-sum);
					
					if(distance < distance_closest)
					{
						closest = sum;
						distance_closest = distance;
						if(distance == 0) return sum;
					}
				}
			}
		}
		return closest;
    } // end of: threeSumClosest(vector<int> &num, int target)
};

void main()
{
	int inputArray[] = {-1, 2, 1, -4};
	vector<int> input(inputArray,end(inputArray));
	int target = 1;

	Solution s;
	int result = s.threeSumClosest(input, target);

	cout << "input: ";
	PrintVec<int>(input);
	cout << "target: " << target << endl;
	cout << "result: " << result << endl;

	getchar();
}