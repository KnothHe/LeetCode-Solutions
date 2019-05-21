/*
 * @lc app=leetcode id=661 lang=java
 *
 * [661] Image Smoother
 *
 * https://leetcode.com/problems/image-smoother/description/
 *
 * algorithms
 * Easy (48.63%)
 * Total Accepted:    34.8K
 * Total Submissions: 71.6K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a 2D integer matrix M representing the gray scale of an image, you
 * need to design a smoother to make the gray scale of each cell becomes the
 * average gray scale (rounding down) of all the 8 surrounding cells and
 * itself.  If a cell has less than 8 surrounding cells, then use as many as
 * you can.
 * 
 * Example 1:
 * 
 * Input:
 * [[1,1,1],
 * ⁠[1,0,1],
 * ⁠[1,1,1]]
 * Output:
 * [[0, 0, 0],
 * ⁠[0, 0, 0],
 * ⁠[0, 0, 0]]
 * Explanation:
 * For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
 * For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
 * For the point (1,1): floor(8/9) = floor(0.88888889) = 0
 * 
 * 
 * 
 * Note:
 * 
 * The value in the given matrix is in the range of [0, 255].
 * The length and width of the given matrix are in the range of [1, 150].
 * 
 * 
 */
class Solution {
    public int[][] imageSmoother(int[][] M) {
        if (M == null) return null;
        int rLen   = M.length;
        int cLen   = M[0].length;
        int[][] R = new int[rLen][cLen];
        for (int i = 0; i < rLen; ++i) {
            for (int j = 0; j < cLen; ++j) {
                R[i][j] = helper(M, i, j);
            }
        }
        return R;
    }

    private int helper(int[][] M, int r, int c) {
        int cr, cc;
        int rLen   = M.length;
        int cLen   = M[0].length;
        int result = 0;
        int count  = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                cr = r + i;
                cc = c + j;
                if (cr >= 0 && cr < rLen && cc >= 0 && cc < cLen) {
                    result += M[cr][cc];
                    ++count;
                }
            }
        }
        return result / count;
    }
}
