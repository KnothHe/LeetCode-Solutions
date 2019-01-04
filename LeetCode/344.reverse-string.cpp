/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (61.45%)
 * Total Accepted:    299.1K
 * Total Submissions: 486.6K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: "hello"
 * Output: "olleh"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: "amanaP :lanac a ,nalp a ,nam A"
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string reverseString(string s) {
        int l = 0, h = s.size()-1;
        while (l < h) {
            swap(s[l++], s[h--]);
        }
        return s;
    }
};
