/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (34.47%)
 * Total Accepted:    293.8K
 * Total Submissions: 851.8K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
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
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> result;
        int current = 0;
        while(current < intervals.size()) {
            int start = intervals[current].start;
            int prevEnd = intervals[current].end;
            while(current+1 < intervals.size() && prevEnd >= intervals[current+1].start) {
                current++;
                prevEnd = max(prevEnd, intervals[current].end);
            }
            int end = max(prevEnd, intervals[current].end);
            result.push_back(Interval(start, end));
            current++;
        }
        return result;
    }

    static bool compare(Interval a, Interval b) {
        if (a.start == b.start) {
            return a.end < b.end;
        } else {
            return a.start < b.start;
        }
    }
};
