/*
Palindrome Partitioning

http://leetcode.com/onlinejudge#question_131

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

=======================================================================

Palindrome Partitioning II

http://leetcode.com/onlinejudge#question_132

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

//=======================================================================
// Palindrome Partitioning
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        if(s.size() == 1) return true;
        
        for(int i=0; i<s.size()/2; ++i)
            if(s[i] != s[s.size()-1-i])
                return false;
        return true;
    }

    vector<vector<string> > partition(string s) {
        // use dynamic programming
        // if s is Palindrome, push to answer
        // for i = 1 to s.size-1
            // if s[:i] is Palindrome
            // get subresult = partition(s[i:])
            // for sub in subresult:
                // result += [s[:i] + sub]
                
        vector<vector<string> > answer;
        
        if(s.size() == 0)
            return answer;
        
        if(isPalindrome(s))
            answer.push_back(vector<string>(1,s));
        
        if(s.size() == 1)
            return answer;
        
        for(int i=1; i<s.size(); ++i) {
            string s1 = s.substr(0, i); 
            string s2 = s.substr(i, s.size()-i);
            
            if(!isPalindrome(s1))
                continue;
                
            vector<vector<string> > sub_answer = partition(s2);
            
            for(int j=0; j<sub_answer.size(); ++j) {
                sub_answer[j].insert(sub_answer[j].begin(), s1);
                answer.push_back(sub_answer[j]);
            }
        }
        
        return answer;
    }
};


//=======================================================================
// Palindrome Partitioning II
// version 1, Time Limit Exceeded
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        if(s.size() == 1) return true;
        
        for(int i=0; i<s.size()/2; ++i)
            if(s[i] != s[s.size()-1-i])
                return false;
        return true;
    }

    int minCut(string s) {
        // use dynamic programming
        // if s is Palindrome, push to answer
        // use a (nXn) matrix to store mincut[i,len]
            // for i=0 to s.size-1: mincut[i,1] = 0
            // for len = 2 to s.size:
                // for i=0 to s.size-len: 
                    // if s.sub(i, len) is Palindrome: mincut[i,len] = 0
                    // else mincut[i,len] = min(mincut[i,j-i] + mincut[j,len-j]) + 1
            // return dp[0, s.size]
                
        if(isPalindrome(s))
            return 0;
            
        vector<vector<int> > dp; // use to store minCut[i, len]
        
        // initial minCut (minCut[i, len] means the result of minCut(s.sub(i, len)))
        for(int i=0; i<s.size(); ++i)
            dp.push_back(vector<int>(s.size()-i+1, 0));
        
        for(int len=2; len<=s.size(); ++len) {
            for(int i=0; i<=s.size()-len; ++i) {
                if((s[i] == s[i+len-1]) && (dp[i+1][len-2]==0)) {
                    dp[i][len] = 0;
                } else {
                    dp[i][len] = len-1;
                    for(int l=1; l<len; ++l) {
                        int cut = dp[i][l] + dp[i+l][len-l] + 1;
                        dp[i][len] = (dp[i][len] < cut) ? dp[i][len] : cut;
                        if(dp[i][len] < 2) break;
                    }
                }
            } // end of: for(int i=0; i<=s.size-len; ++i)
        } // end of: for(int len=2; len<s.size; ++len)
        
        return dp[0][s.size()];
    }
};


//=======================================================================
// Palindrome Partitioning II
// solution 2
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        int dp[len]; // use to store minCut of s[i:]
        bool palidrome[len][len]; // true if s[i:j] is palidrome
        
        // init dp with maximum cut (len-1-i)
        for(int i=0; i<=len; ++i)
            dp[i] = len-i-1;
        for(int i=0; i<len; ++i)
        for(int j=0; j<len; ++j)
            palidrome[i][j] = false;
        
        for(int i=len-2; i>=0; --i)
        for(int j=i; j<len; ++j)
            if((s[i] == s[j]) && (j-i<2 || palidrome[i+1][j-1])) {
                palidrome[i][j] = true;
                dp[i] = min(dp[i], dp[j+1]+1);
            }
        
        return dp[0];
    }
};

//=======================================================================
// Palindrome Partitioning II
// version 3
class Solution {
public:
    int minCut(string s) {
        if (s.size() < 2)
            return 0;
        int len = s.size();
        int minSegs[len+1]; // store the min cut of s[:i]
        int dp[len+2]; //palidrome?
        
        minSegs[0] = 0; minSegs[1] = 1;
        dp[0] = 0; dp[1] = 1; dp[2] = -1;
        
        for (int i=1; i<s.size(); i++) {
            minSegs[i+1] = minSegs[i] + 1;
            int n = 0; // palidrome numbers
            for (int j=0; dp[j] != -1; j++) {
                int left = i-1-dp[j];
                if (left>=0 && s[left]==s[i]) {
                    dp[n++] = dp[j] + 2;
                    minSegs[i+1] = min(minSegs[i+1], minSegs[left] + 1);
                }
            }
            dp[n++] = 0; dp[n++] = 1; dp[n] = -1;
        }
        return minSegs[s.size()] - 1;
    }
};