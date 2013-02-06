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

class Solution {
public:
    string intToRoman(int num) {
        if(num<0 || num>3999) return string("");
        
        return digitSymbol(num, 1000, ' ', ' ', 'M') + 
               digitSymbol(num, 100,  'M', 'D', 'C') + 
               digitSymbol(num, 10,   'C', 'L', 'X') + 
               digitSymbol(num, 1,    'X', 'V', 'I');
    }
    
    string digitSymbol(int num, int base, char ten, char five, char one) {
        int val = num / base % 10;
        string result = "";
        if(val >= 9){
            result += one;
            result += ten;
            val -= 9;
        }
        
        if(val >= 5){
            result += five;
            val -= 5;
        }
        
        if(val >= 4){
            result += one;
            result += five;
            val -= 4;
        }
        
        while(val>=1) {
            result += one;
            val -= 1;
        }
        return result;
    }
    
    int romanToInt(string s) {
        map<char, int> digit;
        digit.insert(make_pair('I', 1));
        digit.insert(make_pair('V', 5));
        digit.insert(make_pair('X', 10));
        digit.insert(make_pair('L', 50));
        digit.insert(make_pair('C', 100));
        digit.insert(make_pair('D', 500));
        digit.insert(make_pair('M', 1000));
        
        int result = digit[s[0]];
        for(int i=1; i<s.size(); i++) {
            result += digit[s[i]];
            if(digit[s[i]] > digit[s[i-1]]) {
                result -= digit[s[i-1]] * 2;
            }
        }
        return result;
    }
    
    // version 2
    int romanToInt2(string s) {
        return symbolDigit(s, 1000, ' ', ' ', 'M', 'C') + 
               symbolDigit(s, 100,  'M', 'D', 'C', 'X') + 
               symbolDigit(s, 10,   'C', 'L', 'X', 'I') + 
               symbolDigit(s, 1,    'X', 'V', 'I', ' ');
    }
    
    int symbolDigit(string s, int base, char ten, char five, char one, char stop) {
        int result = 0;
        int index = 0;
        while(index!=s.size()) {
            if(s[index] == stop)
                return result;
            if(s[index] == five || s[index] == one) 
                break;
            else
                index++;
        }
        
        while(index!=s.size() && (s[index]==five || s[index]==one)) {
            if(s[index] == five) {
                result += 5; 
                index++;
                continue;
            }
            if(s[index] == one) {
                if(index!=s.size()+1 && s[index+1]==five) {
                    result += 4;
                    index += 2;
                    continue;
                }
                if(index!=s.size()+1 && s[index+1]==ten) {
                    result += 9;
                    index += 2;
                    continue;
                }
                result += 1;
                index++;
            }
        }
        return result * base;
    }
};