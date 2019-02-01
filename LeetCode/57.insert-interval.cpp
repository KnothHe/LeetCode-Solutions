/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (30.53%)
 * Total Accepted:    160.4K
 * Total Submissions: 525K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int start = -1, end = -1;
        bool isStartChanged = false, isEndChanged = false;
        vector<Interval> result;
        int index = 0;
        while (index < intervals.size()) {
            if (newInterval.start <= intervals[index].end) {
                if (newInterval.start >= intervals[index].start) {
                    start = intervals[index].start;
                } else {
                    start = newInterval.start;
                }
                isStartChanged = true;
                break;
            } else {
                result.push_back(intervals[index]);
                index++;
            }
        }
        while (index < intervals.size()) {
            if (newInterval.end <= intervals[index].end) {
                if (newInterval.end >= intervals[index].start) {
                    end = intervals[index].end;
                    index++;
                } else {
                    end = newInterval.end;
                }
                isEndChanged = true;
                result.push_back(Interval(start, end));
                break;
            } else {
                index++;
            }
        }

        if (!isStartChanged) {
            result.push_back(newInterval);
        } else if (!isEndChanged) {
            result.push_back(Interval(start, newInterval.end));
        }

        for (int i = index; i < intervals.size(); i++) {
            result.push_back(intervals[i]);
        }

        return result;
    }
};
