/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (26.99%)
 * Total Accepted:    147.8K
 * Total Submissions: 547K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), 0);
        for (int pos = nums.size()-2; pos >= 0; --pos) {
            int furthest_pos = (pos+nums[pos] < nums.size()-1) ? pos+nums[pos] : nums.size()-1;
            int min_jmp = memo[pos+1];
            for (int p = pos+2; p <= furthest_pos; ++p) {
                if (memo[p] < min_jmp) {
                    min_jmp = memo[p];
                }
            }
            memo[pos] = min_jmp + 1;
        }

        return memo[0];
    }
};
