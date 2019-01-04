/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (50.09%)
 * Total Accepted:    245.5K
 * Total Submissions: 489.5K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> phs;
        gen(phs, "", 0, 0, n);
        return phs;
    }
private:
    void gen(vector<string>& phs, string str, int lps, int rps, int n) {
        if (lps+rps == 2*n) {
            phs.push_back(str);
            return;
        }
        if (lps == 0 || lps < n) {
            gen(phs, str+"(", lps+1, rps, n);
        } 
        if (rps < lps) {
            gen(phs, str+")", lps, rps+1, n);
        } 
    }
};
