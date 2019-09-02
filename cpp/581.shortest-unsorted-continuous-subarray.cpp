/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.83%)
 * Total Accepted:    62.7K
 * Total Submissions: 210.1K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
 * 
 * 
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        bool flag = false;
        int minNum = INT_MAX, maxNum = INT_MIN;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] > nums[i]) {
                flag = true;
            }
            if (flag) {
                minNum = min(minNum, nums[i]);
            }
        }
        flag = false;
        for (int i = nums.size()-2; i >= 0; --i) {
            if (nums[i] > nums[i+1]) {
                flag = true;
            }
            if (flag) {
                maxNum = max(maxNum, nums[i]);
            }
        }
        int l, r;
        for (l = 0; l < nums.size(); ++l) {
            if (minNum < nums[l]) {
                break;
            }
        }
        for (r = nums.size()-1; r >= 0; --r) {
            if (maxNum > nums[r]) {
                break;
            }
        }

        return r-l < 0 ? 0 : r-l+1;
    }
};
