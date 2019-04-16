/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (28.83%)
 * Total Accepted:    88.5K
 * Total Submissions: 306.9K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        bool hasFirstMax = false;
        bool hasSecondMax = false;
        bool hasThirdMax = false;

        int firstMax, secondMax, thirdMax;

        for (const auto &n : nums) {
            if (!hasFirstMax || n >= firstMax) {
                if (!hasFirstMax || n > firstMax) {
                    thirdMax = secondMax;
                    secondMax = firstMax;
                    firstMax = n;
                    if (hasSecondMax) hasThirdMax = true;
                    if (hasFirstMax) hasSecondMax = true;
                }
                hasFirstMax = true;
            } else if (!hasSecondMax || n >= secondMax) {
                if (!hasSecondMax || n > secondMax) {
                    thirdMax = secondMax;
                    secondMax = n;
                }
                hasSecondMax = true;
            } else if (!hasThirdMax || n >= thirdMax) {
                thirdMax = n;
                hasThirdMax = true;
            }
        }

        if (hasThirdMax) return thirdMax;
        else return firstMax;
    }
};
