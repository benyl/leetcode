/*
Palindrome Number

http://leetcode.com/onlinejudge#question_9

Determine whether an integer is a palindrome. Do this without extra space.
*/

//====================================================================
// version 1, use iteration
// 300 milli secs pass large judge
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<10) return true;
        int first = x%10, last = x, len = 0;
        while(last>=10) {last/=10; ++len;}
        
        while(x!=0) {
            int l=0; // l is used for counting
            first = x%10, last = x; // get first & last digit
            while(l<len) {last/=10; ++l;}
            
            if(first != last) return false;
            
            while(l>0) {last*=10;--l;}
            x -= last; // remove last digit
            x /= 10; // remove first digit
            len-=2; // update len
        }
        
        return true;
    }
};


//====================================================================
// version 2, use recursive and without variables
// 340 milli secs pass large judge
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        return IsPalindrome(&x, x);
    }
    
    bool IsPalindrome(int* data, int min) { // min is the templary parameter to store data
        if(min == 0) return true;
        // (*data)%10 is the last digit if data, min%10 is the first digit
        if(IsPalindrome(data, min/10) && ((*data)%10 == (min%10))) {
            (*data) /= 10; // recursivly reduce size of data
            return true;
        }
        return false;
    }
};

