/*
3Sum Closest
Given an array S of n integers, find three integers in S 
such that the sum is closest to a given number, target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

// =======================================================================
// 3Sum Closest
// 184 milli secs pass large judge
// time comlexity o(n^2 log n), space complexity (1)

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end()); // sort the numbers for efficiency
        
        int closest = num[0]+num[1]+num[2]; // initial closet sum
        for(int i=0; i<num.size()-2; ++i) {
            for(int j=i+1; j<num.size()-1; ++j) {
                int cand = target-num[i]-num[j];
                auto itr = lower_bound(num.begin()+j+1, num.end(), cand); 
                // use binary search to find lower bound of candidate
                if(*itr==cand) return target;
                // compare sum with closet sum to target
                if(*itr-cand < abs(closest-target))
                    closest = num[i]+num[j]+*itr;
                // also check the biggest number that is smaller than candidate
                if(--itr - num.begin() > j && cand-*itr < abs(closest-target))
                    closest = num[i]+num[j]+*itr;
            }
        }
        
        return closest;
    }
};