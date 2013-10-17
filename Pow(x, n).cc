/*
Pow(x, n)

http://leetcode.com/onlinejudge#question_50

Implement pow(x, n).
*/

class Solution {
public:
    double pow(double x, int n) {
        if(x==0 || x==1 || n==1) return x;
        if(n==0) return 1;
        if(n<0)  return 1/pow(x, -1-n)/x; // avoid INT_MIN
        return pow(x*x, n/2) * ((n%2) ? x : 1);
    }
};