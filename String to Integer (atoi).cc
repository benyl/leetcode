/*
String to Integer (atoi)

http://leetcode.com/onlinejudge#question_8

Implement atoi to convert a string to an integer.

Hint: 
Carefully consider all possible input cases. If you want a challenge,
please do not see below and ask yourself what are the possible input cases.

Notes: 
It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.

Requirements for atoi:
The function first discards as many whitespace characters as necessary 
until the first non-whitespace character is found. Then, starting from 
this character, takes an optional initial plus or minus sign followed 
by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the 
integral number, which are ignored and have no effect on the behavior 
of this function.

If the first sequence of non-whitespace characters in str is not a valid
integral number, or if no such sequence exists because either str is 
empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. 
If the correct value is out of the range of representable values, 
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

class Solution {
public:
    int atoi(const char *str) {
        long long result=0;
        bool start=false, sign=true; // numbers start flag, and sign
        
        while(*str!='\0') {
            if(*str>='0' && *str<='9') { // 0 ~ 9
                start = true;
                result *= 10;
                result += *str - '0';
                if(result>=INT_MAX) break;
            } else if(start) { // invalid char after number
                break;
            } else if(*str=='+' || *str=='-') { // + / -
                sign = (*str=='+');
                start = true;
            } else if(*str!=' ') { // invalid char before any number
                break;
            }
            ++str;
        }
        
        if(sign && result>=INT_MAX) return INT_MAX;
        if(!sign && result*-1<=INT_MIN) return INT_MIN;
        return  result * ((sign) ? 1 : -1);
    }
};