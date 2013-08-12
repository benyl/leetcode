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
        
        vector<string> row(nRows, string(""));
        int index = 0;
        bool flag = true;
        for(int i=0; i<s.size(); ++i) {
            row[index] += s[i];
            
            index += (flag) ? 1 : -1;
            if(index==0) flag=true;
            if(index==nRows-1) flag=false;
        }
        
        string result = "";
        for(int i=0; i<nRows; ++i)
            result += row[i];
            
        return result;
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
        if(nRows==1) return s;
        
        string result = "";
        for(int i=0; i<nRows; ++i) {
            int index=i;
            int step = (nRows-1) * 2;
            int in_step = (nRows-1-i) * 2;
            while(index < s.size()) {
                result += s[index];
                if(i!=0 && i!=nRows-1 && (index+in_step<s.size()))
                    result += s[index + in_step];
                index += step;
            }
        }
        
        return result;
    }
};