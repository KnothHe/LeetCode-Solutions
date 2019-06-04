/*
 * @lc app=leetcode id=38 lang=java
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (40.31%)
 * Total Accepted:    284.4K
 * Total Submissions: 701.3K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
class Solution {
    public String countAndSay(int n) {
        StringBuilder sb = new StringBuilder("1");

        for (int p = 1; p < n; p++) {
            StringBuilder cur_sb = new StringBuilder("");
            int count = 1;
            for (int k = 1; k < sb.length(); k++) {
                if (sb.charAt(k) == sb.charAt(k-1)) {
                    count++;
                } else {
                    cur_sb.append(count).append(sb.charAt(k-1));
                    count = 1;
                }
            }
            cur_sb.append(count).append(sb.charAt(sb.length()-1));
            sb = cur_sb;
        }

        return sb.toString();
    }
}
