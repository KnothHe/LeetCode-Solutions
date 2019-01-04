/*
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (46.81%)
 * Total Accepted:    71K
 * Total Submissions: 151.3K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, find the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. You may
 * assume that each word will contain only lower case letters. If no such two
 * words exist, return 0.
 * 
 * Example 1:
 * 
 * 
 * Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16 
 * Explanation: The two words can be "abcw", "xtfn".
 * 
 * Example 2:
 * 
 * 
 * Input: ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4 
 * Explanation: The two words can be "ab", "cd".
 * 
 * Example 3:
 * 
 * 
 * Input: ["a","aa","aaa","aaaa"]
 * Output: 0 
 * Explanation: No such pair of words.
 * 
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> wordBits;
        int wordBit = 0;
        for (string word : words) {
            wordBit = 0;
            for (char c : word)
                wordBit |= (1 << (c - 'a'));
            wordBits.push_back(wordBit);
        }

        int maxLen = 0;
        int curLen = 0;
        int len = words.size();
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < len; j++) {
                if ((wordBits[i] & wordBits[j]) == 0) {
                    curLen = words[i].size() * words[j].size();
                    if (curLen > maxLen)
                        maxLen = curLen;
                }
            }
        }
        return maxLen;
    }

// ---- This is my solution
//public:
//    int maxProduct(vector<string>& words) {
//        int len = words.size();
//        int maxLen = 0;
//        for (int i = 0; i < len; i++) {
//            for (int j = i+1; j < len; j++) {
//                int curLen = words[i].size() * words[j].size();
//                if (curLen > maxLen && !is_share(words[i], words[j])) {
//                    maxLen = curLen;
//                }
//            }
//        }
//        return maxLen;
//    }

//private:
//    bool is_share(string stra, string strb) {
//        int lena = stra.size();
//        int lenb = strb.size();
//        for (int i = 0; i < lena; i++) {
//            for (int j = 0; j < lenb; j++) {
//                if (stra[i] == strb[j])
//                    return true;
//            }
//        }

//        return false;
//    }
};
