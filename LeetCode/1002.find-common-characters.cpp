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
        for (int i = 0; i < A.size(); i++) {
            count.push_back(unordered_map<char, int> { });
            for (int j = 0;  j < A[0].size(); j++) {
                char ch = A[i][j];
                if (count[i].find(ch) == count[i].end()) {
                    count[i][ch] = 1;
                } else {
                    count[i][ch]++;
                }
            }
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            common[ch] = numeric_limits<int>::max();
        }
        for (int i = 0; i < count.size(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (count[i].find(ch) != count[i].end()) {
                    common[ch] = min(common[ch], count[i][ch]);
                } else {
                    common[ch] = 0;
                }
            }
        }
        vector<string> result;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (common[ch] != numeric_limits<int>::max()) {
                for (int c = 0; c < common[ch]; c++){
                    result.push_back(string(1, ch));
                } 
            }
        }
        return result;
    }

private:
    vector<unordered_map<char, int>> count;
    unordered_map<char, int> common;
};
