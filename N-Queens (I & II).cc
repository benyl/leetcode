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


// =========================================================
// N-Queens I: use bitmap and depth-first backtracking algorithm
// 20 milli secs pass large judge
// note: !!! add parentheses to bit manipulation due to low operator precedence !!!

class Solution {
public:
    vector<vector<string> > result;
    vector<string> board;

    vector<vector<string> > solveNQueens(int n) {
        result.clear();
        if(n<1) return result;
        
        board = vector<string>(n, string(n, '.'));
        solveNQueens(n, 0, 0, 0, 0);
        return result;
    }

    void solveNQueens(int n, int row, int ct, int ld, int rd) {
        if(row==n) {
            result.push_back(board); // if all n queens placed, put to result
            return;
        }
        
        int forbid = (ct | ld | rd); // forbid places represented by bit map
        for(int i=0; i<n; ++i) {
            int mask = (1<<i); 
            if((forbid & mask)!=0) continue;  // find the availale place of bit '0'
            board[row][i] = 'Q'; // place the queen
            int c = (ct | mask);      // mark for center line checking
            int l = (ld | mask) << 1; // mark for left-diagonal checking, do left shift
            int r = (rd | mask) >> 1; // mark for right-diagonal checking, do right shift
            solveNQueens(n, row+1, c, l, r);
            board[row][i] = '.'; // recover for back-tracking
        }
    }
};

// =========================================================
// N-Queens II: use bitmap
// 184 milli secs pass large judge
// note: !!! add parentheses to bit manipulation due to low operator precedence !!!

class Solution {
public:
    int totalNQueens(int n, int col=0, int ld=0, int rd=0) {
        if(col==(1<<n)-1) return 1; // when all n queens are placed
        
        int sum = 0;
        for(int i=0;i<n;++i)
            if(~(col | ld | rd) & (1<<i)) // use 3 bitmaps to represented available places
                sum += totalNQueens(n, col|(1<<i), (ld|(1<<i))<<1, (rd|(1<<i))>>1);
        return sum;
    }
};