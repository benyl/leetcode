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
// large judge: 144 milli secs
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        if(target<=0 || candidates.size()==0) return result;

        // sort the candidate (may need remove duplicate)
        sort(candidates.begin(), candidates.end());
    
        if(candidates[0] > target) return result;

        int x = candidates.back(); // x is the max item
        candidates.pop_back(); // erase the last element
        
        // for i: candidate[n] * 0 ~ target/n
        for(int i=0; i * x <= target; i++) {
            if(i * x == target) {
                result.push_back(vector<int>(i, x)); // combination that exactly match
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
// large judge: 100 milli secs
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        if(target <= 0 || candidates.size() == 0) return result;

        // sort the candidate (may need remove duplicate)
        sort(candidates.begin(), candidates.end());
    
        if(candidates[0] > target) return result;

        int x = candidates.back(), count = 0; // x is the max item
        while(candidates.back()==x) {
            candidates.pop_back(); // erase the last element
            ++count;
        }
        
        // for i: candidate[n] * 0 ~ target/n
        for(int i=0; i*x<=target && i<=count; i++) {
            if(i * x == target) {
                result.push_back(vector<int>(i, x));
            } else {
                vector<vector<int> > re = combinationSum2(candidates, target - i * x);
                for(int j=0; j<re.size(); j++)
                    re[j].insert(re[j].end(), i, x); // add x to end of results
                result.insert(result.end(), re.begin(), re.end());
            }
        } // end of: for(int i=0; i * x <= target; i++)
        
        candidates.insert(candidates.end(), count, x); // add x back for back tracking
        
        return result;
    } // end of: combinationSum(vector<int> &candidates, int target)
};