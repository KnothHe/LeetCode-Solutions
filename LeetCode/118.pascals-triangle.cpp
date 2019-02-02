/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (43.96%)
 * Total Accepted:    220K
 * Total Submissions: 500.4K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0) return vector<vector<int>> { };
        vector<int> nums(numRows, 0);
        vector<vector<int>> result;
        nums[0] = 1;
        for (int i = 0; i < numRows; i++) {
            vector<int> oneRow(i+1);
            for (int j = i; j > 0; j--) {
                nums[j] += nums[j-1];
                oneRow[j] = nums[j];
            }
            oneRow[0] = 1;
            result.push_back(oneRow);
        }
        return result;
    }
};
