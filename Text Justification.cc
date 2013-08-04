/*
Text Justification

http://leetcode.com/onlinejudge#question_68

Given an array of words and a length L, format the text such that each 
line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many 
words as you can in each line. Pad extra spaces ' ' when necessary so 
that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line do not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots 
on the right.

For the last line of text, it should be left justified and no extra space 
is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.


Corner Cases:
A line other than the last line might contain only one word. 
What should you do in this case?

In this case, that line should be left-justified.
*/

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        if(words.size() == 0) return words;
        
        vector<int> point; // break point of words
        
        point.push_back(words[0].size());
        for(int i=1; i<words.size(); i++) {
            if(point[0] + words[i].size() + 1 > L) {
                point.push_back(i);
                point[0] = words[i].size();
            } else {
                point[0] += 1 + words[i].size();
            }
        }
        point[0] = 0;
        point.push_back(words.size());
        
        vector<string> result;
        for(int i=0; i<point.size()-1; i++) {
            int len = L; // space needed
            for(int j=point[i]; j<point[i+1]; j++)
                len -= words[j].size();
            
            string just = words[point[i]];
            for(int j=point[i]+1; j<point[i+1]; j++) {
                if(i!=point.size()-2) {
                    just += string(len / (point[i+1]-point[i]-1), ' ');
                    just += string(len % (point[i+1]-point[i]-1) >= (j-point[i]), ' ');
                    just += words[j];
                } else {
                    just += " " + words[j];
                }
            }
            if(just.size()<L) just += string(L-just.size(), ' ');
            result.push_back(just);
        }
        
        return result;
    }
};

int main()
{
    string input[] = {"What","must","be","shall","be."};
    vector<string> words(input, end(input));

    Solution sol;
    words = sol.fullJustify(words, 12);
    for(int i=0; i<words.size(); i++)
		cout << words[i] << endl;
    getchar();

    return 0;
}


//============================================

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        if(words.size()==0) 
            return vector<string>();
        
        vector<string> result;
        int start=0, end=0, length=0;
        for(int i=0; i<=words.size(); ++i) {
            if(i==words.size() || length+words[i].size()>=L) {
                if(i==words.size() || cand.size()==1) {
                    for(int j=1; j<cand.size(); ++j)
                        cand[0] += cand[j];
                    cand[0] += string(L-length, ' ');
                    result.push_back(cand[0]);
                } else if(cand.size() > 1) {
                    int index = 0;
                    while(length<L) {
                        cand[index++] += ' ';
                        index %= cand.size()-1;
                        ++length;
                    }
                    for(int j=1; j<cand.size(); ++j)
                        cand[0] += cand[j];
                    result.push_back(cand[0]);
                }
                
                cand.clear();
                length = 0;
            }
            if(i!=words.size()) {
                length += words[i].size();
                cand.push_back(words[i]);
                if(cand.size() != 1) {
                    length += 1;
                    cand.back() = string(" ") + cand.back();
                }
                
            }
        } 
        return result;
    }
};
