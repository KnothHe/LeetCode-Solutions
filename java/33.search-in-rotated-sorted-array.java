/*
 * @lc app=leetcode id=33 lang=java
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (37.57%)
 * Likes:    13180
 * Dislikes: 863
 * Total Accepted:    1.4M
 * Total Submissions: 3.7M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * There is an integer array nums sorted in ascending order (with distinct
 * values).
 * 
 * Prior to being passed to your function, nums is possibly rotated at an
 * unknown pivot index k (1 <= k < nums.length) such that the resulting array
 * is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
 * (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
 * and become [4,5,6,7,0,1,2].
 * 
 * Given the array nums after the possible rotation and an integer target,
 * return the index of target if it is in nums, or -1 if it is not in nums.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is an ascending array that is possibly rotated.
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
    public int search(int[] nums, int target) {
        int len = nums.length;
        int minIdx = findMinIdx(nums);
        int res = binarySearch(nums, 0, minIdx-1, target);
        if (res == -1) {
            res = binarySearch(nums, minIdx, len-1, target);
        }
        return res;
    }

    public int findMinIdx(int[] nums) {
        int len = nums.length, s = 0, e = len - 1;
        while (s < e) {
            int mid = (s+e)/2;
            int m = nums[mid];

            if (m >= nums[s] && m > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }

    public int binarySearch(int[] nums, int s, int e, int target) {
        if (s > e) {
            return -1;
        }

        while (s <= e) {
            int mid = (s+e)/2;
            int m = nums[mid];

            if (m < target) {
                s = mid + 1;
            } else if (m == target) {
                return mid;
            } else {
                e = mid - 1;
            }
        }

        return -1;
    }
}
// @lc code=end

