/*
 * @lc app=leetcode id=30 lang=java
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
    public List<Integer> findSubstring(String s, String[] words) {
        if (s.isEmpty() || words.length == 0) {
            return new ArrayList<Integer>();
        }

        Map<String, Integer> map = new HashMap<>();
        List<Integer> result = new ArrayList<>();
        int word_len = words[0].length();

        for (String word : words) {
            map.put(word, map.getOrDefault(word, 0) + 1);
        }

        for (int i = 0; i <= s.length() - word_len * words.length; i++) {
            String word = s.substring(i, i + word_len);
            if (map.containsKey(word) && map.get(word) > 0) {
                Map<String, Integer> cur_map = new HashMap<>(map);
                cur_map.put(word, cur_map.get(word) - 1);
                int count = 1;
                while (count < words.length) {
                    word = s.substring(i + word_len * count, 
                            i + word_len * (count + 1));
                    if (cur_map.containsKey(word) && cur_map.get(word) > 0) {
                        cur_map.put(word, cur_map.get(word) - 1);
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == words.length) {
                    result.add(i);
                }
            }
        }

        return result;
    }
}
