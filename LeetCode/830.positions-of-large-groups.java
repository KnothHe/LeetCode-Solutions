/*
 * @lc app=leetcode id=830 lang=java
 *
 * [830] Positions of Large Groups
 *
 * https://leetcode.com/problems/positions-of-large-groups/description/
 *
 * algorithms
 * Easy (47.66%)
 * Total Accepted:    25.9K
 * Total Submissions: 54.3K
 * Testcase Example:  '"abbxxxxzzy"'
 *
 * In a string S of lowercase letters, these letters form consecutive groups of
 * the same character.
 * 
 * For example, a string like S = "abbxxxxzyy" has the groups "a", "bb",
 * "xxxx", "z" and "yy".
 * 
 * Call a group large if it has 3 or more characters.  We would like the
 * starting and ending positions of every large group.
 * 
 * The final answer should be in lexicographic order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abbxxxxzzy"
 * Output: [[3,6]]
 * Explanation: "xxxx" is the single large group with starting  3 and ending
 * positions 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "abc"
 * Output: []
 * Explanation: We have "a","b" and "c" but no large group.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "abcdddeeeeaabbbcd"
 * Output: [[3,5],[6,9],[12,14]]
 * 
 * 
 * 
 * Note:  1 <= S.length <= 1000
 * 
 */
class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> result = new ArrayList();

        int l = 0, r = 0;
        while (r < S.length()) {
            while (r < S.length() && S.charAt(r) == S.charAt(l)) {
                ++r;
            }
            if (r-l >= 3) {
                result.add(Arrays.asList(new Integer[]{l, r-1}));
            }
            l = r;
        }

        return result;
    }
}
