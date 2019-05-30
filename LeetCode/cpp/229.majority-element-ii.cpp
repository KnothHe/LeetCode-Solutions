/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (31.05%)
 * Total Accepted:    90.3K
 * Total Submissions: 290.9K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * Note: The algorithm should run in linear time and in O(1) space.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 * 
 */

/*
 * reference: https://leetcode.com/problems/majority-element-ii/discuss/63520/Boyer-Moore-Majority-Vote-algorithm-and-my-elaboration
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 0) return vector<int> { };
        if (nums.size() == 1) return vector<int> { nums[0] };

        int count1 = 0, count2 = 0, result1 = 0, result2 = 1;
        for (const int &n : nums) {
            if (n == result1) {
                count1++;
            } else if (n == result2) {
                count2++;
            } else if (count1 == 0) {
                result1 = n;
                count1 = 1;
            } else if (count2 == 0) {
                result2 = n;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0; count2 = 0;
        for (const int &n : nums) {
            if (n == result1) count1++;
            if (n == result2) count2++;
        }

        vector<int> result;
        if (count1 > nums.size()/3) result.push_back(result1);
        if (count2 > nums.size()/3) result.push_back(result2);

        return result;
    }
};
