/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (32.08%)
 * Total Accepted:    108.8K
 * Total Submissions: 339.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */

/*
 * reference: https://leetcode.com/problems/maximal-rectangle/discuss/29054/Share-my-DP-solution
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        const int rLen = matrix.size();
        const int cLen = matrix[0].size();

        vector<int> height(cLen, 0);
        vector<int> left(cLen, 0);
        vector<int> right(cLen, cLen);
        int maxArea = 0;

        for (int r = 0; r < rLen; r++) {
            for (int c = 0; c < cLen; c++) {
                if (matrix[r][c] == '1') height[c]++;
                else height[c] = 0;
            }

            int leftBound = 0, rightBound = cLen;
            for (int c = 0; c < cLen; c++) {
                if (matrix[r][c] == '1') {
                    left[c] = max(leftBound, left[c]);
                } else {
                    leftBound = c+1;
                    left[c] = 0;
                }
            }
            for (int c = cLen-1; c >= 0; c--) {
                if (matrix[r][c] == '1') {
                    right[c] = min(rightBound, right[c]);
                } else {
                    rightBound = c;
                    right[c] = cLen;
                }
            }

            for (int c = 0; c < cLen; c++) {
                maxArea = max(maxArea, height[c] * (right[c] - left[c]));
            }
        }

        return maxArea;
    }
};
