/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.49%)
 * Total Accepted:    338K
 * Total Submissions: 834.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> rst;
        bool carry = false;
        int sum_of_one_digit = 0;
        int index = digits.size()-1;

        do {
            carry = false;
            sum_of_one_digit = digits[index] + 1;
            if (sum_of_one_digit > 9) {
                sum_of_one_digit = 0;
                carry = true;
            }
            rst.push_back(sum_of_one_digit);
            index--;
        } while (carry && index >= 0);

        if (carry) {
            rst.push_back(1);
        } else {
            while (index >= 0) {
                rst.push_back(digits[index]);
                index--;
            }
        }

        reverse(rst.begin(), rst.end());

        return rst;
    }
};
