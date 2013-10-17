/*
Palindrome Number

http://leetcode.com/onlinejudge#question_9

Determine whether an integer is a palindrome. Do this without extra space.
*/

//====================================================================
// version 1, use iteration
// 308 milli secs pass large judge
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long org=x, rev=0;
        while(x!=0){
            rev*=10;
            rev+=x%10;
            x/=10;
        }
        return org==rev;
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
