/*
=============================================
Combination Sum I

Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

=============================================
Combination Sum II
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

// =====================================================================
// Combination Sum I
// large judge: 172 milli secs
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        if(target <= 0 || candidates.size() == 0) return result;

        // sort the candidate and remove duplicate
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    
        if(candidates[0] > target) return result;

        int x = candidates.back(); // x is the max item
        candidates.pop_back(); // erase the last element
        
        // for i: candidate[n] * 0 ~ target/n
        for(int i=0; i * x <= target; i++) {
            if(i * x == target) {
                result.push_back(vector<int>(i, x));
            } else {
                vector<vector<int> > re = combinationSum(candidates, target - i * x);
                for(int j=0; j<re.size(); j++)
                    re[j].insert(re[j].end(), i, x); // add x to end of results
                result.insert(result.end(), re.begin(), re.end());
            }
        } // end of: for(int i=0; i * x <= target; i++)
        
        candidates.push_back(x); // add x back for back tracking
        
        return result;
    } // end of: combinationSum(vector<int> &candidates, int target)
};

// =====================================================================
// Combination Sum II
// 
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
    
        // if target == 0 return empty
        if(target <= 0) return result;
        if(candidates.size() == 0) return result;

        // check if the candidate is in order
        // if not, sort the candidate
        for(int i=1; i < candidates.size(); i++)
            if(candidates[i] < candidates[i-1]) {
                sort(candidates.begin(), candidates.end());
                break;
            }
    
        // if candidate[0] > target, return empty
        if(candidates[0] > target) return result;
    
        // copy the candidate
        vector<int> newcandidates(candidates);
        int num = 0; // num

        // for i: candidate[n] * 0 ~ num
        int x = *(newcandidates.end() - 1); // x is the max item
        while(newcandidates.size() != 0 && x == *(newcandidates.end() - 1))
        {
            newcandidates.erase(newcandidates.end() - 1); // erase the last
            num++;
        }

        for(int i=0; i<=num ; i++) // let candidate appear 0 ~ num times
        {
            if(i * x == target)
            {
                vector<int> temp;
                for(int m=0; m<i; m++){ temp.push_back(x); }
                result.push_back(temp);
                continue;
            } // end of: if(i * x == target)

            vector<vector<int> > re = combinationSum(newcandidates, target - i * x);
            if(re.size()!= 0)
            {
                for(int j=0; j<re.size(); j++)
                {
                    for(int m=0; m<i; m++){ re[j].push_back(x); }
                    result.push_back(re[j]);
                }
            } // end of: if(re.size()!= 0)
        } // end of: for(int i=0; i * x <= target; i++)
        
        return    result;
    } // end of: combinationSum(vector<int> &candidates, int target)
};
