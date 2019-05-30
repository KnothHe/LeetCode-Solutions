/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (44.76%)
 * Total Accepted:    123.9K
 * Total Submissions: 276.8K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */

/*
 * reference: https://leetcode.com/problems/spiral-matrix-ii/discuss/222730/c%2B%2B-4ms-12lines-easy-to-understand
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int left_top = 0, right_bottom = n-1;

        for (int i = 0, size = n*n; i < size;) {
            for (int j = left_top; j <= right_bottom; ++j) res[left_top][j] = ++i; // left to right
            for (int j = left_top+1; j <= right_bottom; ++j) res[j][right_bottom] = ++i; // top to bottom
            for (int j = right_bottom-1; j >= left_top; --j) res[right_bottom][j] = ++i; // right to left
            for (int j = right_bottom-1; j >= left_top+1; --j) res[j][left_top] = ++i; // bottom to top
            left_top++;
            right_bottom--;
        }

        return res;
    }
};
