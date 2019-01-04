/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (28.88%)
 * Total Accepted:    196.5K
 * Total Submissions: 678.3K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

/*
 * Though this code is slow, it works
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rst;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                for (int k = j+1; k < nums.size(); k++) {
                    if ( binary_search(begin(nums)+k+1, end(nums), target-nums[i]-nums[j]-nums[k]) ) {
                        rst.push_back(vector<int>({nums[i], nums[j], nums[k], target-nums[i]-nums[j]-nums[k]}));
                    }
                }
            }
        }
        rst.erase( unique( rst.begin(), rst.end() ), rst.end() );
        set<vector<int>> s( rst.begin(), rst.end() );
        rst.assign( s.begin(), s.end() );
        return rst;
    }
};
