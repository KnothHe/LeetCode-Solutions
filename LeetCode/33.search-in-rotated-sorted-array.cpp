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

/*
 * reference: https://leetcode.com/problems/search-in-rotated-sorted-array/solution/
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();

        if (len == 0) return -1;
        if (len == 1) return target == nums[0] ? 0 : -1;

        int rotatedIndex = findRotatedIndex(nums, 0, len-1);

        if (nums[rotatedIndex] == target) return rotatedIndex;
        else {
            if (rotatedIndex == 0) {
                return binarySearch(nums, 0, len-1, target);
            } else if (target < nums[0])  {
                return binarySearch(nums, rotatedIndex, len-1, target);
            } else {
                return binarySearch(nums, 0, rotatedIndex-1, target);
            }
        }
        
        return -1;
    }

private:
    int findRotatedIndex(vector<int>& nums, int left, int right) {
        if (nums[left] < nums[right]) {
            return 0;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid+1]) {
                return mid+1;
            } else {
                if (nums[mid] < nums[left]) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
        }
        
        return 0;
    }

    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else {
                if (nums[mid] < target) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }

        return -1;
    }
};
