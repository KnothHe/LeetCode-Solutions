/*
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (32.61%)
 * Total Accepted:    157.1K
 * Total Submissions: 481.5K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int clen = obstacleGrid[0].size();
        int rlen = obstacleGrid.size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[rlen-1][clen-1] == 1) return 0;
        int dp[rlen][clen];
        for (int i = 0; i < rlen; i++) {
            fill(dp[i], dp[i]+clen, 0);
        }
        dp[0][0] = 1;
        for (int i = 0; i < rlen; i++) {
            for (int j = 0; j < clen; j++) {
                if (i-1 >= 0 && obstacleGrid[i-1][j] != 1) dp[i][j] += dp[i-1][j];
                if (j-1 >= 0 && obstacleGrid[i][j-1] != 1) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[rlen-1][clen-1];
    }
};
