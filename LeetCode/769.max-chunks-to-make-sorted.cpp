/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 *
 * https://leetcode.com/problems/max-chunks-to-make-sorted/description/
 *
 * algorithms
 * Medium (51.06%)
 * Total Accepted:    20.6K
 * Total Submissions: 40.3K
 * Testcase Example:  '[4,3,2,1,0]'
 *
 * Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we
 * split the array into some number of "chunks" (partitions), and individually
 * sort each chunk.  After concatenating them, the result equals the sorted
 * array.
 * 
 * What is the most number of chunks we could have made?
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [4,3,2,1,0]
 * Output: 1
 * Explanation:
 * Splitting into two or more chunks will not return the required result.
 * For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1,
 * 2], which isn't sorted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,0,2,3,4]
 * Output: 4
 * Explanation:
 * We can split into two chunks, such as [1, 0], [2, 3, 4].
 * However, splitting into [1, 0], [2], [3], [4] is the highest number of
 * chunks possible.
 * 
 * 
 * Note:
 * 
 * 
 * arr will have length in range [1, 10].
 * arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<bool> used(arr.size(), false);
        int curMinNum = 0;
        int curMaxNum = 0;
        int cnt = 0;

        for (const auto& n : arr) {
            used[n] = true;
            curMaxNum = max(curMaxNum, n);
            if (allUsed(used, curMinNum, curMaxNum)) {
                cnt++;
                curMinNum = curMaxNum+1;
            }
        }
    }

private:
    bool allUsed(vector<bool>& used, int lo, int hi) {
        for (int i = lo; i <= hi; i++) {
            if (!used[i]) return false;
        }
        return true;
    }
};
