/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (28.28%)
 * Total Accepted:    183.7K
 * Total Submissions: 648.7K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> memo(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            int product = nums[i];
            int curMax = nums[i];
            for (int j = i-1; j >= 0; j--) {
                product *= nums[j];
                curMax = max(curMax, product);
            }
            memo[i] = curMax;
        }

        int maxNum = numeric_limits<int>::min();
        for (int &n : memo) {
            maxNum = max(maxNum, n);
        }

        return maxNum;
    }
};
