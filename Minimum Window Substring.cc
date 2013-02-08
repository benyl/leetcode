/*
Minimum Window Substring

http://leetcode.com/onlinejudge#question_76

Given a string S and a string T, find the minimum window in S which 
will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, 
return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will 
always be only one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string S, string T) {
        if(T.size()==0) return "";
        
        vector<int> require(256, 0);
        vector<int> found(256, 0);
        int unique = 0;
        int match = 0;
        
        for(int i=0; i<T.size(); i++) {
            if(require[T[i]] == 0) unique++;
            require[T[i]] ++;
        }
        
        int start=0, end=0;
        string window = S;
        
        while(start<=end) {
            if(match < unique) {
                if(require[S[end]]!=0) {
                    found[S[end]]++;
                    if(found[S[end]]==require[S[end]]) match++;
                }

                end++;
                if(end>S.size()) break;

                int temp = end-start, temp2 = window.size();
                if(match==unique && (end-start)<window.size())
                    window = S.substr(start, end-start);
            } else {
                if(require[S[start]]!=0) {
                    if(found[S[start]]==require[S[start]]) match--;
                    found[S[start]] --;
                }
                
                start++;
                if(start>S.size()) break;

                int temp = end-start, temp2 = window.size();
                if(match==unique && (end-start)<window.size())
                    window = S.substr(start, end-start);
            }
        }
        
        if(window == S && start==0) return "";
        else  return window;
    }
};