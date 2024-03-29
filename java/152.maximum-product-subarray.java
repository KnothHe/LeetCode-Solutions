/*
 * @lc app=leetcode id=152 lang=java
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (34.46%)
 * Likes:    10834
 * Dislikes: 338
 * Total Accepted:    701.9K
 * Total Submissions: 2M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find a contiguous non-empty subarray within the
 * array that has the largest product, and return the product.
 * 
 * The test cases are generated so that the answer will fit in a 32-bit
 * integer.
 * 
 * A subarray is a contiguous subsequence of the array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * 
 */

// @lc code=start
class Solution {
    public int maxProduct(int[] nums) {
        // dp
        int minp = nums[0], maxp = nums[0], len = nums.length, max = nums[0];
        for (int i = 1; i < len; i++) {
            int pminp = minp;
            int pmaxp = maxp;
            int n = nums[i];
            minp = Math.min(n, Math.min(n*pminp, n*pmaxp));
            maxp = Math.max(n, Math.max(n*pminp, n*pmaxp));
            max = Math.max(max, maxp);
        }
        return max;
    }
}
// @lc code=end

