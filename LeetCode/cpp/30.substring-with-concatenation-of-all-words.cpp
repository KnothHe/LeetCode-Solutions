/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (23.50%)
 * Total Accepted:    133.6K
 * Total Submissions: 565.5K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.size() == 0 || words.size() == 0) {
            return {  };
        }

        int word_len = words[0].size();
        int words_len = words.size();
        int str_len = s.size();
        unordered_map<string, int> map;
        vector<int> result;

        for (string word : words) {
            map[word]++;
        }

        for (int i = 0; i <= str_len - word_len * words_len; i++) {
            string word = s.substr(i, word_len);
            if (map.find(word) != map.end() && map[word] > 0) {
                unordered_map cur_map(map);
                cur_map[word]--;
                int count = 1;
                while (count < words_len) {
                    word = s.substr(i + word_len * count, word_len);
                    if (cur_map.find(word) != cur_map.end() 
                            && cur_map[word] > 0) {
                        cur_map[word]--;
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == words_len) {
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};
