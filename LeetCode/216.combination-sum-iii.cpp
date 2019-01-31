/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (50.08%)
 * Total Accepted:    110.5K
 * Total Submissions: 220.6K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curRes;
        backtrack(res, curRes, 1, k, n);
        return res;
    }

private:
    void backtrack(vector<vector<int>>& res, vector<int>& curRes, int start, int k, int n) {
        if (k == 0) {
            if (n == 0) {
                res.push_back(curRes);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            curRes.push_back(i);
            backtrack(res, curRes, i+1, k-1, n-i);
            curRes.pop_back();
        }
    }
};
