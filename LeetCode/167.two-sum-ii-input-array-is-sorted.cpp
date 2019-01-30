/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (48.74%)
 * Total Accepted:    202K
 * Total Submissions: 413.9K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int lo = 0, hi = numbers.size()-1;
        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];
            if (sum > target) {
                hi--;
            } else if (sum < target) {
                lo++;
            } else {
                res.push_back(lo+1);
                res.push_back(hi+1);
                return res;
            }
        }

        return res;
    }
};
