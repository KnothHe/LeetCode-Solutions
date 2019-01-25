/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (38.59%)
 * Total Accepted:    183.2K
 * Total Submissions: 474.5K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */

/*
 * reference: https://leetcode.com/problems/set-matrix-zeroes/solution/
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rlen = matrix.size();
        int clen = (rlen == 0) ? 0 : matrix[0].size();
        bool rflag = false;
        bool cflag = false;

        for (int c = 0; c < clen; ++c)  {
            if (matrix[0][c] == 0) cflag = true;
        }
        for (int r = 0; r < rlen; ++r) {
            if (matrix[r][0] == 0) rflag = true;
        }

        for (int i = 1; i < rlen; ++i) {
            for (int j = 1; j < clen; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < rlen; ++i) {
            for (int j = 1; j < clen; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (rflag) {
            for (int r = 0; r < rlen; ++r) matrix[r][0] = 0;
        }
        if (cflag) {
            for (int c = 0; c < clen; ++c) matrix[0][c] = 0;
        }
    }
};
