/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.59%)
 * Total Accepted:    200.1K
 * Total Submissions: 578.5K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rLen = matrix.size();
        int cLen = (rLen == 0) ? 0 : matrix[0].size();
        int rLeft = 0, rRight = rLen-1;
        int cLeft = 0, cRight = cLen-1;

        if (cLen == 0) return false;
        while (rLeft <= rRight) {
            int mid = rLeft + (rRight - rLeft) / 2;
            int midNum = matrix[mid][0];
            if (midNum > target) rRight = mid-1;
            if (midNum < target) rLeft = mid+1;
            if (midNum == target) return true;
        }
        int row = rRight;
        if (row < 0 || row >= rLen) return false;
        while (cLeft <= cRight) {
            int mid = cLeft + (cRight - cLeft) / 2;
            int midNum = matrix[row][mid];
            if (midNum > target) cRight = mid-1;
            if (midNum < target) cLeft = mid+1;
            if (midNum == target) return true;
        }

        return false;
    }
};
