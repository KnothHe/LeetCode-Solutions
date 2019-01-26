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

/*
 * reference: https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmpRes;

        sort(nums.begin(), nums.end());
        backtrack(nums, res, tmpRes, 0);
        
        return res;
    }

private:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmpRes, int start) {
        res.push_back(tmpRes);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            tmpRes.push_back(nums[i]);
            backtrack(nums, res, tmpRes, i+1);
            tmpRes.pop_back();
        }
    }
};
