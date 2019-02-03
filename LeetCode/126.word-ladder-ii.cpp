/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (16.69%)
 * Total Accepted:    107K
 * Total Submissions: 640.1K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 * 
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: []
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // first construct a transformation list and find the index of endWord;
        int begin = -1;
        vector<vector<int>> transformList(wordList.size(), vector<int>{ });
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) {
                begin = i;  
            }
            for (int j = i-1; j >= 0; j--) {
                if (canTransfrom(wordList[i], wordList[j]) && wordList[j] != endWord) {
                    transformList[i].push_back(j);
                }
            }
            for (int j = i+1; j < wordList.size(); j++) {
                if (canTransfrom(wordList[i], wordList[j]) && wordList[j] != endWord) {
                    transformList[i].push_back(j);
                }
            }
            if (canTransfrom(wordList[i], beginWord)) {
                transformList[i].push_back(-1);
            }
        }
        if (begin == -1) return vector<vector<string>> { };
        vector<vector<string>> result;
        vector<string> oneResult { wordList[begin] };
        unordered_set<int> set { };
        int minLen = INT_MAX;
        // then travel
        travel(wordList, transformList, result, oneResult, set, begin, beginWord, minLen);
        // finally
        vector<vector<string>> trueResult;
        for (vector<string> &vec : result) {
            if (vec.size() == minLen) {
                reverse(vec.begin(), vec.end());
                trueResult.push_back(vec);
            }
        }
        return trueResult;
    }

private:
    bool canTransfrom(string word, string next) {
        int count = 0;
        int len = min(word.size(), next.size());
        for (int i = 0; i < len; i++) {
            if (word[i] != next[i]) {
                count++;
            }
        }
        return count == 1;
    }

    void travel(vector<string>& wordList, vector<vector<int>> &transformList, vector<vector<string>> &result,
                vector<string> &oneResult, unordered_set<int> &set, int index, string target, int &minLen) {
        if (oneResult.size() > minLen) return;
        if (index == -1) {
            oneResult.push_back(target);
            result.push_back(oneResult);
            minLen = min(minLen, static_cast<int>(oneResult.size()));
            oneResult.pop_back();
            return;
        }
        for (const int &n : transformList[index]) {
            if (n == -1) {
                travel(wordList, transformList, result, oneResult, set, -1, target, minLen);
            } else if (set.find(n) == set.end()) {
                auto it = set.insert(n);
                oneResult.push_back(wordList[n]);
                travel(wordList, transformList, result, oneResult, set, n, target, minLen);
                set.erase(it.first);
                oneResult.pop_back();
            }
        }
    }
};
