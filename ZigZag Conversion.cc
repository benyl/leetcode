/*
ZigZag Conversion

http://leetcode.com/onlinejudge#question_6

The string "PAYPALISHIRING" is written in a zigzag pattern on a given 
number of rows like this: (you may want to display this pattern in a 
fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given
a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows==1) return s;
        vector<string> rows(nRows, string(""));
        
        for(int i=0; i<s.size(); i++) {
            int index = i % (nRows*2-2);
            if(index>=nRows) index = nRows*2-2-index;
            rows[index] += s[i];
        }
        string result = "";
        for(int i=0; i<nRows; i++)
            result+=rows[i];
        return result;
    }
};