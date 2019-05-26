/*
 * @lc app=leetcode id=647 lang=java
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (56.74%)
 * Total Accepted:    97.7K
 * Total Submissions: 171.8K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 * 
 */
class Solution {
    public int countSubstrings(String s) {
        int count = 0;

        for (int block = s.length(); block > 0; --block) {
            for (int i = 0; i <= s.length()-block; ++i) {
                if (isPalindromic(s.substring(i, i+block))) {
                    ++count;
                }
            }
        }

        return count;
    }

    private boolean isPalindromic(String s) {
        int lo = 0, hi = s.length()-1;
        while (lo < hi) {
            if (s.charAt(lo) != s.charAt(hi)) {
                return false;
            }
            ++lo;
            --hi;
        }
        return true;
    }
}
