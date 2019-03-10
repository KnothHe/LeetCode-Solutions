/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * https://leetcode.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (69.06%)
 * Total Accepted:    7.9K
 * Total Submissions: 11.5K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * Given an array A of strings made only from lowercase letters, return a list
 * of all characters that show up in all strings within the list (including
 * duplicates).  For example, if a character occurs 3 times in all strings but
 * not 4 times, you need to include that character three times in the final
 * answer.
 * 
 * You may return the answer in any order.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["bella","label","roller"]
 * Output: ["e","l","l"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["cool","lock","cook"]
 * Output: ["c","o"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] is a lowercase letter
 * 
 * 
 * 
 */
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> common(26, numeric_limits<int>::max());

        for (const auto &str : A) {
            vector<int> count(26, 0);
            for (const auto &c : str) {
                count[c-'a']++;
            }
            for (int i = 0; i < count.size(); i++) {
                common[i] = min(common[i], count[i]);
            }
        }

        vector<string> result;
        for(int i = 0; i < common.size(); i++) {
            if (common[i] != numeric_limits<int>::max()) {
                for (int j = 0; j < common[i]; j++) {
                    result.push_back(string(1, i+'a'));
                }
            }
        }
        
        return result;
    }
};