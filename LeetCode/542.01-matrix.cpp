/*
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (33.53%)
 * Total Accepted:    29.3K
 * Total Submissions: 87.4K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * Example 1: 
 * Input:
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * Output:
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * 
 * 
 * Example 2: 
 * Input:
 * 
 * 0 0 0
 * 0 1 0
 * 1 1 1
 * 
 * Output:
 * 
 * 0 0 0
 * 0 1 0
 * 1 2 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 * 
 * 
 * 
 */
// when I see the solution of leetcode with bfs, I know I had thought wrong.
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) 
            return matrix;
        int cols = matrix[0].size();
        queue<pair<int, int>> que;
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        int dir[4][2] = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
        };
        while (!que.empty()) {
            pair<int, int> pr = que.front();
            int cx = pr.first;
            int cy = pr.second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int dx = cx + dir[i][0];
                int dy = cy + dir[i][1];
                if (dx >= 0 && dx < rows && dy >= 0 && dy < cols && dist[dx][dy] > dist[cx][cy] + 1) {
                    que.push({dx, dy});
                    dist[dx][dy] = dist[cx][cy] + 1;
                }
            }
        }
        return dist;
    }
};
