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
        vector<vector<int>> next(wordList.size(), vector<int> { });
        // begin: index of endWord
        // end: index of beginWord
        int begin = -1, end = -1;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord) {
                end = i;
            }
        }
        for (int i = 0; i < wordList.size(); i++) {
            if (end == -1 && isNext(wordList[i], beginWord)) {
                next[i].push_back(-1);
            }
            if (wordList[i] == endWord) {
                begin = i;
            } 
            for (int j = i+1; j < wordList.size(); j++) {
                if (isNext(wordList[i], wordList[j])) {
                    next[i].push_back(j);
                    next[j].push_back(i);
                }
            }
        }
        if (begin == -1) return vector<vector<string>> { };
        vector<bool> visited(wordList.size(), false);
        int minLen = bfs(next, visited, begin, end);
        vector<vector<string>> result;
        vector<string> oneResult { endWord };
        for (int i = 0; i < visited.size(); i++) {
            visited[i] = false;
        }
        dfs(next, wordList, visited, result, oneResult, begin, beginWord, minLen);
        for (auto &vec : result) {
            reverse(vec.begin(), vec.end());
        }
        return result;
    }

private:
    bool isNext(string word, string next) {
        int count = 0;
        int len = min(word.size(), next.size());
        for (int i = 0; i < len; i++) {
            if (word[i] != next[i]) {
                count++;
            }
        }
        return count == 1;
    }

    int bfs(vector<vector<int>> &next, vector<bool>& visited, int begin, int end) {
        queue<int> qu;
        qu.push(begin);
        visited[begin] = true;
        vector<int> distTo(visited.size(), 0);
        distTo[begin] = 1;
        int front;

        while(!qu.empty()) {
            front = qu.front();
            qu.pop();
            for (const int &n : next[front]) {
                if (n == -1) {
                    break;
                } else if (!visited[n]) {
                    qu.push(n);
                    visited[n] = true; 
                    distTo[n] = distTo[front]+1;
                }
            }
        }

        return (end == -1) ? distTo[front]+1 : distTo[end];
    }

    void dfs(vector<vector<int>> &next, vector<string> &wordList, vector<bool> &visited,
             vector<vector<string>> &result, vector<string> &oneResult, int index,
             const string &target, int minLen) {
         if (oneResult.size() == minLen) {
            if (index == -1 || oneResult.back() == target) {
                result.push_back(oneResult);
            } 
            return;
        }

        for (const int &n : next[index]) {
            if (n == -1) {
                oneResult.push_back(target);
                dfs(next, wordList, visited, result, oneResult, -1, target, minLen);
                oneResult.pop_back();
            } else if (!visited[n]) {
                visited[n] = true;
                oneResult.push_back(wordList[n]);
                dfs(next, wordList, visited, result, oneResult, n, target, minLen);
                oneResult.pop_back();
                visited[n] = false;
            }
        }
    }
};