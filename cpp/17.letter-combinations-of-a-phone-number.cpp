/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (38.00%)
 * Total Accepted:    278.1K
 * Total Submissions: 730.8K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> t{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> rst;
        for (int i = 0; i < t[digits[0]-'2'].size(); i++) {
            rst.push_back(string(1, t[digits[0]-'2'][i]));
        }
        for (int i = 1; i < digits.size(); i++) {
            vector<string> tmp(rst);
            rst.clear();
            for (int j = 0; j < tmp.size(); j++) {
                for (int k = 0; k < t[digits[i]-'2'].size(); k++) {
                    rst.push_back(tmp[j] + t[digits[i]-'2'][k]);
                }
            }
        }
        return rst;
    }
};
