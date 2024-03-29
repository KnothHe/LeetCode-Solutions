/*
 * @lc app=leetcode id=300 lang=java
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (48.86%)
 * Likes:    11234
 * Dislikes: 222
 * Total Accepted:    810.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 * 
 * A subsequence is a sequence that can be derived from an array by deleting
 * some or no elements without changing the order of the remaining elements.
 * For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
 * complexity?
 * 
 */

// @lc code=start
class Solution {
    public int lengthOfLIS(int[] nums) {
        // use TreeMap
        TreeMap<Integer, Integer> dp = new TreeMap<>();
        dp.put(nums[0], 1);
        int max = 1;
        for (int i = 1; i < nums.length; i++) {
            // find lower key less than current
            Integer lk = dp.lowerKey(nums[i]);
            int cmax;
            if (lk == null) {
                cmax = 1;
            } else {
                cmax = dp.get(lk)+1;
            }

            Integer ck = dp.ceilingKey(nums[i]);
            if (ck != null) {
                dp.remove(ck);
            }

            dp.put(nums[i], cmax);
            max = Math.max(cmax, max);
        }
        return max;
    }

    public int O_n2(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0] = 1;
        int gmax = 1;
        for (int i = 1; i < nums.length; i++) {
            int max = 0;
            for (int j = i-1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    max = Math.max(max, dp[j]);
                }
            }
            dp[i] = max+1;
            gmax = Math.max(dp[i], gmax);
        }
        return gmax;
    }
}
// @lc code=end

