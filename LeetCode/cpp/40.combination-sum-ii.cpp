/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (40.91%)
 * Total Accepted:    211.5K
 * Total Submissions: 517K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> oneRes;
        travel(candidates, res, oneRes, target, 0);

        return res;
    }

private:
    void travel(vector<int>& candidates, vector<vector<int>>& res, vector<int> oneRes, int rest, int beg) {
        if (rest <= 0) {
            if (rest == 0) {
                res.push_back(oneRes);
            }
            return;
        }
        
        for (int i = beg; i < candidates.size(); ++i) {
            int num = candidates[i];
            oneRes.push_back(num);
            rest -= num;
            travel(candidates, res, oneRes, rest, i+1);
            rest += num;
            oneRes.pop_back();
            while (i+1 < candidates.size() && candidates[i+1] == candidates[i]) ++i;
        }
    }
};
