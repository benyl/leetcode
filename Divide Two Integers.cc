/*
Divide Two Integers

http://leetcode.com/onlinejudge#question_29

Divide two integers without using multiplication, division and mod operator.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return 0;
        
        bool sign = false;
        if((dividend<0 && divisor>0) || 
           (dividend>0 && divisor<0)) {
            sign = true;
        }
        
        unsigned int dend = (dividend>=0) ? dividend : (-dividend);
        unsigned int dsor = (divisor>=0) ? divisor : (-divisor);
        
        if(dsor>dend) return 0;
        
        int bits=0;
        while(dsor<dend){
            dsor = dsor << 1;
            bits++;
        }
        
        int quot = 0;
        while(bits >=0 ) {
            if(dend >= dsor) {
                quot |= 1 << bits;
                dend -= dsor;
            }
            if(dend==0) break;
            dsor = dsor >> 1;
            bits--;
        }
        
        if(sign) quot = 0 - quot;
        return quot;
    }
};