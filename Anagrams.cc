/*
Anagrams
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

For example, given candidate set ["tea","and","ate","eat","den"]
A solution set is: ["tea","ate","eat"]
*/

// 228 milli secs pass large test
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // sort the string as key for the hash map
        map<string, vector<string> > strsmap;
		for(int i=0;i<strs.size(); i++) {
			string key = strs[i];
			sort(key.begin(),key.end());
			strsmap[key].push_back(strs[i]);
		}
        
        // insert all the strings that has anagrams
    	vector<string> result;
        for(auto iter=strsmap.begin(); iter!=strsmap.end(); iter++)
            if(iter->second.size()>1)
                result.insert(result.end(), iter->second.begin(), iter->second.end());

		// return the strings that has anagrams
		return result;
    }
};



// code for testing
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