/*
 * @lc app=leetcode id=213 lang=java
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (39.67%)
 * Likes:    7509
 * Dislikes: 111
 * Total Accepted:    528.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have a security system connected, and it
 * will automatically contact the police if two adjacent houses were broken
 * into on the same night.
 * 
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2), because they are adjacent houses.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
    public int rob(int[] nums) {
        int len = nums.length;

        if (len == 0) {
            return -1;
        }

        if (len == 1) {
            return nums[0];
        }

        if (len == 2) {
            return Math.max(nums[0], nums[1]);
        }

        int t1 = rob0(nums, 0, len-1);
        int t2 = rob0(nums, 1, len);
        return Math.max(t1, t2);
    }

    public int rob0(int[] nums, int start, int end) {
        int len = nums.length;
        if (end - start == 2) {
            Math.max(nums[start], nums[start+1]);
        }

        int dp0 = 0, dp1 = nums[start], dp2 = nums[start+1];
        for (int i = start+2; i < end; i++) {
            int m = Math.max(dp0, dp1);
            dp0 = dp1;
            dp1 = dp2;
            dp2 = m + nums[i];
        }
        return Math.max(dp1, dp2);
    }

}
// @lc code=end

