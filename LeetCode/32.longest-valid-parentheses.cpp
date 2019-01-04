/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (23.84%)
 * Total Accepted:    146.4K
 * Total Submissions: 613.6K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len <= 1) return 0;
        int longest = 0;
        int dp[len];
        fill(dp, dp+len, 0);
        for  (int i = 0; i < len;) {
            if (s[i] == ')' && i-1 >= 0 && i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
                dp[i] = dp[i-1]+2;
                if (i-dp[i] >= 0) {
                    dp[i] += dp[i-dp[i]];
                }
                i++;
            } else if (s[i] == '(' && i+1 < len && s[i+1] == ')') {
                dp[i+1] = 2;
                if (i-1 >= 0) {
                    dp[i+1] += dp[i-1];
                }
                i += 2;
            } else {
                dp[i] = 0;
                i++;
            }
            longest = max(longest, dp[i-1]);
        }
        return longest;
    }
};
