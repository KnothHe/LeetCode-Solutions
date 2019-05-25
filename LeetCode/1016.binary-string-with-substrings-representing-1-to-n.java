/*
 * @lc app=leetcode id=1016 lang=java
 *
 * [1016] Binary String With Substrings Representing 1 To N
 *
 * https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/
 *
 * algorithms
 * Medium (62.89%)
 * Total Accepted:    6.1K
 * Total Submissions: 9.8K
 * Testcase Example:  '"0110"\n3'
 *
 * Given a binary string S (a string consisting only of '0' and '1's) and a
 * positive integer N, return true if and only if for every integer X from 1 to
 * N, the binary representation of X is a substring of S.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "0110", N = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "0110", N = 4
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 1000
 * 1 <= N <= 10^9
 * 
 * 
 */
class Solution {
    public boolean queryString(String S, int N) {
        for (int i = 1; i <= N; i++) {
            String number = Integer.toBinaryString(i);
            if (S.indexOf(number) < 0) {
                return false;
            }
        }

        return true;
    }
}
