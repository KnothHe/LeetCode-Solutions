/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (46.03%)
 * Total Accepted:    294.3K
 * Total Submissions: 639.1K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curNum;
        backtrack(candidates, result, curNum, 0, 0, target);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& curNums, int sum, int start, int target) {
        if (start >= nums.size() || sum >= target) {
            if (sum == target) {
                result.push_back(curNums);
            }
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            curNums.push_back(nums[i]);
            backtrack(nums, result, curNums, sum+nums[i], i, target);
            curNums.pop_back();
        }
    }
};
