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
    enum class Index {
        GOOD, BAD, UNKNOWN
    };
    
    vector<Index> memo;

    bool isAGoodPosition(int pos, vector<int> &nums) {
        if (memo[pos] != Index::UNKNOWN) {
            return memo[pos] == Index::GOOD;
        }
        
        int furthestPosition = ((pos+nums[pos] < nums.size()-1) ? pos+nums[pos] : nums.size()-1);
        // for (int p = pos+1; p <= furthestPosition; ++p) {
        for (int p = furthestPosition; p >= pos+1; --p) {
            if (isAGoodPosition(p, nums)) {
                memo[p] = Index::GOOD;
                return true;
            }
        }

        memo[pos] = Index::BAD;
        return false;
    }

    bool canJump(vector<int>& nums) {
        memo.resize(nums.size());

        for (auto &ind : memo) {
            ind = Index::UNKNOWN;
        }
        memo[memo.size()-1] = Index::GOOD;

        return isAGoodPosition(0, nums);
    }
};