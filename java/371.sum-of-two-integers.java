/*
 * @lc app=leetcode id=371 lang=java
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Medium (50.63%)
 * Likes:    2398
 * Dislikes: 3621
 * Total Accepted:    286.1K
 * Total Submissions: 565.1K
 * Testcase Example:  '1\n2'
 *
 * Given two integers a and b, return the sum of the two integers without using
 * the operators + and -.
 * 
 * 
 * Example 1:
 * Input: a = 1, b = 2
 * Output: 3
 * Example 2:
 * Input: a = 2, b = 3
 * Output: 5
 * 
 * 
 * Constraints:
 * 
 * 
 * -1000 <= a, b <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
    // bit-manipulation
    public int getSum(int a, int b) {
        int c;
        // carry or second num not null
        while (b != 0) {
            // carry
            c = a&b;
            // sum without carry
            a = a^b;
            // final carry
            b = c<<1;
        }
        return a;
    }
}
// @lc code=end

