/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (29.31%)
 * Total Accepted:    201.9K
 * Total Submissions: 689K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * solution reference: https://leetcode.com/problems/spiral-matrix/solution/
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int> { };
        int rLen = matrix.size();
        int cLen = matrix[0].size();
        vector<vector<bool>> marked(rLen, vector<bool>(cLen, false));
        vector<int> result;
        vector<int> dr {0, 1,  0, -1};
        vector<int> dc {1, 0, -1,  0};
        int r = 0, c = 0, di = 0;
        for (int i = 0; i < rLen * cLen; i++) {
            result.push_back(matrix[r][c]);
            marked[r][c] = true;
            int rr = r + dr[di];
            int cc = c + dc[di];
            if (rr >= 0 && rr < rLen && cc >= 0 && cc < cLen && !marked[rr][cc]) {
                r = rr;
                c = cc;
            } else {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }

        return result;
    }
};
