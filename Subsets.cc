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
    
    
    
    
    // ======================================================
    // Subsets II
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


// ======================================================
// iterative version, bottom up approach
// ======================================================

class Solution {
public:

    // ======================================================
    // Subsets I
    vector<vector<int> > subsets(vector<int> &S) {
        if(S.size()==0) return vector<vector<int> > ();
        
        sort(S.begin(), S.end()); // sort S before getting result
        
        vector<vector<int> > result;
        vector<int> range; // result in [range[i-1] ~ range[i]-1] contains i numbers
            
        result.push_back(vector<int>()); // put empty set at first
        range.push_back(result.size()); // result[0] contains 0 number
        
        for(int i=0; i<S.size(); ++i) // generate subsets that contains only one number
            result.push_back(vector<int>(1, S[i]));
        range.push_back(result.size()); // result[1 ~ S.size()] contains 1 number
            
        // get subsets in botton up approach
        for(int i=2; i<=S.size(); ++i) { // generate subsets that contains i numbers
            for(int j=range[i-2]; j<range[i-1]; ++j) // get the results that contains i-1 numbers
                for(int k=S.size()-1; k>=0; --k) { 
                    if(S[k] <= result[j].back()) break; // only put numbers bigger then last one
                    result.push_back(result[j]);
                    result.back().push_back(S[k]); // construct new subsets base on previous result
                }
            range.push_back(result.size()); // save the ranges of result that contains i numbers
        }
        
        return result;
    }
    
    
    // ======================================================
    // Subsets II
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        if(S.size() == 0) return vector<vector<int> >();
        
        sort(S.begin(), S.end()); // sort S before getting result
        
        vector<vector<int> > result;
        vector<int> unique, num, range; // result in [range[i-1] ~ range[i]-1] contains i UNIQUE numbers
        
        for(int i=0; i<S.size(); ++i) {
            if(i==0 || S[i]!=S[i-1]) {
                unique.push_back(S[i]); // store the unique numbers in S
                num.push_back(0); // count the unique numbers in S
            }
            num.back()++;
        }
        
        result.push_back(vector<int>()); // put empty set at first
        range.push_back(result.size()); // result[0] contains 0 number
        
        for(int i=0; i<unique.size(); ++i) // generate subsets that contains only one UNIQUE number
            for(int j=0; j<num[i]; ++j) // unique[i] can repeat 1 ~ num[i] times
                result.push_back(vector<int>(j+1, unique[i]));
        range.push_back(result.size()); // save the ranges of result that contains one UNIQUE number
        
        for(int i=2; i<=unique.size(); ++i) { // generate subsets that contains i UNIQUE numbers
            for(int j=range[i-2]; j<range[i-1]; ++j) // get the results that contains i-1 UNIQUE numbers
                for(int k=unique.size()-1; k>=0; --k) {
                    if(unique[k]<=result[j].back()) break; // only put numbers bigger then last one
                    vector<int> temp = result[j];
                    for(int l=0; l<num[k]; ++l) {
                        temp.push_back(unique[k]); // construct new subsets base on previous result
                        result.push_back(temp);
                    }
                }
            range.push_back(result.size()); // save the ranges of result that contains i numbers
        }
        return result;
    }
};