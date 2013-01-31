/*
Anagrams
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

For example, given candidate set ["tea","and","ate","eat","den"]
A solution set is: ["tea","ate","eat"]
*/

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		vector<string> result;

		if(strs.size()< 2) return result;

		map<string, vector<string> > strsmap;
        // sort the string in the vector
		// and insert the string into hash map
		for(int i=0;i<strs.size(); i++)
		{
			string key = strs[i];
			sort(key.begin(),key.end());
			strsmap[key].push_back(strs[i]);

			if(strsmap[key].size() == 2)
			{
				result.push_back(strsmap[key][0]);
				result.push_back(strs[i]);
			}
			else if(strsmap[key].size() > 2)
			{
				result.push_back(strs[i]);
			}
		}

		// return the strings that has anagrams
		return result;
    }
};

template <class T>
void PrintVec(vector<T> vec)
{
	for(int i=0; i<vec.size(); i++)	
		cout << vec[i] << " ";
	cout << endl;
}

int main()
{
  const char *input[] = {"ute","fey","toe","lob","pet","ted","olb","bye","car","peg","maw","ote","has","dot","tam"};
  vector<string> strs(input, end(input));

  cout << "input: ";
  PrintVec<string>(strs);

  Solution sol;

  vector<string> result = sol.anagrams(strs);

  cout << "result: ";
  PrintVec<string>(result);

  getchar();
  return 0;
}