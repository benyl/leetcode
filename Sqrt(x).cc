/*
Sqrt(x)

http://leetcode.com/onlinejudge#question_69

Implement int sqrt(int x).

Compute and return the square root of x.
*/

#define MAX_ROOT 46340

class Solution {
public:
    int sqrt(int x) {
        if(x<2) return x;
		if(MAX_ROOT * MAX_ROOT < x) return MAX_ROOT;
        int min = 0;
        int max = x/2;
		max = (max<MAX_ROOT) ? max:MAX_ROOT;
        while(min < max){
            int mid = (min+max)/2;
            
            if(mid * mid>x)
                max = mid-1;
            else if ((mid+1)*(mid+1) <= x)
                min = mid+1;
            else return mid;
        }
        return (min+max)/2;
    }
};