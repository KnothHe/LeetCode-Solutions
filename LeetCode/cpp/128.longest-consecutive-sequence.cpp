/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (40.58%)
 * Total Accepted:    185.4K
 * Total Submissions: 456.9K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 * solution reference: https://leetcode.com/problems/longest-consecutive-sequence/solution/
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_set<int> set;
        for (const int &n : nums) {
            set.insert(n);
        }
        int maxCount = 1;
        for (const int &n : set) {
            if (set.find(n-1) == set.end()) {
                int count = 1;
                int num = n;
                while (set.find(num+1) != set.end()) {
                    count++;
                    num = num+1;
                }
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};
