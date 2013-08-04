/*
Valid Sudoku

http://leetcode.com/onlinejudge#question_36

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/

// ==================================================================
// version 1, use bool vector
// 64 milli secs pass Judge Large 
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        //Each row must have the numbers 1-9 occuring just once.
        for(int i=0; i<9; i++) {
            vector<bool> occur(9, false);
                
            for(int j=0; j<9; j++)
                if(board[i][j]!='.') {
                    int num = board[i][j]-'1';
                    if(occur[num]) return false;
                    else occur[num] = true;
                }
        }
        
        //Each column must have the numbers 1-9 occuring just once.
        for(int i=0; i<9; i++) {
            vector<bool> occur(9, false);
                
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
            vector<bool> occur(9, false);
            
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

// ==================================================================
// version 2, use bit mapping
// be careful about operator precedence
// 56 milli secs pass Judge Large
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // use bit map to mark the apperance of numbers
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<vector<int> > box(3, vector<int>(3, 0));
        
        for(int i=0; i<9; ++i)
        for(int j=0; j<9; ++j)
            if(board[i][j] != '.') {
                int digit = board[i][j] - '1'; // convert to 0 ~ 8
                // check if there is duplicate choice
                if((row[i] & (1<<digit)) != 0) return false;
                if((col[j] & (1<<digit)) != 0) return false;
                if((box[i/3][j/3] & (1<<digit)) != 0) return false;
                // mark the bit for the appeared number
                row[i] |= (1<<digit);
                col[j] |= (1<<digit);
                box[i/3][j/3] |= (1<<digit);
            }
        // return true if no conflict found
        return true;
    }
};