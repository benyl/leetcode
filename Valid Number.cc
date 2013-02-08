/*
Valid Number

http://leetcode.com/onlinejudge#question_65

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: 
It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.

*/

class Solution {
public:
    bool isNumber(const char *s) {
        if(s==NULL) return false;
        if(*s==NULL) return false;
        
        bool start = false;
        bool point = false;
        bool exp   = false;
        
        while(*s!=NULL) {
            switch(*s) {
            case '+': 
                if(start==true && *(s-1)!='e') return false;
                if(*(s+1)==NULL) return false;
                if(*(s+1)!='.') 
                    if(*(s+1)-'0'<0 || *(s+1)-'0'>9)
                        return false;
                break;
            case '-': 
                if(start==true && *(s-1)!='e') return false;
                if(*(s+1)==NULL) return false;
                if(*(s+1)!='.') 
                    if(*(s+1)-'0'<0 || *(s+1)-'0'>9)
                        return false;
                break;
            case '.': 
                if(exp==true) return false;
                if(point==true) return false;
                if(*(s+1)!=NULL && *(s+1)!=' ' && *(s+1)!='e') 
                    if(*(s+1)-'0'<0 || *(s+1)-'0'>9)
                        return false;
                point=true;
                break;
            case 'e': 
                if(start==false) return false;
                if(exp==true) return false;
                if(*(s+1)==NULL) return false;
                if(*(s+1)!='+' && *(s+1)!='-') 
                    if(*(s+1)-'0'<0 || *(s+1)-'0'>9)
                        return false;
                exp=true;
                break;
            case ' ': 
                if(start==true || point==true)
                    if(*(s+1)!=' ' && *(s+1)!=NULL)
                        return false;
                break;
            default:            
                if(*s-'0'<0 || *s-'0'>9) return false;
                start = true;
            }
            s++;
        }
        return start;
    }
};