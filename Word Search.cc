/*
Word Search

http://leetcode.com/onlinejudge#question_79

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word, 
               int x = -1, int y = -1, int pos=0) {
        if(word.size() == pos) return true;
        if(board.size() == 0) return false;
        
        int m = board.size();
        int n = board[0].size();
        
        if(x==-1 & y==-1) {
            for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(board[i][j]==word[pos]){
                    board[i][j] = '\0'; // set to '\0' to avoid duplicate search
                    if(exist(board, word, i, j, pos+1)) return true;
                    board[i][j] = word[pos]; // restore
                }
            }
        } else {
            if(x>0 && board[x-1][y] == word[pos]){                
                board[x-1][y] = '\0';
                if(exist(board, word, x-1, y, pos+1)) return true;
                board[x-1][y] = word[pos];
            }
            if(x<m-1 && board[x+1][y] == word[pos]){                
                board[x+1][y] = '\0';
                if(exist(board, word, x+1, y, pos+1)) return true;
                board[x+1][y] = word[pos];
            }
            if(y>0 && board[x][y-1] == word[pos]){                
                board[x][y-1] = '\0';
                if(exist(board, word, x, y-1, pos+1)) return true;
                board[x][y-1] = word[pos];
            }
            if(y<n-1 && board[x][y+1] == word[pos]){                
                board[x][y+1] = '\0';
                if(exist(board, word, x, y+1, pos+1)) return true;
                board[x][y+1] = word[pos];
            }
        } // end of: if(x==-1 & y==-1)
        
        return false;
    }
};