/*
String to Integer (atoi)

http://leetcode.com/onlinejudge#question_8

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