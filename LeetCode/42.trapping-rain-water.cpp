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
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            int left = 0, right = 0;
            for (int j = i; j >= 0; j--) {
                left = max(left, height[j]);
            }
            for (int j = i; j < height.size(); j++) {
                right = max(right, height[j]);
            }
            sum += min(left, right) - height[i];
        }
        return sum;
    }
};
