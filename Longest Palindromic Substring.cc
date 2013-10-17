/*
Longest Palindromic Substring

http://leetcode.com/onlinejudge#question_5

Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.

*/

// =========================================================
// recursive solution
// 284 milli secs pass large test
// time complexity o(n^2), space complexity (n)

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        string sub = longestPalindrome(s.substr(0, s.size()-1));
        
        if(s.size()-sub.size()>=2 && 
            isPalindrome(s.substr(s.size()-sub.size()-2)))
            return s.substr(s.size()-sub.size()-2);
            
        if(isPalindrome(s.substr(s.size()-sub.size()-1)))
            return s.substr(s.size()-sub.size()-1);
        
        return sub;
    }
    bool isPalindrome(string s) {
        for(int i=0; i<s.size()/2; i++)
            if(s[i] != s[s.size()-i-1]) return false;
        return true;
    }
};

// =========================================================
// iterative solution
// 104 milli secs pass large test
// time complexity o(n^2), space complexity (1)

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        int len = 1, id = 0;

        for(int i=1; i<s.size(); ++i) {
            bool pal = false;
            
            if(len<i && s[i] == s[i-len-1]) {
                pal = true;
                for(int j=0; j<len/2; ++j)
                    if(s[i-j-1] != s[i-len+j]) 
                        { pal = false; break; }
                if(pal) { len += 2; id = i; }
            }
            
            if(!pal && s[i] == s[i-len]) {
                pal = true;
                for(int j=0; j<len/2; ++j)
                    if(s[i-j-1] != s[i-len+j+1]) 
                        { pal = false; break; }
                if(pal) { len += 1; id = i; }
            }
        }
        
        return s.substr(id-len+1, len);
    }
};

// =========================================================
// DP solution, Manacher's Algorithm
// http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
// http://www.felix021.com/blog/read.php?2040
//
// 24 milli secs pass large test
// time complexity o(n), space complexity (n)

class Solution {
public:
    string longestPalindrome(string s) {
        // Transform S into T
        string T(s.size()*2+3, '#'); // T = " # S[1] # S[2]... # S[n] # "
        T.front() = '^'; T.back() = '$';  // add to two end to simplify algorithm
        for(int i=0; i<s.size(); ++i) T[i*2+2] = s[i];

        int *P = new int[T.size()]; // palindrome radius that centered at T[i]
        int C = 0, R = 0; // nearest palidromic center and radius
        int maxC = 0, maxR = 0; // the longest palidrome center and radius

        for (int i = 1; i < T.size()-1; i++) {
            int i_mirror = 2*C-i; // equals to i' = C - (i - C)
            
            // try to use i_mirror palidromic length as i's base length
            P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
            
            // Attempt to expand palindrome centered at i
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) ++P[i];
            
            // remember the longest palidrome center and radius
            if( maxR < P[i] ) { maxC = i; maxR = P[i]; }

            // If palindrome centered at i expand past R, update center
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        delete[] P;
        return s.substr((maxC - 1 - maxR)/2, maxR);
    }
};