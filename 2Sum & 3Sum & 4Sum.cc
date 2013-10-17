/*
TwoSum

http://leetcode.com/onlinejudge#question_1

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

=======================================================================

3Sum

http://leetcode.com/onlinejudge#question_15

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


=======================================================================    
4Sum

http://leetcode.com/onlinejudge#question_18

Given an array S of n integers, are there elements a, b, c, and d in S 
such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:

Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ? b ? c ? d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

// =======================================================================
// TwoSum
// simple solution, time comlexity o(n^2), space complexity o(1)
// should have o(n log n) solution

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        
        for(int i=0; i<numbers.size(); ++i)
        for(int j=i+1; j<numbers.size(); ++j)
            if(numbers[i] + numbers[j] == target) {
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
        return result;
    }
};


// =======================================================================
// 3Sum
// 276 milli secs pass large judge
// time comlexity o(n^2 * log n), space complexity o(n^3)

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num, int target=0) {
        if(num.size()<3) return vector<vector<int> > ();
        vector<vector<int> > result;
        
        sort(num.begin(), num.end()); // sort the numbers for efficiency
        
        for(int i=0; i<num.size()-2;) {
            if(num[i]*3>target || num.back()*3<target) break; // early break
            
            for(int j=i+1; j<num.size()-1;) {
                if(num[j]*2>target-num[i] || num.back()*2<target-num[i]) break; // early break
                
                // use binary search to find the third number add up to 0
                if(binary_search(num.begin()+j+1, num.end(), 0-num[i]-num[j])) {
                    result.push_back(vector<int>());
                    result.back().push_back(num[i]);
                    result.back().push_back(num[j]);
                    result.back().push_back(0-num[i]-num[j]);
                }
                do {++j;} while(j<num.size() && num[j]==num[j-1]); // next unique
            }
            do {++i;} while(i<num.size() && num[i]==num[i-1]); // next unique
        }
        
        return result;
    }
};

// =======================================================================
// 4Sum
// 84 milli secs pass large judge
// time comlexity o(n^3 log n), space complexity (n^4)

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if(num.size() < 4) return vector<vector<int> > ();
        vector<vector<int> > result;
        
        sort(num.begin(), num.end()); // sort the numbers for efficiency
        
        for(int i=0; i<num.size()-3;) {
            if(num[i]*4>target || num.back()*4<target) break; // early break
            
            for(int j=i+1; j<num.size()-2;) {
                if(num[j]*3>target-num[i] || num.back()*3<target-num[i]) break; // early break
                
                for(int k=j+1; k<num.size()-1;) {
                    int candidate = target-num[i]-num[j]-num[k];
                    if(num[k]>candidate || num.back()*2<candidate+num[k]) break; // early break
                    
                    if(binary_search(num.begin()+k+1, num.end(), candidate)) {
                        result.push_back(vector<int>());
                        result.back().push_back(num[i]);
                        result.back().push_back(num[j]);
                        result.back().push_back(num[k]);
                        result.back().push_back(candidate);
                    }
                    do {++k;} while(k<num.size()&&num[k]==num[k-1]);  // next unique
                }
                do {++j;} while(j<num.size()&&num[j]==num[j-1]); // next unique
            }
            do {++i;} while(i<num.size()&&num[i]==num[i-1]); // next unique
        }
        
        return result;
    }
};


// =======================================================================
// 3Sum / 4Sum version 2
// can be extanded to any number sum
// 296 milli secs pass large judge for 3Sum
// 84 milli secs pass large judge for 4Sum
// time comlexity o(n^(k-1) log n), space complexity (n^k) for k sum

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &candidates, int target=0) {
		return numSum(candidates, target, 3);
    }

    vector<vector<int> > fourSum(vector<int> &candidates, int target=0) {
		return numSum(candidates, target, 4);
    }
    
    vector<vector<int> > numSum(vector<int> &candidates, int target, int num) {
        if(candidates.size() < num) return vector<vector<int> > ();
        
		sort(candidates.begin(), candidates.end()); // sort the numbers for efficiency
        vector<vector<int> > result;
		vector<int> prefix;
		numSum(candidates, target, num, prefix, 0, result);
        
		return result;
    }

    // get the numbers that just sum up to the target
    void numSum(vector<int> &candidates, int target, int num, 
		vector<int> &prefix, int start, vector<vector<int> > &result) {
        
        if(num==1) { // if num == 1, use binary search to find the target
            if(binary_search(candidates.begin()+start, candidates.end(), target)) {
                prefix.push_back(target); // use prefix to do back tracking
                result.push_back(prefix);
                prefix.pop_back(); // back tracking
            }
            return;
        } 
        
		for(int i=start; i<=candidates.size()-num;) { // get the prefix that sum up to a specifit num
            if(candidates[i]*num>target || candidates.back()*num<target) break; // early break
            
			prefix.push_back(candidates[i]); // use prefix to do back tracking
            numSum(candidates, target-candidates[i], num-1, prefix, i+1, result);
			prefix.pop_back(); // back tracking
            
            do{++i;} while(i<=candidates.size()-num && candidates[i]==candidates[i-1]); // next unique
		}
    } // end of: numSum(vector<int> &candidates, int target)
};