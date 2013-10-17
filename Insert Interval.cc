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

// ===========================================================================
// 68 milli secs pass large judge
// time complexity O(n), space complexity O(1) 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int start=0, end=-1; // used to mark the first and last collapse intervals
        
        for(int i=0; i<intervals.size(); ++i) {
            // find collapse intervals
            if ( (newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end) || 
                 (newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end)  || 
                 (intervals[i].start >= newInterval.start && intervals[i].start <= newInterval.end) ||
                 (intervals[i].end >= newInterval.start && intervals[i].end <= newInterval.end) ) 
            {    
                if(end==-1) start = i;
                end = i;
                
                // merge collapse intervals
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            } 
            else if(newInterval.start > intervals[i].end) ++start;
            else break;
        }
        
        if(end == -1) // no collapse intervals, insert into the list
            intervals.insert(intervals.begin() + start, newInterval);
        else { // has collapse intervals, replace the node from start ~ end with interval
            intervals[start] = newInterval;
            intervals.erase(intervals.begin()+start+1, intervals.begin()+end+1);
        }

        return intervals;
    }
};

// =========================================================================
// version 2, use binary match to find the insertion point, and then do merging
class Solution {
    static bool cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval, Solution::cmp);
        intervals.insert(it, newInterval);

        vector<Interval> ret;
        for (auto& itv : intervals) {
            if (ret.empty()) ret.push_back(itv);
            else {
                if (ret.back().end >= itv.start) {
                    ret.back().end = max(ret.back().end, itv.end);
                } else {
                    ret.push_back(itv);
                }
            }
        }
        return ret;
    }
};


// version 3
// use binary search to find the right place to insert
 
bool operator < (const Interval &a,const Interval &b) {
    return a.start < b.start;
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        sort(intervals.begin(), intervals.end());
        int first=lower_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        int last;
        
        if(first!=0 && intervals[first-1].end >= newInterval.start)
            newInterval.start = intervals[--first].start;
            
        for(last=first; last<intervals.size() && 
            intervals[last].start<=newInterval.end; ++last)
            newInterval.end = max(newInterval.end, intervals[last].end);
        
        if(last>first)
            intervals.erase(intervals.begin()+first+1, intervals.begin()+last);
        else
            intervals.insert(intervals.begin()+first, newInterval);
            
        intervals[first] = newInterval;
            
        return intervals;
    }
};