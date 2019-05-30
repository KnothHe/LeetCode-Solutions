/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (28.90%)
 * Total Accepted:    204.8K
 * Total Submissions: 708.7K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 *  ['A','B','C','E'],
 *  ['S','F','C','S'],
 *  ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int xlen = board.size(), ylen = board[0].size();
        for (int i = 0; i < xlen; i++) {
            for (int j = 0; j < ylen; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> marked(xlen, vector<bool>(ylen, false));
                    marked[i][j] = true;
                    if (dfs(board, i, j, word, 1, marked)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, int x, int y, string& word, int index, vector<vector<bool>>& marked) {
        if (index >= word.size()) return true;
        int xlen = board.size(), ylen = board[0].size();
        int d[4][2] = {
            {-1, 0},
            {0, -1},
            { 1, 0},
            {0,  1}
        };
        for (int i = 0; i < 4; i++) {
            int tx = x + d[i][0];
            int ty = y + d[i][1];
            if (tx >= 0 && tx < xlen && ty >= 0 && ty < ylen) {
                if (!marked[tx][ty] && board[tx][ty] == word[index]) {
                    marked[tx][ty] = true;
                    if (dfs(board, tx, ty, word, index+1, marked))
                        return true;
                    marked[tx][ty] = false;
                }
            }
        }
        return false;
    }
};
