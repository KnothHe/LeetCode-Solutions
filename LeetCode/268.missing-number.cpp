/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (47.21%)
 * Total Accepted:    238.4K
 * Total Submissions: 504.9K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> bools(nums.size()+1, false);
        for (const int &n : nums) {
            bools[n] = true;
        }
        for (int i = 0; i < bools.size(); i++) {
            if (!bools[i]) return i;
        }
        return -1;
    }
};
