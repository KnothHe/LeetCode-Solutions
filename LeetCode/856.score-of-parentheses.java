/*
 * @lc app=leetcode id=856 lang=java
 *
 * [856] Score of Parentheses
 *
 * https://leetcode.com/problems/score-of-parentheses/description/
 *
 * algorithms
 * Medium (55.88%)
 * Total Accepted:    18K
 * Total Submissions: 32K
 * Testcase Example:  '"()"'
 *
 * Given a balanced parentheses string S, compute the score of the string based
 * on the following rule:
 * 
 * 
 * () has score 1
 * AB has score A + B, where A and B are balanced parentheses strings.
 * (A) has score 2 * A, where A is a balanced parentheses string.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "(())"
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "()()"
 * Output: 2
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "(()(()))"
 * Output: 6
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S is a balanced parentheses string, containing only ( and ).
 * 2 <= S.length <= 50
 * 
 * 
 * 
 * 
 * reference:
 * https://leetcode.com/problems/score-of-parentheses/solution/
 * 
 */
class Solution {
    public int scoreOfParentheses(String S) {
        return helper(S, 0, S.length());
    }

    private int helper(String S, int beg, int end) {
        int ans = 0;
        int bal = 0;

        for (int i = beg; i < end; ++i) {
            bal += S.charAt(i) == '(' ? 1 : -1;
            if (bal == 0) {
                if (i - beg == 1) {
                    ++ans;
                } else {
                    ans += 2 * helper(S, beg+1, i);
                }
                beg = i+1;
            }
        }
        return ans;
    }
}
