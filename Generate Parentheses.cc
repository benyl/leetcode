/*
Generate Parentheses

http://leetcode.com/onlinejudge#question_22

Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

// =============================================================
// recursive version

class Solution {
public:
    vector<string> result;
    string temp;
    int num;
    
    vector<string> generateParenthesis(int n) {
        result.clear();
        num = n;
        temp = string(num * 2, ' ');
        generate(0, 0);
        
        return result;
    }
    
    void generate(int left, int right) { // used left and right Parenthesis
        if(left==num && right==num) {
            result.push_back(temp);
        } else {
            if(left < num) { // use '(' if available
                temp[left+right] = '(';
                generate(left+1, right); // recursive
            }
            if(right < left) { // use ')' if available
                temp[left+right] = ')';
                generate(left, right+1); // recursive
            }
        }
    }
};


// =============================================================
// back tracking solution

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n<1) return vector<string>();
        
        int left=0, right=0; // used left and right Parenthesis
        
        vector<string> result;
        string gen(2*n, ' ');
        
        while(true)
            if(left<n) { // use '(' if available
                gen[left + right]='(';
                ++left;
            } else if(right<n) { // no '(' , use ')'
                gen[left + right]=')';
                ++right;
            } else { // used up Parenthesis
                result.push_back(gen);
                
                while(left+right>0) { // begin back tracking
                    if(gen[left+right-1]==')') --right; // remove Parenthesis
                    else --left;
                    
                    if(gen[left+right]=='(' && left!=right) // find the optional '('
                        break;
                }
                if(left+right==0) break; // end of back tracking: "()()()..."
                gen[left+right] = ')'; // flip the optional '(' to ')'
                ++right;
            }
        return result;
    }
};