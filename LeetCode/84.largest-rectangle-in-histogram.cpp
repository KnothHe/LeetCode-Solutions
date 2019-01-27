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
 * reference: https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28902/5ms-O(n)-Java-solution-explained-(beats-96)
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() <= 0) return 0;
        vector<int> lessFromLeft(heights.size(), 0);
        vector<int> lessFromRight(heights.size(), 0);
        lessFromLeft[0] = -1;
        lessFromRight[heights.size()-1] = heights.size();

        for (int i = 0; i < heights.size(); i++) {
            int p = i-1;
            while (p >= 0 && heights[p] >= heights[i]) {
                p = lessFromLeft[p];
            }
            lessFromLeft[i] = p;
        }

        for (int i = heights.size()-1; i >= 0; i--) {
            int p = i+1;
            while (p < heights.size() && heights[p] > heights[i]) {
                p = lessFromRight[p];
            }
            lessFromRight[i] = p;
        }

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, heights[i] * (lessFromRight[i] - lessFromLeft[i] -1));
        }

        return maxArea;
    }
};
