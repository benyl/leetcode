/*
Merge Intervals

http://leetcode.com/onlinejudge#question_56

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// overwrite operator function for sorting
bool operator < (const Interval &a,const Interval &b) {
    return a.start < b.start;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end());
        
        vector<Interval> result;
        result.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++) { 
            if(intervals[i].end <= result.back().end)
                continue;
            if(intervals[i].start <= result.back().end)
                result.back().end = intervals[i].end;
            else
                result.push_back(intervals[i]);
        }
        
        return result;
    }
};