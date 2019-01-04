/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (22.06%)
 * Total Accepted:    381.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { // need to optimize
        sort(nums.begin(), nums.end());
        vector<vector<int>> rst;
        if (nums.size() < 3) return rst;
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i-1] && nums.size()-i != 3) continue;
            for (int j = i+1; j < nums.size(); j++) {
                auto f = lower_bound(nums.begin()+j+1, nums.end(), -nums[i]-nums[j]);
                if (f != nums.end() && *f == -nums[i]-nums[j]) {
                    rst.push_back((vector<int>){nums[i], nums[j], *f});
                }
            }
        }
        sort(rst.begin(), rst.end());
        rst.erase(unique(rst.begin(), rst.end()), rst.end());
        return rst;
    }
};
