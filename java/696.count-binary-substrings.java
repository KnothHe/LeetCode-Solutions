/*
 * @lc app=leetcode id=696 lang=java
 *
 * [696] Count Binary Substrings
 *
 * https://leetcode.com/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (53.30%)
 * Total Accepted:    30.7K
 * Total Submissions: 57.5K
 * Testcase Example:  '"00110"'
 *
 * Give a string s, count the number of non-empty (contiguous) substrings that
 * have the same number of 0's and 1's, and all the 0's and all the 1's in
 * these substrings are grouped consecutively. 
 * 
 * Substrings that occur multiple times are counted the number of times they
 * occur.
 * 
 * Example 1:
 * 
 * Input: "00110011"
 * Output: 6
 * Explanation: There are 6 substrings that have equal number of consecutive
 * 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
 * Notice that some of these substrings repeat and are counted the number of
 * times they occur.
 * Also, "00110011" is not a valid substring because all the 0's (and 1's) are
 * not grouped together.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "10101"
 * Output: 4
 * Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
 * number of consecutive 1's and 0's.
 * 
 * 
 * 
 * Note:
 * s.length will be between 1 and 50,000.
 * s will only consist of "0" or "1" characters.
 *
 * 
 */
class Solution {
    public int countBinarySubstrings(String s) {
        int len = s.length();
        int prev = 0;
        int cur = 1;
        int count = 0;

        for (int i = 1; i < len; i++) {
            if (s.charAt(i) != s.charAt(i-1)) {
                count += Math.min(cur, prev);
                prev = cur;
                cur = 1;
            } else {
                cur++;
            }
        }
        count += Math.min(cur, prev);

        return count;
    }

    private int solve2(String s) {
        int len = s.length();
        int cur_count = 1;
        ArrayList<Integer> group = new ArrayList<>();

        for (int i = 1; i < len; i++) {
            if (s.charAt(i) != s.charAt(i-1)) {
                group.add(cur_count);
                cur_count = 1;
            } else {
                cur_count++;
            }
        }
        group.add(cur_count);
        
        int group_len = group.size();
        int count = 0;
        for (int i = 1; i < group_len; i++) {
            count += Math.min(group.get(i), group.get(i-1));
        }

        return count;
    }

    private int solve1(String s) {
        int zero_count = 0;
        int one_count = 0;
        int cur_count = 0;
        int count = 0;
         
        for (char c : s.toCharArray()) {
            if (c == '0') {
                if (zero_count == 0) {
                    cur_count = one_count;
                    one_count = 0;
                }
                zero_count++;
                if (zero_count <= cur_count) {
                    count++;
                }
            } else if (c == '1') {
                if (one_count == 0) {
                    cur_count = zero_count;
                    zero_count = 0;
                }
                one_count++;
                if (one_count <= cur_count) {
                    count++;
                }
            }
        }

        return count;
    }
}
