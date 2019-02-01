/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (46.20%)
 * Total Accepted:    217.4K
 * Total Submissions: 470.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image.
 * 
 * Rotate the image by 90 degrees (clockwise).
 * 
 * Note:
 * 
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 * 
 * Example 1:
 * 
 * 
 * Given input matrix = 
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Given input matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ], 
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 * 
 * 
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() <= 1) return;
        int len = matrix.size();
        int layer = len / 2;
        int leftTop = 0, rightBottom = len-1;
        vector<vector<int>> indexs(4, vector<int>(2));
        for (int i = 0; i < layer; i++) {
            indexs[0][0] = leftTop; 
            indexs[0][1] = leftTop;
            indexs[1][0] = leftTop;
            indexs[1][1] = rightBottom;
            indexs[2][0] = rightBottom;
            indexs[2][1] = rightBottom;
            indexs[3][0] = rightBottom;
            indexs[3][1] = leftTop;
            int times = rightBottom - leftTop;
            for (int j = 0; j < times; j++) {
                int prev = matrix[indexs[3][0]][indexs[3][1]];
                for (int k = 0; k <= 3; k++) {
                    int temp = matrix[indexs[k][0]][indexs[k][1]];
                    matrix[indexs[k][0]][indexs[k][1]] = prev;
                    prev = temp;
                }
                indexs[0][1] += 1;
                indexs[1][0] += 1;
                indexs[2][1] -= 1;
                indexs[3][0] -= 1;
            }
            leftTop++;
            rightBottom--;
        }
    }
};
