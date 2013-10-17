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

// ======================================================
// recursive version, top down approach
// ======================================================

class Solution {
public:

    // ======================================================
    // Subsets I
    vector<vector<int> > subsets(vector<int> &S) {
        if(S.size() == 0) 
            return vector<vector<int> >(1, vector<int>());
        
        sort(S.begin(), S.end()); // sort S at first
        int x = S.back(); // srote the max item
        S.pop_back(); // erase the last
    
        vector<vector<int> > result = subsets(S); // get the subsets without x
        for(int i=result.size()-1; i>=0; --i) {
            result.push_back(result[i]);
            result.back().push_back(x); // copy the subsets and add x to end
        }
        
        return  result;
    } // end of: vector<vector<int> > subsets(vector<int> &S)
    
    // ======================================================
    // Subsets II
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        if(S.size() == 0) return vector<vector<int> >(1, vector<int>());
        
        sort(S.begin(), S.end()); // sort S at first
        int x = S.back(), num = 0; // srote the max item and frequency
        while(S.size()>0 && S.back()==x) 
            {S.pop_back(); ++num;} // erase the max item and count frequency
            
        vector<vector<int> > result = subsetsWithDup(S);  // get the subsets without x
        for(int i=result.size()-1; i>=0; --i) {
            result.push_back(result[i]); // copy the subsets and add x to end
            result.back().push_back(x);
            for(int j=2; j<=num; ++j) { // let candidate appear 1 ~ num times
                result.push_back(result.back()); // copy the subsets and add x to end
                result.back().push_back(x);
            }
        }
        
        return  result;
    } // end of: vector<vector<int> > subsetsWithDup(vector<int> &S)
};


// ======================================================
// iterative version, bottom up approach
// ======================================================

class Solution {
public:

    // ======================================================
    // Subsets I
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end()); // sort S before getting result
        vector<vector<int> > result(1, vector<int>()); // put empty set at first
        
        for(int i=0; i<S.size(); ++i) { // generate subsets that contains S[0~i]
            for(int j=result.size()-1; j>=0; --j) { // get the subsets without S[i]
                result.push_back(result[j]); // copy the subsets and add S[i] to end
                result.back().push_back(S[i]);
            }
        }
        
        return result;
    }
    
    
    // ======================================================
    // Subsets II
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end()); // sort S before getting result
        vector<vector<int> > result(1, vector<int>()); // put empty set at first
        
        for(int i=0, num=1; i<S.size(); i+=num, num=1) { // generate subsets that contains S[0~i]
            while(i+num<S.size() && S[i+num]==S[i]) ++num; // count the frequency of S[i]
            for(int j=result.size()-1; j>=0; --j) { // get the subsets without S[i]
                result.push_back(result[j]); // copy the subsets and add S[i] to end
                result.back().push_back(S[i]); // let S[i] appear 1 time
                for(int k=2; k<=num; ++k) { // let S[i] appear 2 ~ num times
                    result.push_back(result.back()); // copy the subsets and add S[i] to end
                    result.back().push_back(S[i]);
                }
            }
        }
        return result;
    }
};
