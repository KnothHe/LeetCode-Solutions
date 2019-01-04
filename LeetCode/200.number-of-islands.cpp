/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (38.27%)
 * Total Accepted:    235.9K
 * Total Submissions: 616.1K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int ci, int cj) {
        if (grid[ci][cj] == '0') {
            return;
        }
        grid[ci][cj] = '0';
        int rows = grid.size();
        int cols = grid[0].size();
        int dir[4][2] = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
        };
        for (int i = 0; i < 4; i++) {
            int cx = ci + dir[i][0];
            int cy = cj + dir[i][1];
            if (cx >= 0 && cx < rows && cy >= 0 && cy < cols && grid[cx][cy]!= 0) {
                dfs(grid, cx, cy);
            }
        }
    }
};
