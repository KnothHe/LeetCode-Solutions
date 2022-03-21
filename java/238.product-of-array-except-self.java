/*
 * @lc app=leetcode id=238 lang=java
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (63.73%)
 * Likes:    11509
 * Dislikes: 702
 * Total Accepted:    1.1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 * 
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * You must write an algorithm that runs in O(n) time and without using the
 * division operation.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * 
 * 
 * Follow up: Can you solve the problem in O(1) extra space complexity? (The
 * output array does not count as extra space for space complexity analysis.)
 * 
 */

// @lc code=start
class Solution {
    public int[] productExceptSelf(int[] nums) {
        return twoPass(nums);
    }

    public int[] twoPass(int[] nums) {
        int len = nums.length;
        int[] answer = new int[len];

        // forward
        answer[0] = nums[0];
        int p = nums[0];
        for (int i = 1; i < len; i++) {
            answer[i] = p;
            p *= nums[i];
        }

        // backward
        p = 1;
        for (int i = len-1; i > 0; i--) {
            answer[i] = answer[i] * p;
            p *= nums[i];
        }
        answer[0] = p;
        return answer;
    }

    public int[] twoArrays(int[] nums) {
        // two array
        int len = nums.length;

        if (len == 0) {
            return nums;
        }

        if (len == 1) {
            int[] a = new int[len];
            a[0] = 0;
            return a;
        }

        int[] forward = new int[len];
        int[] backward = new int[len];
        int[] answer = new int[len];
        forward[0] = nums[0];
        backward[len-1] = nums[len-1];
        for (int i = 1; i < len; i++) {
            forward[i] = forward[i-1] * nums[i];
        }
        for (int i = len-2; i > 0; i--) {
            backward[i] = backward[i+1] * nums[i];
        }
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                answer[i] = backward[1];
                continue;
            }
            if (i == len-1 && len >= 2) {
                answer[i] = forward[len-2];
                continue;
            }
            answer[i] = forward[i-1] * backward[i+1];
        }
        return answer;
    }
}
// @lc code=end

