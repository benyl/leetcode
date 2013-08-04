/*
Merge Intervals

http://leetcode.com/onlinejudge#question_56

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/


//===========================================================
// 68 milli secs pass large judge

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// overload compare function
bool operator < (const Interval &a,const Interval &b) {
    return a.start < b.start;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end()); // sort interval on start
        
        int i=0; // anchor for result
        for(int j=1; j<intervals.size(); ++j)
            if(intervals[i].end >= intervals[j].start) // found collapse interval
                intervals[i].end = max(intervals[i].end, intervals[j].end); // merge interval
            else // else try next interval
                intervals[++i] = intervals[j];
        
        intervals.erase(intervals.begin()+i+1, intervals.end()); // erase the legacy interval
        
        return intervals;
    }
};