/*
Integer to Roman

http://leetcode.com/onlinejudge#question_12

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

=======================================================================
Roman to Integer

http://leetcode.com/onlinejudge#question_13

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

// =======================================================================
// Integer to Roman
// 128 milli secs pass large judge

class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        char *symbol = "IVXLCDM"; // I, V, X, L, C, D, M
        if(num >= 4000) num %= 4000;
        
        for(int x=num%10; num>0; num/=10, symbol+=2, x=num%10) {
            if(num==0) {
                break;
            } else if(x==0) {
                continue;
            } else if(x<4) { // I, II, III
                roman.insert(roman.begin(), x, symbol[0]);
            } else if(x==4) { // IV
                roman = symbol[0] + (symbol[1] + roman);
            } else if(x<9){ // V, VI, VII, VIII
                roman.insert(roman.begin(), x-5, symbol[0]);
                roman = symbol[1] + roman;
            } else { // IX
                roman = symbol[0] + (symbol[2] + roman);
            }
        }
        
        return roman;
    }
};


// =======================================================================
// Roman to Integer
// 128 milli secs pass large judge

class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        char *symbol = "IVXLCDM?!"; // I, V, X, L, C, D, M
        
        for(int i=s.size()-1, base=1; i>=0; --i) {
            if(s[i]==symbol[0]) { // I
                num += base;
                if(i!=s.size()-1 && 
                  (s[i+1]==symbol[1] || s[i+1]==symbol[2])) // IV, IX
                    num -= 2 * base;
            } else if(s[i]==symbol[1]) { // V
                num += 5 * base;
            } else if(s[i]==symbol[2]) { // X
                num += 10 * base;
            } else { // others, change base
                base *= 10;
                symbol += 2;
                ++i; // skip --i
            }
        }
        
        return num;
    }
};

// =======================================================================
// Roman to Integer, version 2

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> digit = {{'I', 1}, {'V', 5}, {'X', 10}, 
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int result = digit[s[0]];
        for(int i=1; i<s.size(); i++) {
            result += digit[s[i]];
            if(digit[s[i]] > digit[s[i-1]]) {
                result -= digit[s[i-1]] * 2;
            }
        }
        return result;
    }
};