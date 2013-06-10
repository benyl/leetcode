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
// time complexity O(n*2^n), space complexity O(2^n)
/*
1) find all possible palindrome in s that start with the first letter

    2.1) for each palindrome p, get the substring s1 of s that have the characters after p, so s = p + s1

    2.2) find all possible palindrome partition of s1 by calling partition(s1), add p to the begin of return and save to answers

3) return answers


*/

class Solution {
public:
    // function to find if s is palindrome
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        if(s.size() == 1) return true;
        
        for(int i=0; i<s.size()/2; ++i)
            if(s[i] != s[s.size()-1-i])
                return false;
        return true;
    }

    vector<vector<string> > partition(string s) {
        vector<vector<string> > answer;
        
        if(s.size() == 0)
            return answer;
        
        // if s is Palindrome, push to answer
        if(isPalindrome(s))
            answer.push_back(vector<string>(1,s));
        
        if(s.size() == 1)
            return answer;
        
        for(int i=1; i<s.size(); ++i) {
            string s1 = s.substr(0, i); 
            string s2 = s.substr(i, s.size()-i);
            
            if(isPalindrome(s1)) {
                // get sub_answers of partition(s[i:])
                vector<vector<string> > sub_answer = partition(s2);
                
                // add s1 to the begin of sub_answers
                for(int j=0; j<sub_answer.size(); ++j) {
                    sub_answer[j].insert(sub_answer[j].begin(), s1);
                    answer.push_back(sub_answer[j]);
                }
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
// Version 2, 120 milli secs for large judge
// time complexity O(n^2), space complexity O(n^2)
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        int dp[len]; // store minCut of s[i:]
        bool palidrome[len][len]; // store if s[i:j] is palidrome
        
        // init dp of mincut with maximum cut for s[i:] is (len-i-1)
        for(int i=0; i<=len; ++i)
            dp[i] = len-i-1;
        for(int i=0; i<len; ++i)
        for(int j=0; j<len; ++j)
            palidrome[i][j] = false;
        
        // start from end to head of string
        for(int i=len-2; i>=0; --i)
        for(int j=i; j<len; ++j)
            // only consider when s[i:j] is palidrome (s[i] == s[j] and s[i+1:j-1] is palidrome)
            // or else mincut(s[i:]) = mincut(s[i+1:]) + 1
            if((s[i] == s[j]) && (j-i<2 || palidrome[i+1][j-1])) {
                palidrome[i][j] = true;
                // mincut s[i:] is minimum of mincut(s[j:]) + 1 (that is, first cut at j)
                dp[i] = min(dp[i], dp[j+1]+1);
            }
        
        return dp[0];
    }
};

//=======================================================================
// Palindrome Partitioning II
// Version 3, 28 milli secs for large judge
// time complexity O(n^2), space complexity O(n)
class Solution {
public:
    int minCut(string s) {
        if (s.size() < 2)
            return 0;
        int len = s.size();
        // use two arrays for dyanmic programming
        int minSegs[len+1]; // store the min palidrome segments of s[:i]
        int palLen[len+2]; // store all lengths of palidrome that ends at s[i]
        
        // initialize the minSegs and possible lengths of palidrome for s[:1]
        minSegs[0] = 0; minSegs[1] = 1;
        palLen[0] = 0; palLen[1] = 1; palLen[2] = -1;
        
        for (int i=1; i<s.size(); i++) {
            // init mincut(s[:i+1]) = mincut(s[:i]) + 1
            minSegs[i+1] = minSegs[i] + 1;
            int n = 0; // numbers of palidrome that ends at s[i]
            // for all palidrome that ends at s[i-1], check if s[left:i] is palidrome
            for (int j=0; palLen[j] != -1; j++) {
                int left = i-1-palLen[j];
                // if s[left:i] is palidrome, add length of s[left:i] into array and update minSegs[i+1]
                if (left>=0 && s[left]==s[i]) {
                    palLen[n++] = palLen[j] + 2;
                    // first cut at left and s[left:i] is palidrome -> minSegs[i+1] = minSegs[left] + 1
                    minSegs[i+1] = min(minSegs[i+1], minSegs[left] + 1);
                    if(minSegs[i+1] == 1) break;
                }
            }
            // add lengths 0 and 1 to array of palidrome length for s[:i]
            palLen[n++] = 0; palLen[n++] = 1; palLen[n] = -1;
        }
        
        // minCut(s) = minSeg(s) - 1
        return minSegs[s.size()] - 1;
    }
};