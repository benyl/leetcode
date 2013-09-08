/*
Multiply Strings

http://leetcode.com/onlinejudge#question_43

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

*/

// ===================================================================
// version 1

class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(), '0');
        
        for(int i=0; i<num1.size(); i++)
        for(int j=0; j<num2.size(); j++) {
            int carry = (num1[i]-'0') * (num2[j]-'0');

            for(int pos=i+j+1; pos>=0 && carry>0; --pos) {
                int digit = result[pos] - '0' + carry;
                carry = digit / 10;
                result[pos] = digit % 10 + '0';
            }
        }
        
        while(result.size()>1 && result[0] == '0')
            result.erase(result.begin());
            
        return result;
    }
};


// ===================================================================
// version 2

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> digit(num1.size() + num2.size(), 0);
        string result(num1.size() + num2.size(), '0');
        
        for(int i=0; i<num1.size(); ++i)
        for(int j=0; j<num2.size(); ++j)
            digit[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
        
        for(int i=num1.size()+num2.size()-1; i>=0; --i) {
            if(i!=0) digit[i-1] += digit[i]/10;
            digit[i] %= 10;
            result[i] += digit[i];
        }
        
        while(result.size()>1 && result[0]=='0')
            result.erase(result.begin());
            
        return result;
    }
};