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

// ======================================================================
// 64 milli secs pass large data

class Solution {
public:
    string minWindow(string S, string T) {
        // use a dynamic window to search thru the string
        int min_start=-1, min_end=S.size();
        int start=0, end=-1;
        
        int count[256], found[256]; // arrays to record characters
        int count_uni = 0; // number of unique characters in T
        int match_uni = 0; // number of unique characters match in S
        
        for(int i=0; i<256; ++i) // initialize arrays
            { count[i]=0;found[i]=0; }
            
        for(int i=0; i<T.size(); ++i) { // count characters in T
            if(count[T[i]] == 0) ++count_uni;
            ++count[T[i]];
        }
        
        while(end!=S.size()) {
            if(match_uni < count_uni) {
                ++end; // extend the window if not enough char match
                if(count[S[end]] != 0) { // only consider the char found in T
                    ++found[S[end]];
                    if(found[S[end]] == count[S[end]]) { // if the window contain enough char in T
                        ++match_uni;
                        if(match_uni == count_uni) // check unique character matching
                            if((end-start) < (min_end - min_start))
                                { min_end = end; min_start = start; }  // remember the minimum window
                    }
                }
            } else {
                if(count[S[start]] != 0) { // only consider the char found in T
                    if(found[S[start]] == count[S[start]]) {  // if the window contain enough char in T
                        if(match_uni == count_uni) // check unique character matching
                            if((end-start) < (min_end - min_start))
                                { min_end = end; min_start = start; } // remember the minimum window
                        --match_uni;
                    }
                    --found[S[start]];
                }
                ++start; // reduce the window if enough char match
            }
        }
        
        if(min_start == -1) return ""; // return "" if no match window found
        else return S.substr(min_start, min_end-min_start+1);
    }
};
