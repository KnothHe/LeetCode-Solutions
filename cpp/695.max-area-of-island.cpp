/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (56.07%)
 * Total Accepted:    72.4K
 * Total Submissions: 129.1K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * Find the maximum area of an island in the given 2D array. (If there is no
 * island, the maximum area is 0.)
 * 
 * Example 1:
 * 
 * 
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 
 * Given the above grid, return 6. Note the answer is not 11, because the
 * island must be connected 4-directionally.
 * 
 * Example 2:
 * 
 * 
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 * 
 * Note: The length of each dimension in the given grid does not exceed 50.
 * 
 */
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rowLen = grid.size();
        int colLen = (rowLen == 0 ? 0 : grid[0].size());
        for (int i = 0; i < rowLen; ++i) {
            for (int j = 0; j < colLen; ++j) {
                if (grid[i][j] == 1) {
                    int cnt = 0;
                    dfs(grid, i, j, cnt);
                    maxArea = max(maxArea, cnt);
                }
            }
        } 

        return maxArea;
    }

private:
    void dfs(vector<vector<int>>& grid, int r, int c, int& cnt) {
        grid[r][c] = 0;
        cnt++;
        int rowLen = grid.size();
        int colLen = (rowLen == 0 ? 0 : grid[0].size());
        vector<vector<int>> dir = {
            {-1, 0},
            { 1, 0},
            {0, -1},
            {0,  1}
        };
        for (int i = 0; i < 4; ++i) {
            int cr = r + dir[i][0];
            int cc = c + dir[i][1];
            if (cr >= 0 && cr < rowLen && cc >= 0 &&cc < colLen && grid[cr][cc] == 1) {
                dfs(grid, cr, cc, cnt);
            }
        }
    }
};
