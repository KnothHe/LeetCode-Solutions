/*
 * @lc app=leetcode id=10 lang=java
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.23%)
 * Total Accepted:    305.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 *
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 * Example 4:
 *
 *
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
 * it matches "aab".
 *
 *
 * Example 5:
 *
 *
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 *
 *
 */
class Solution {
    public boolean isMatch(String s, String p) {
        if (p.isEmpty()) return s.isEmpty();
        boolean first_match = (!s.isEmpty() &&
                (p.charAt(0) == s.charAt(0) ||
                 p.charAt(0) == '.'));

        if (p.length() >= 2 && p.charAt(1) == '*') {
            return (isMatch(s, p.substring(2)) ||
                    first_match && isMatch(s.substring(1), p));
        } else {
            return first_match && isMatch(s.substring(1), p.substring(1));
        }
    }

    private boolean wrong(String s, String p) {
        int slen = s.length();
        int plen = p.length();
        int pidx = 0;
        int sidx = 0;
        
        while (sidx < slen && pidx < plen) {
            if (p.charAt(pidx) == '*') {
                if (p.charAt(pidx - 1) == '.') {
                    return true; // I can't handle this situation
                } else if (p.charAt(pidx - 1) == s.charAt(sidx)) {
                    sidx++;
                } else if (pidx + 1 < plen && 
                        (p.charAt(pidx + 1) == s.charAt(sidx) ||
                        p.charAt(pidx + 1) == '.')) {
                    pidx += 2;
                    sidx++;
                } else {
                    return false;
                }
            } else if (p.charAt(pidx) == '.' ||
                    p.charAt(pidx) == s.charAt(sidx)) {
                pidx++;
                sidx++;
            } else if (pidx+1 < plen && p.charAt(pidx+1) == '*') {
                pidx++;
            } else {
                return false;
            }
        }

        while (pidx < plen && p.charAt(pidx) == '*') {
            pidx++;
        }

        return pidx == plen && sidx == slen;
    }
}
