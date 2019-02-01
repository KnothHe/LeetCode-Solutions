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
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        int count = 1; 
        int maxCount = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]+1) {
                count++;
            } else if (nums[i] > nums[i-1]) {
                maxCount = max(maxCount, count);
                count = 1;
            }
        }

        return max(maxCount, count);
    }
};
