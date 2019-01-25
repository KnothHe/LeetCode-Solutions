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
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rlen = matrix.size();
        int clen = 0;
        if (rlen) clen = matrix[0].size();
        for (int r = 0; r < rlen; ++r) {
            for (int c = 0; c < clen; ++c) {
                if (matrix[r][c] == 0) {
                    setNeg(matrix, r, c);
                }
            }
        }
        for (int r = 0; r < rlen; ++r) {
            for (int c = 0; c < clen; ++c) {
                if (matrix[r][c] == INT_MIN+5) {
                    matrix[r][c] = 0;
                }
            }
        }
    }

private:
    void setNeg(vector<vector<int>>& matrix, int r, int c) {
        int rlen = matrix.size();
        int clen = 0;
        if (rlen) clen = matrix[0].size();
        for (int i = 0; i < clen; ++i) {
            if (matrix[r][i] != 0) {
                matrix[r][i] = INT_MIN+5;
            }
        }
        for (int i = 0; i < rlen; ++i) {
            if (matrix[i][c] != 0) {
                matrix[i][c] = INT_MIN+5;
            }
        }
    }
};
