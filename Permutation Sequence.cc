/*
Permutation Sequence

http://leetcode.com/onlinejudge#question_60

The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        k--; // index start from 0
        
        vector<int> com(n, 1);
        for(int i=n-2;i>=0;i--)
            com[i] = com[i+1] * (n-i-1);
 
        for(int i=0;i<n;i++) {
            int quo = k/com[i]; // quotient
            k %= com[i];        // remainder
            com[i] = quo;
        }
        
        vector<int> num(n, 1);
    	for(int i=0;i<n;i++)
            num[i] = i+1;

		for(int i=0;i<n;i++){
			int temp = num[com[i]];
			num.erase(num.begin()+com[i]);
			com[i] = temp;
		}
        
        stringstream ss;
        for(int i=0;i<n;i++) 
            ss << com[i];
        
        return ss.str();
    }
};