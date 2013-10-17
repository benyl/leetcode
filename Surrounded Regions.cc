/*
Surrounded Regions

http://leetcode.com/onlinejudge#stkstion_130

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if(board.size()==0 || board[0].size()==0) return;
        
        int m = board.size();
        int n = board[0].size();
        stack<pair<int, int> > stk;
        
        // mark all edge 'O' to '+'
        for(int i=0; i<m; ++i) {
            if(board[i][0]=='O') { board[i][0] = '+'; stk.push(make_pair(i,0)); }
            if(board[i][n-1]=='O') { board[i][n-1] = '+'; stk.push(make_pair(i,n-1)); }
        }
        for(int j=0; j<n; ++j) {
            if(board[0][j]=='O') { board[0][j] = '+'; stk.push(make_pair(0,j)); }
            if(board[m-1][j]=='O') { board[m-1][j] = '+'; stk.push(make_pair(m-1,j)); }
        }
        
        // mark '+' surrounded 'O' to '+'
        while(stk.size() != 0) {
            int i = stk.top().first;
            int j = stk.top().second;
            stk.pop();
            
            if(i<m-1 && board[i+1][j]=='O') { board[i+1][j] = '+'; stk.push(make_pair(i+1,j)); }
            if(i>0 && board[i-1][j]=='O') { board[i-1][j] = '+'; stk.push(make_pair(i-1,j)); }
            if(j<n-1 && board[i][j+1]=='O') { board[i][j+1] = '+'; stk.push(make_pair(i,j+1)); }
            if(j>0 && board[i][j-1]=='O') { board[i][j-1] = '+'; stk.push(make_pair(i,j-1)); }
        }
        
        // mark all other 'O' to 'X' and mark all '+' back to 'O'
        for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            board[i][j] = (board[i][j]=='+') ? 'O' : 'X';
    }
};