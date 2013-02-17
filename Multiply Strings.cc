/*
Multiply Strings

http://leetcode.com/onlinejudge#question_43

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

*/

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<char> result(num1.size() + num2.size(), '0');
        
        for(int i=0; i<num1.size(); i++)
        for(int j=0; j<num2.size(); j++) {
            int pos = i+j+1;
            int carry = (num1[i] - '0') * (num2[j] - '0');

            while(pos>0 && result[pos] + carry > '9' ) {
                char remain = (result[pos] - '0' + carry) % 10 + '0';
                carry = (result[pos] - '0' + carry) / 10;
                result[pos] = remain;
                pos --;
            }

            result[pos] += carry;
        }
                
        while(result.size()>1 && result[0] == '0') {
            result.erase(result.begin());
        }
            
        return string(result.begin(), result.end());
    }
};