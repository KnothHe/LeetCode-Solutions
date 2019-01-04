/*
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (42.98%)
 * Total Accepted:    176.2K
 * Total Submissions: 409.3K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int clen = grid[0].size();
        int rlen = grid.size();
        int dp[rlen][clen];
        for (int r = 0; r < rlen; r++) {
            fill(dp[r], dp[r]+clen, 0);
        }
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                if (r == 0 && c == 0) dp[r][c] = 0;
                else if (r == 0) dp[r][c] = dp[r][c-1];
                else if (c == 0) dp[r][c] = dp[r-1][c];
                else dp[r][c] = min(dp[r-1][c], dp[r][c-1]);
                dp[r][c] += grid[r][c];
            }
        }
        return dp[rlen-1][clen-1];
    }
};
