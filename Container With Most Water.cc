/*
Container With Most Water

http://leetcode.com/onlinejudge#question_11

Given n non-negative integers a1, a2, ..., an, where each represents a 
point at coordinate (i, ai). 

n vertical lines are drawn such that the two endpoints of line i is at 
(i, ai) and (i, 0). Find two lines, which together with x-axis forms a 
container, such that the container contains the most water.

Note: You may not slant the container.
*/
class Solution {
public:
    int maxArea(vector<int> &height) {
        int area = 0, left = 0, right = height.size()-1;
        while(left<right) {
            area = max(area, min(height[left], 
                       height[right]) * (right - left));
            if(height[left]<height[right]) 
                ++left;
            else 
                --right;
        }
        return area;
    }
};