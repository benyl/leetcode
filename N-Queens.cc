/*
N-Queens

http://leetcode.com/onlinejudge#question_51

The n-queens puzzle is the problem of placing n queens on an n*n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

=======================================================================

N-Queens II

http://leetcode.com/onlinejudge#question_52

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        return solveNQueens(0, board);
    }
    
    vector<vector<string> > solveNQueens(int n, vector<string> &board) {
        vector<vector<string> > result;
        int x = board.size();
        if(n==x) {
            for(int i=0;i<x;i++)
            for(int j=0;j<x;j++)
                board[i][j] = (board[i][j]=='Q')?'Q':'.';
            result.push_back(board);
            return result;
        }
                
        for(int i=0; i<x; i++) {
            if(board[n][i] == '.') {
                vector<string> newboard(board);
                for(int j=0; j<x; j++) {
                    newboard[j][i] = '*';
                    newboard[n][j] = '*';
                    if(n+j< x && i+j< x) newboard[n+j][i+j] = '*';
                    if(n+j< x && i-j>=0) newboard[n+j][i-j] = '*';
                    if(n-j>=0 && i+j< x) newboard[n-j][i+j] = '*';
                    if(n-j>=0 && i-j>=0) newboard[n-j][i-j] = '*';
                }
                newboard[n][i] = 'Q';
                vector<vector<string> > re = solveNQueens(n+1, newboard);
                for(int j=0; j<re.size(); j++)
                    result.push_back(re[j]);
            }
        }
        
        return result;
    }
    
    int totalNQueens(int n, int row=0, int ld=0, int rd=0) {
        if(row==pow(2.0,n)-1) return 1;
        
        int sum = 0;
        for(int i=0;i<n;i++)
            if(~(row | ld | rd) & (1<<i))
                sum += totalNQueens(n, row|(1<<i), 
                        (ld|(1<<i))<<1, (rd|(1<<i))>>1);
        
        return sum;
    }
};