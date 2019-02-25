/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (34.64%)
 * Total Accepted:    182.7K
 * Total Submissions: 527.3K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * reference: https://leetcode.com/problems/contains-duplicate-ii/discuss/61390/C%2B%2B-solution-with-unordered_set
 * 
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;

        if (k <= 0) return false;
        if (k >= nums.size()) k = nums.size()-1;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                s.erase(nums[i-k-1]);
            }
            if (!s.insert(nums[i]).second) {
                return true;
            }
        }

        return false;
    }
};
