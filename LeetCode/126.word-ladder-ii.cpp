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
 * reference: https://leetcode.com/problems/word-ladder-ii/discuss/40475/My-concise-JAVA-solution-based-on-BFS-and-DFS
 * 
 */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> nodeNeighbors;
        unordered_map<string, int> distance;
        vector<vector<string>> result;
        vector<string> solution;

        dict.insert(beginWord);
        bfs(beginWord, endWord, dict, nodeNeighbors, distance);
        dfs(beginWord, endWord, dict, nodeNeighbors, distance, solution, result);

        return result;
    }

private:
    void bfs(string start, string end, unordered_set<string> &dict, 
    unordered_map<string, vector<string>> &nodeNeighbors,
    unordered_map<string, int> &distance) {
        queue<string> que;
        que.push(start);
        distance[start] = 0;

        while (!que.empty()) {
            int count = que.size();
            bool foundEnd = false;
            for (int i = 0; i < count; i++) {
                string cur = que.front();
                que.pop();
                int curDistance = distance[cur];
                vector<string> neighbors = getNeighbors(cur, dict);
                nodeNeighbors[cur] = neighbors;

                for (const auto &neighbor : neighbors) {
                    if (distance.find(neighbor) == distance.end()) {
                        distance[neighbor] = curDistance + 1;
                        if (end == neighbor) {
                            foundEnd = true;
                        } else {
                            que.push(neighbor);
                        }
                    }
                }
            }

            if (foundEnd) break;
        }
    }

    vector<string> getNeighbors(string node, unordered_set<string> &dict) {
        vector<string> result;
        vector<char> chs(node.begin(), node.end());
        
        for (char ch = 'a'; ch <= 'z'; ch++) {
            for (int i = 0; i < chs.size(); i++) {
                if (chs[i] == ch) continue;
                char ori_ch = chs[i];
                chs[i] = ch;
                string temp_str(chs.begin(), chs.end());
                if (dict.find(temp_str) != dict.end()) {
                    result.push_back(temp_str);
                }
                chs[i] = ori_ch;
            }
        }

        return result;
    }

    void dfs(string cur, string end, unordered_set<string> &dict,
    unordered_map<string, vector<string>> &nodeNeighbors,
    unordered_map<string, int> &distance, vector<string> &solution,
    vector<vector<string>> &result) {
        solution.push_back(cur);
        if (end == cur) {
            result.push_back(solution);
        } else {
            for (string next : nodeNeighbors[cur]) {
                if (distance.find(next) != distance.end() && 
                    distance[next] == distance[cur] + 1) {
                    dfs(next, end, dict, nodeNeighbors, distance, solution, result);
                }
            }
        }
        solution.pop_back();
    }
};