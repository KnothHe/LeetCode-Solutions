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
class Solution {
public:
    enum class Direction {
        LEFT_TO_RIGHT, RIGHT_TO_LEFT, TOP_TO_BOTTOM, BOTTOM_TO_TOP
    };

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int x = 0, y = 0;
        Direction dir = Direction::LEFT_TO_RIGHT;

        for (int i = 1; i <= n*n; i++) {
            if (x < 0 || x >= n || y < 0 || y >= n || res[x][y] != 0) {
                if (dir == Direction::LEFT_TO_RIGHT) {
                    dir = Direction::TOP_TO_BOTTOM;
                    x++;
                    y--;
                } else if (dir == Direction::TOP_TO_BOTTOM) {
                    dir = Direction::RIGHT_TO_LEFT;
                    x--;
                    y--;
                } else if (dir == Direction::RIGHT_TO_LEFT) {
                    dir = Direction::BOTTOM_TO_TOP;
                    x--;
                    y++;
                } else if (dir == Direction::BOTTOM_TO_TOP) {
                    dir = Direction::LEFT_TO_RIGHT;
                    x++;
                    y++;
                }
            }

            res[x][y] = i;

            if (dir == Direction::LEFT_TO_RIGHT) {
                y++;
            } else if (dir == Direction::TOP_TO_BOTTOM) {
                x++;
            } else if (dir == Direction::RIGHT_TO_LEFT) {
                y--;
            } else if (dir == Direction::BOTTOM_TO_TOP) {
                x--;
            }
        }

        return res;
    }
};
