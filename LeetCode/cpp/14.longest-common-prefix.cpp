/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.92%)
 * Total Accepted:    323.5K
 * Total Submissions: 1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        string lcp("");
        for (int i = 0; i < strs[0].size(); i++) {
            if (strs[0][i] != strs[1][i]) break;
            lcp += strs[0][i];
        }
        for (int i = 2; i < strs.size(); i++) {
            string tmp("");
            for (int j = 0; j < lcp.size(); j++) {
                if (lcp[j] != strs[i][j]) break;
                tmp += lcp[j];
            }
            lcp = tmp;
        }
        return lcp;
    }
};
