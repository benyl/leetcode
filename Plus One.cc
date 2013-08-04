/*
Plus One

http://leetcode.com/onlinejudge#question_66

Given a number represented as an array of digits, plus one to the number.
*/

//====================================================================
// add in place
// 24 milli secs pass lerge judge
// time complexity o(n), space complexity o(1)

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        for(int i=digits.size()-1; i>=0; --i) {
            digits[i] += 1; // plus one
            bool carry = digits[i]>9; // check carry bit
            digits[i] %= 10;
            if(!carry) break; // stop if no carry bit
            if(i==0) digits.insert(digits.begin(), 1); // carry bit before the head
        }
        return digits;
    }
};
