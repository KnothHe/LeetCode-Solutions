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

/*
 * reference: https://leetcode.com/problems/search-a-2d-matrix/discuss/26220/Don't-treat-it-as-a-2D-matrix-just-treat-it-as-a-sorted-list
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rLen = matrix.size();
        int cLen = rLen == 0 ? 0 : matrix[0].size();
        int left = 0, right = rLen * cLen - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midNum = matrix[mid/cLen][mid%cLen];
            if (midNum > target) right = mid - 1;
            if (midNum < target) left = mid + 1;
            if (midNum == target) return true;
        }

        return false;
    }
};
