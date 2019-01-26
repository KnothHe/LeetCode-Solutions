/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.53%)
 * Total Accepted:    354.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len-1;
        int left_end = -1, right_begin = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid-1 >= 0 && nums[mid-1] > nums[mid]) {
                left_end = mid-1;
                right_begin = mid;
                break;
            }
            if (mid+1 < len && nums[mid] > nums[mid+1]) {
                left_end = mid;
                right_begin = mid+1;
                break;
            }
            if (nums[mid] > nums[0]) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        int res1 = binarySearch(nums, 0, left_end, target);
        int res2 = binarySearch(nums, right_begin, nums.size()-1, target);

        if (res1 != -1) return res1;
        if (res2 != -1) return res2;
        return -1;
    }

private:
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midNum = nums[mid];
            if (target < midNum) right = mid-1;
            else if (target > midNum) left = mid+1;
            else return mid;
        }

        return -1;
    }
};
