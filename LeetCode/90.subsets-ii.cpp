/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (41.00%)
 * Total Accepted:    183.1K
 * Total Submissions: 446.3K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        uint64_t size = 1<<nums.size();
        vector<vector<int>> res(size);

        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; ++i) {
            uint64_t b = 1;
            for (int j = 0; j < nums.size(); ++j, b <<= 1) {
                if ((i & b) == b) res[i].push_back(nums[j]);
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());

        return res;
    }
};
