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

#define INT_MAX int(2147483647)
#define INT_MIN int(-2147483648)

class Solution {
public:
    int atoi(const char *str) {
        int result = 0;
        int sign = 1;
        bool start = false;
        
        while(str!=NULL && *str!=NULL){
            if(*str >= '0' && *str <= '9') {
                if(sign==-1 && (INT_MIN/10*-1 - result < 0 || 
                   INT_MIN + result*10 + *str - '0' > 0)) {
                    result = INT_MIN;
                    sign=1;
                    break;
                   }
                if(sign==1 && (INT_MAX/10 - result < 0 || 
                   INT_MAX - result*10 - *str + '0' < 0)) {
                    result = INT_MAX; 
                    break;
                   }
                result *= 10;
                result += *str - '0';
                start = true;
            } else if(*str=='+' || *str=='-') {
                if(start) break;
                sign = (*str=='+')?1:-1;
                start = true;
            } else if(*str==' ') {
                if(start) break;
            } else break;
            str++;
        }
        return result * sign;
    }
};