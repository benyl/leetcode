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


// simulation method
class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows==1) return s;
        
        vector<string> seg(nRows);
        for(int i=0, row=0, step=1; i<s.size(); ++i, row+=step) {
            seg[row] += s[i];
            if(row == 0) step = 1;
            if(row == nRows-1) step = -1;
        }
        
        for(int row=1; row<nRows; ++row)
            seg[0] += seg[row];
            
        return seg[0];
    }
};


// calculation row index by char index
// example: nRows = 5
// 0       8
// 1     7 9
// 2   6   10
// 3 5     11
// 4       12

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows==1) return s; // corner case, step=2(nRows-1)=0 when nRows=1
        
        string result = "";
        for(int i=0; i<nRows; ++i)
            for(int j=i; j<s.size(); j+=2*(nRows-1)) { // loop step = 2*(nRows-1)
                result += s[j];
                if(i!=0 && i!=nRows-1 && j+2*(nRows-1-i)<s.size())
                    result += s[j+2*(nRows-1-i)]; //  internal step = 2*(nRows-1-i)
            }
        
        return result;
    }
};