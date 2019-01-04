/*
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (38.82%)
 * Total Accepted:    131.8K
 * Total Submissions: 339.3K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 * 
 */
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp {0};
        while (dp.size() <= n) {
            int m = dp.size();
            int squares = INT_MAX;
            for (int i = 1; i*i <= m; i++) {
                squares = min(squares, dp[m-i*i]+1);
            }
            dp.push_back(squares);
        }
        return dp[n];
    }
};
