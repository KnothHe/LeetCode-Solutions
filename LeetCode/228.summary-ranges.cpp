/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (34.86%)
 * Total Accepted:    121.3K
 * Total Submissions: 347.8K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * Example 1:
 * 
 * 
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 * 
 * 
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return vector<string> { vector<string>()};
        if (nums.size() == 1) return vector<string> { vector<string>{ to_string(nums[0]) } };
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            string str(to_string(nums[i]));
            int begin = i;
            while (i+1 < nums.size() && nums[i+1] == nums[i]+1) {
                i++;
            }
            if (i != begin) {
                str.append("->").append(to_string(nums[i]));
            }
            res.push_back(str);
        }
        return res;
    }
};
