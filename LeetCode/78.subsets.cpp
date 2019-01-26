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
 * reference: https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rst;
        vector<int> tmpRst;

        backtrack(nums, rst, tmpRst, 0);

        return rst;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& rst, vector<int>& tmpRst, int start) {
        rst.push_back(tmpRst);
        for (int i = start; i < nums.size(); i++) {
            tmpRst.push_back(nums[i]);
            backtrack(nums, rst, tmpRst, i+1);
            tmpRst.pop_back();
        }
    }
};
