/*
Largest Rectangle in Histogram

http://leetcode.com/onlinejudge#question_84

Given n non-negative integers representing the histogram's bar height where 
the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        vector<int> left  (height.size(), 0);
        vector<int> right (height.size(), height.size());
        int maxarea = 0;
        
        // from left to right, for each bar, find the left bound containing this bar
        for(int i=1; i<height.size(); i++) {
            left[i] = i;
            while(left[i]!=0 && height[left[i]-1]>=height[i]) {
                left[i] = left[left[i]-1];
            }
        }
        
        // from right to left, for each bar, find the right bound containing this bar
        for(int i=height.size()-2; i>=0; i--) {
            right[i] = i+1;
            while(right[i]!=height.size() && height[right[i]]>=height[i]) {
                right[i] = right[right[i]];
            }
        }
        
        // calculate area of each rectangle
        for(int i=0; i<height.size(); i++) {
            int area = (right[i] - left[i]) * height[i];
            maxarea = (area > maxarea) ? area : maxarea;
        }
        
        return maxarea;
    }
};