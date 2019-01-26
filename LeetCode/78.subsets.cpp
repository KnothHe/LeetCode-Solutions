/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (50.09%)
 * Total Accepted:    317K
 * Total Submissions: 632.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

/*
 * reference: https://leetcode.com/problems/subsets/discuss/224190/c%2B%2B-beats-100-using-bit-manipulation
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        uint64_t size = 1<<nums.size();
        vector<vector<int>> rst(size);

        for (int i = 0; i < size; i++) {
            uint64_t b = 1;
            for (int j = 0; j < nums.size(); ++j, b <<= 1) {
                if ((i & b) == b) rst[i].push_back(nums[j]);
            }
        }

        return rst;
    }
};
