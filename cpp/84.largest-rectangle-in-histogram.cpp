/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (29.87%)
 * Total Accepted:    153.1K
 * Total Submissions: 512.5K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */

/*
 * reference: https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> s;
        int tp = -1;

        int i = 0;
        while (i < heights.size()) {
            if (s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i);
                ++i;
            } else {
                tp = s.top();
                s.pop();
                maxArea = max(maxArea, heights[tp] * (s.empty() ? i : i - s.top() - 1));
            }
        }

        while (!s.empty()) {
            tp = s.top();
            s.pop();
            maxArea = max(maxArea, heights[tp] * (s.empty() ? i : i - s.top() - 1));
        }

        return maxArea;
    }
};
