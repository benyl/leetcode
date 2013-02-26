/*
Insert Interval

http://leetcode.com/onlinejudge#question_57

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        if(newInterval.start > intervals.back().end) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        // find the first and last interval that overlap with newInterval
        int first = -1, last = -1;
        for(int i=0; i<intervals.size(); i++) {
            if(intervals[i].start > newInterval.end) {
                last = i;
                break;
            }
            if(intervals[i].end < newInterval.start)
                continue;
                
            if(first==-1) first = i;
            
            if(intervals[i].start < newInterval.start)
                newInterval.start = intervals[i].start;
            
            if(intervals[i].end > newInterval.end)
                newInterval.end = intervals[i].end;
        }
        
        if(first==-1 && last==-1) {             // can not find a smaller interval, insert at last
            intervals.insert(intervals.end(), newInterval);
        } else if (first==-1 && last!=-1) {     // break out a middle, insert at middle
            intervals.insert(intervals.begin() + last, newInterval);
        } else { // (first != -1)               // has collapse, remove the collapse intervals
            intervals[first] = newInterval;
            if(last==-1) last = intervals.size();
            intervals.erase(intervals.begin()+first+1, intervals.begin()+last);
        }
        
        return intervals;
    }
};