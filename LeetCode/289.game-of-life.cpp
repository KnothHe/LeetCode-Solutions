/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (43.18%)
 * Total Accepted:    100K
 * Total Submissions: 231.4K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply
 * as Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 * 
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal,
 * vertical, diagonal) using the following four rules (taken from the above
 * Wikipedia article):
 * 
 * 
 * Any live cell with fewer than two live neighbors dies, as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 * 
 * 
 * Write a function to compute the next state (after one update) of the board
 * given its current state. The next state is created by applying the above
 * rules simultaneously to every cell in the current state, where births and
 * deaths occur simultaneously.
 * 
 * Example:
 * 
 * 
 * Input: 
 * [
 * [0,1,0],
 * [0,0,1],
 * [1,1,1],
 * [0,0,0]
 * ]
 * Output: 
 * [
 * [0,0,0],
 * [1,0,1],
 * [0,1,1],
 * [0,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches the border of the array. How would you address these problems?
 * 
 * 
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rowLen = board.size();
        if (rowLen == 0) return;
        int colLen = board[0].size();
        vector<vector<int>> nextBoard(rowLen, vector<int>(colLen, 0));

        for (int i = 0; i < rowLen; i++) {
            for (int j = 0; j < colLen; j++) {
                int state = board[i][j];
                int count = getNumberOfNeighbors(board, i, j);
                if (state == 1 && (count < 2 || count > 3)) {
                    state = 0;
                }
                if (state == 0 && count == 3) {
                    state = 1;
                }
                nextBoard[i][j] = state;
            }
        }

        for (int i = 0; i < rowLen; i++) {
            for (int j = 0; j < colLen; j++) {
                board[i][j] = nextBoard[i][j];
            }
        }
    }

private:
    int getNumberOfNeighbors(vector<vector<int>>& board, int r, int c) {
        int count =  0;
        int rowLen = board.size();
        if (rowLen == 0) return 0;
        int colLen = board[0].size();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int nr = r + i;
                int nc = c + j;
                if (nr >= 0 && nr < rowLen && nc >= 0 && 
                nc < colLen && board[nr][nc] == 1) {
                        count++;
                }
            }
        }

        return count;
    }
};
