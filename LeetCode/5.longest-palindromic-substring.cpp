/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.62%)
 * Total Accepted:    370.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int l= 0, r = 0;
        for (int i = 0; i < s.size(); i++) {
            int l1 = 0, r1 = -2;
            if (i+1 < s.size() && s[i] == s[i+1]) {
                l1 = i;
                r1 = i+1;
            }
            while (l1 >= 1 && r1 < s.size()-1) {
                if (s[l1-1] == s[r1+1]) {
                    l1--;
                    r1++;
                 } else {
                     break;
                 }
            }
            if (r1-l1 >= r-l) {
                l = l1;
                r = r1;
            }
            int l2 = 0, r2 = -2;
            if (i+1 < s.size() && i-1 >= 0 && s[i-1] == s[i+1]) {
                l2 = i-1;
                r2 = i+1;
            }
            while (l2 >= 1 && r2 < s.size()-1) {
                if (s[l2-1] == s[r2+1]) {
                    l2--;
                    r2++;
                 } else {
                     break;
                 }
            }
            if (r2-l2 >= r-l) {
                l = l2;
                r = r2;
            }
        }
        return s.substr(l, r-l+1);
    }
};
