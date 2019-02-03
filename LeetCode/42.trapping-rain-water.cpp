/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (41.31%)
 * Total Accepted:    245.2K
 * Total Submissions: 593.5K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 * solution reference: https://leetcode.com/problems/trapping-rain-water/solution/
 * 
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len <= 1) return 0;
        vector<int> left(len), right(len);
        left[0] = height[0];
        for (int i = 1; i < len; i++) {
            left[i] = max(left[i-1], height[i]);
        }
        right[len-1] = height[len-1];
        for (int i = len-2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i]);
        }
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += min(left[i], right[i]) - height[i];
        }
        return sum;
    }
};
