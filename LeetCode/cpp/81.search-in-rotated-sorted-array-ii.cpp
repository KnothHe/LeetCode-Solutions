/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.48%)
 * Total Accepted:    152.8K
 * Total Submissions: 470.4K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len-1;
        int left_end = -1, right_begin = 0;

        if (nums.size() >= 1 && nums.front() == nums.back()) {
            for (int n : nums) {
                if (n == target) return true;
            }
            return false;
        }
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
            if (nums[mid] >= nums[0]) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        cout << left_end << " " << right_begin;
        int res1 = binarySearch(nums, 0, left_end, target);
        int res2 = binarySearch(nums, right_begin, nums.size()-1, target);

        return (res1 != -1 || res2 != -1);
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
