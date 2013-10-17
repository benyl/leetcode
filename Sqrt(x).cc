/*
Sqrt(x)

http://leetcode.com/onlinejudge#question_69

Implement int sqrt(int x).

Compute and return the square root of x.
*/

//======================================================================= 
// version 1, use binary search
class Solution {
public:
    const int MAX_ROOT = std::sqrt(INT_MAX); // max root of integer
    
    int sqrt(int x) {
        // limit the upper bound of root, or else time limit exceed
        int min = 0;
        int max = (x < MAX_ROOT) ? x : MAX_ROOT;
        
        // use binary search
        while(min <= max){
            int mid = (min+max)/2;
            int sqr = mid * mid;
            if(sqr == x) return mid;
            else if(sqr < x) 
                min = mid+1;
            else 
                max = mid-1;
        }
        
        return (min+max)/2;
    }
};

//======================================================================= 
// version 2, use bit manipulation
class Solution {
public:
    int sqrt(int x) {
        if(x<1) return 0;
        long long root;
        int bits = 0;
        
        for(root=1; root*root<x; root<<=1)
            ++bits;
        
        for(root=0; bits>=0; --bits) {
            long long tmp = root | (1<<bits);
            long long sqr = tmp * tmp;
            if(sqr == x) return tmp;
            if(sqr < x) root = tmp;
        }
        
        return root;
    }
};

//======================================================================= 
// version 3, use Newton's method for root approximation
// https://en.wikipedia.org/wiki/Newton's_method
// Newton's method: t1 = t0 - f(t0) / f'(t0)
// f(t0) = t0 ^ 2 - x
// f'(t0) = 2 * t0
class Solution {
public:
    const float EPS = 0.0001; // precision for aproximation
    
    int sqrt(int x) {
        if(x <= 1) return x;
        double root = x;
        while(true) {
            double oldroot = root;
            // use Newton's method: t1 = t0 - f(t0) / f'(t0)
            // be careful about implicit integer casting
            root = root / 2.0 + x / 2.0 / root; 
            
            // break if we reach a precision 
            if(abs(oldroot - root) < EPS) break;
        }
        return floor(root);
    }
};
