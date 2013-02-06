/*
Letter Combinations of a Phone Number

http://leetcode.com/onlinejudge#question_17

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public: 
    vector<string> letterCombinations(string digits) {
        string letter[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if(digits.size() == 0) return vector<string>(1, "");
        
        vector<string> result;
        vector<string> re = letterCombinations(digits.substr(1));
        int num = digits[0] - '0';
        for(int i=0; i<letter[num].size(); i++)
        for(int j=0; j<re.size(); j++)
            result.push_back(letter[num][i] + re[j]);
        
        return result;
    }
};