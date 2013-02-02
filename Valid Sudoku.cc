/*
Valid Sudoku

http://leetcode.com/onlinejudge#question_36

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<bool> occur(9, false);
        
        //Each row must have the numbers 1-9 occuring just once.
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) occur[j]=false;
                
            for(int j=0; j<9; j++)
                if(board[i][j]!='.') {
                    int num = board[i][j]-'1';
                    if(occur[num]) return false;
                    else occur[num] = true;
                }
        }
        
        //Each column must have the numbers 1-9 occuring just once.
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) occur[j]=false;
                
            for(int j=0; j<9; j++)
                if(board[j][i]!='.') {
                    int num = board[j][i]-'1';
                    if(occur[num]) return false;
                    else occur[num] = true;
                }
        }
        
        //And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
        for(int x=0; x<9; x+=3) {
        for(int y=0; y<9; y+=3) {
            for(int j=0; j<9; j++) occur[j]=false;
            
            for(int i=x; i<x+3; i++)
            for(int j=y; j<y+3; j++)
                if(board[i][j]!='.') {
                    int num = board[i][j]-'1';
                    if(occur[num]) return false;
                    else occur[num] = true;
                }
        }
        }
        
        return true;
    }
};