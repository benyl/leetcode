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

// pass large judge with 68 milli secs
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        
        if(n<k || n<=0 || k<=0) return result;
        if(k==1) {
            result = vector<vector<int> >(n, vector<int>(1, 0));
            for(int i=0; i<n; ++i)
                result[i][0] = i+1;
            return result;
        }
        if(k==n) {
            result = vector<vector<int> >(1, vector<int>(n, 0));
            for(int i=0; i<n; ++i)
                result[0][i] = i+1;
            return result;
        }
        
        result = combine(n-1, k);
        vector<vector<int> > temp = combine(n-1, k-1);
        for(int i=0; i<temp.size(); ++i)
            temp[i].push_back(n);
        
        result.insert(result.end(), temp.begin(), temp.end());
        return result;
    }
};


//=====================================================
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