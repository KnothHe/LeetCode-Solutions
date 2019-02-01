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
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int> { };
        int rLen = matrix.size();
        int cLen = matrix[0].size();
        vector<int> result(rLen * cLen);
        int left = 0, top = 0, right = cLen-1, bottom = rLen-1;
        for (int i = 0; i < result.size(); ) {
            for (int j = left; i < result.size() && j <= right; j++) {
                result[i++] = matrix[top][j];
            }
            for (int j = top+1; i < result.size() && j <= bottom; j++) { 
                result[i++] = matrix[j][right];
            }
            for (int j = right-1; i < result.size() && j >= left; j--) {
                result[i++] = matrix[bottom][j];
            }
            for (int j = bottom-1; i < result.size() && j > top; j--) {
                result[i++] = matrix[j][left];
            }
            left++; top++; right--; bottom--;
        }

        return result;
    }
};
