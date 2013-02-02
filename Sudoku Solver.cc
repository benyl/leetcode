/*
Sudoku Solver

http://leetcode.com/onlinejudge#question_37

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

class Solution {
public:
    bool solveSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > row(9, vector<bool>(9, true));
        vector<vector<bool> > col(9, vector<bool>(9, true));
        vector<vector<bool> > box(9, vector<bool>(9, true));
        
        //Each row must have the numbers 1-9 occuring just once.
        for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(board[i][j]!='.')
                if(!row[i][board[i][j]-'1']) return false;
                else row[i][board[i][j]-'1'] = false;
        
        //Each column must have the numbers 1-9 occuring just once.
        for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(board[j][i]!='.')
                if(!col[i][board[j][i]-'1']) return false;
                else col[i][board[j][i]-'1'] = false;
        
        //And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
        for(int k=0; k<9; k++)
            for(int i= (k/3*3); i< (k/3*3)+3; i++) // 6 7 8
            for(int j= (k%3*3); j< (k%3*3)+3; j++) // 3 4 5
                if(board[i][j]!='.')               // 0 1 2
                    if(!box[k][board[i][j]-'1']) return false;
                    else box[k][board[i][j]-'1'] = false;
        
        // find the space with minimum candidates
        int min=10, x=0, y=0;
        vector<bool> candidate;
        for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(board[i][j]=='.') {
                vector<bool> cand(9, true);
                int b = i/3*3 + j/3, num = 0;
                for(int k=0; k<9; k++) {
                    cand[k] = row[i][k] && col[j][k] && box[b][k];
                    if(cand[k]) num++;
                    }
                if(num==0) return false;
                else if(num < min) {min=num; x=i; y=j; candidate=cand;}
            }
        
        if(min==10) return true; // if no space
        
        for(int k=0; k<9; k++) //backtracking
            if(candidate[k]) {
                board[x][y] = '1' + k;
                if(solveSudoku(board)) return true;
                else board[x][y]='.';
            }
        return false; // if all candidate is wrong, return false;
    }
};