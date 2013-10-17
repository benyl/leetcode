/*
Candy 

http://oj.leetcode.com/problems/candy/

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

// dynamic programming
// 132 ms pass judge cases
// time complexity o(n), space complexity o(1)

class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.size()<2) return ratings.size();
        
        int sumCandy = 0, leftCandy = 0; // remember last child's candy
        
        for(int i=0, next=1; i<ratings.size(); i=next++) {
            // the candy needed to be higher than left neighbor
            leftCandy = (i==0 || ratings[i-1]>=ratings[i]) ? 1 : leftCandy+1; 
            
            // find the child on the right with lower rating than both neighbors
            while(next<ratings.size() && ratings[next]<ratings[next-1]) ++next; 
            
            int rightCandy = (next - i); // the candy needed to be higher than right neighbor
            sumCandy += rightCandy * (rightCandy-1) / 2; // sum all candy between i and next
            
            int thiscandy = max(leftCandy, rightCandy);
            sumCandy += thiscandy;
            
            leftCandy = (next==i+1) ? thiscandy : 1; // remember last child's candy
        }
        
        return sumCandy;
    }
};