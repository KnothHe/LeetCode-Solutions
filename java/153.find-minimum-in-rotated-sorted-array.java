/*
 * @lc app=leetcode id=153 lang=java
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (47.78%)
 * Likes:    6281
 * Dislikes: 374
 * Total Accepted:    869.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array of length n sorted in ascending order is rotated between 1
 * and n times. For example, the array nums = [0,1,2,4,5,6,7] might
 * become:
 * 
 * 
 * [4,5,6,7,0,1,2] if it was rotated 4 times.
 * [0,1,2,4,5,6,7] if it was rotated 7 times.
 * 
 * 
 * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results
 * in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
 * 
 * Given the sorted rotated array nums of unique elements, return the minimum
 * element of this array.
 * 
 * You must write an algorithm that runs in O(log n) time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,4,5,1,2]
 * Output: 1
 * Explanation: The original array was [1,2,3,4,5] rotated 3 times.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2]
 * Output: 0
 * Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4
 * times.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [11,13,15,17]
 * Output: 11
 * Explanation: The original array was [11,13,15,17] and it was rotated 4
 * times. 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 5000
 * -5000 <= nums[i] <= 5000
 * All the integers of nums are unique.
 * nums is sorted and rotated between 1 and n times.
 * 
 * 
 */

// @lc code=start
class Solution {
    public int findMin(int[] nums) {
        int len = nums.length, s = 0, e = len-1;
        while (s < e) {
            int mid = (s + e) / 2;
            int n = nums[mid];

            if (n >= nums[s] && n > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return nums[s];
    }

    public int oneWay(int[] nums) {
        int len = nums.length;
        int s = 0, e = len-1;
        while (s < e && nums[s] > nums[e]) {
            int mi = (s + e) / 2;
            int m = nums[mi];
            
            if (m > nums[s]) {
                s = mi + 1;
            } else if (m == nums[s]) {
                return Math.min(nums[s], nums[e]);
            } else {
                e = mi;
            }
        }
        return nums[s];
    }
}
// @lc code=end

