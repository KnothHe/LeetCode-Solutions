/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (27.44%)
 * Total Accepted:    175K
 * Total Submissions: 635.3K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if (nums.empty()) return 1;
        int id;
        for (id = 0; nums[id] <= 0 && id < nums.size(); id++) { }
        int rst;
        for (rst = 1; nums[id+rst-1] == rst; rst++) { }
        return rst;

        // if (nums.empty()) return 1;
        // sort(nums.begin(), nums.end());
        // int num = 1;
        // while (num <= nums.back()) {
        //     if (!binary_search(nums.begin(), nums.end(), num)) return num;
        //     num++;
        // }
        // return num;
    }
};
