/*
Valid Sudoku

http://leetcode.com/onlinejudge#question_36

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

// ==================================================================

Sudoku Solver

http://leetcode.com/onlinejudge#question_37

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

*/

// ==================================================================
// Valid Sudoku
// use bit mapping, be careful about operator precedence
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
        return true; // return true if no conflict found
    }
};

// ==================================================================
// Sudoku Solver
// use bit mapping with depth first back tracking method
// be careful about operator precedence
// 20 milli secs pass Judge Large

class Solution {
public:
    bool solveSudoku(vector<vector<char> > &board) {
        // use bit map to count the apperance of numbers
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<vector<int> > box(3, vector<int>(3, 0));
        // check valid sudoku
        for(int i=0; i<9; ++i)
        for(int j=0; j<9; ++j)
            if(board[i][j] != '.') {
                int digit = board[i][j] - '1'; // convert to 0~8
                // check if there is duplicate choice
                if((row[i] & (1<<digit)) != 0) return false;
                if((col[j] & (1<<digit)) != 0) return false;
                if((box[i/3][j/3] & (1<<digit)) != 0) return false;
                // mark the bit for the appeared number
                row[i] |= (1<<digit);
                col[j] |= (1<<digit);
                box[i/3][j/3] |= (1<<digit);
            }
        // find candidate with minimum options
        int min_i, min_j, min_opt = 65535;
        for(int i=0; i<9; ++i)
        for(int j=0; j<9; ++j)
            if(board[i][j] == '.') {
                int options = row[i] | col[j] | box[i/3][j/3];
                int opt_num = 0;
                // find the bit that is available
                for(int digit=0; digit<9; ++digit)
                    if((options & (1<<digit)) == 0)
                        ++opt_num;
                // check if there is no option
                if(opt_num == 0) return false;
                if(opt_num < min_opt) {
                    min_i = i; min_j = j; min_opt = opt_num;
                }
            }
        // no candidate found, sudoku is already solved
    	if(min_opt == 65535) return true;
        // use back tracking to test all available choices
        int options = row[min_i] | col[min_j] | box[min_i/3][min_j/3];
        for(int digit=0; digit<9; ++digit)
            if((options & (1<<digit)) == 0) {
                board[min_i][min_j] = '1' + digit;
                if(solveSudoku(board)) return true;
            }
        // if no result, do back tracking
        board[min_i][min_j] = '.';
        return false;
    }
};


// ==================================================================
// code for testing in local
void main(){
	Solution sol;
	string input[9] = {".19748632","783652419","426139875","357986241","264317598","198524367","975863124","832491756","641275983"};
	vector<vector<char> > board(9, vector<char>(9, '.'));

	for(int i=0; i<9; ++i)
	for(int j=0; j<9; ++j)
		board[i][j] = input[i][j];

	cout << sol.solveSudoku(board) << endl;
	getchar();
}