/*
Maximal Rectangle

http://leetcode.com/onlinejudge#question_85

Given a 2D binary matrix filled with 0's and 1's, 
find the largest rectangle containing all ones and return its area.
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty())
            return 0;

        int m = matrix.size(), n = matrix[0].size();
        
        // use idea of suspension lines and dynamic programming
        vector<int> H(n, 0); // height of the highest rectangle on [i, j]
        vector<int> L(n, 0); // left  bound of current highest rectangle on [i, j]
        vector<int> R(n, n); // right bound of current highest rectangle on [i, j]
        
        int maxret = 0;      // area of largest rectangle
        
        for (int i = 0; i < m; ++i) { // search from top to buttom for all valid rectangles
            int left = 0, right = n;  // used to remember the current left/right bound of '1's
            
            for (int j = 0; j < n; ++j) {    // search from left to right to record left bound
                if (matrix[i][j] == '1') {
                    L[j] = max(L[j], left);  // keep the higher but narrower block
                    ++H[j];                  // if [i,j] = '1', add height and left bound
                } else {
                    left = j+1;                    // left bound of rectangle should be the right '1'
                    H[j] = 0; L[j] = 0; R[j] = n;  // if [i,j] = '0', reset height and left/right bound
                }
            }
            for (int j = n-1; j >= 0; --j) { // search from right to left to record right bound
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], right);                 // keep the higher but narrower block
                    maxret = max(maxret, H[j]*(R[j]-L[j]));  // calculate the area of each block, keep the max
                } else {
                    right = j;  // right bound of rectangle should be this '0'
                }
            }
        }

        return maxret;
    }
};


// version 2, use the solution of maximal rectangle in histogram
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int nSize = matrix.size();
        if(nSize == 0){
            return 0;
        }
        vector<vector<char> > heights;
        heights.push_back(vector<char>(matrix[0].size(), 0));
        int max = 0;
        for(int i = 0; i< nSize; ++i){
            vector<char> row;
            for(int j = 0; j< matrix[i].size(); ++j) {
                if(matrix[i][j] == '1') {
                    row.push_back(heights[i][j] + 1);
                } else {
                    row.push_back(0);
                }
            }
            heights.push_back(row);
        }
        for(int i = 1; i <= nSize; ++i){
            int temp = largestRectangleArea(heights[i]);
            max = max > temp? max: temp;
        }
        return max;
    }
    int largestRectangleArea(vector<char> &height) {
        int nSize = height.size();  
        int l[nSize + 1];//left bar position  
        int h[nSize + 1];//height of the left bar  
        l[0] = h[0] = 0;  
        int cur_h = 0;  
        int max = 0;  
        int top = 0;  
        for(int i = 0 ; i<= nSize; ++i){  
            cur_h = i==nSize? 0: height[i];  
            int j = i;  
            for(; h[top] > cur_h; j = l[top--]){  
                int temp = (i - l[top]) * h[top];  
                if(temp > max){  
                    max = temp;  
                }  
            }  
            if(cur_h > h[top]){  
                h[++top] = cur_h;  
                l[top] = j;  
            }  
        }  
        return max;  
    }  
};