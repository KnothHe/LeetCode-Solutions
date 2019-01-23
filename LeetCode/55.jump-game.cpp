/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (30.61%)
 * Total Accepted:    217.6K
 * Total Submissions: 708.2K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */

/*
 *  https://leetcode.com/problems/jump-game/solution/
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left_most_pos = nums.size()-1;

        for (int i = nums.size()-2; i >= 0; --i) {
            if (i+nums[i] >= left_most_pos) {
                left_most_pos = i;
            }
        }

        return left_most_pos == 0;
    }
};