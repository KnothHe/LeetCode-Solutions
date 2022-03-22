/*
 * @lc app=leetcode id=15 lang=java
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (30.80%)
 * Likes:    16697
 * Dislikes: 1605
 * Total Accepted:    1.8M
 * Total Submissions: 6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int len = nums.length;
        Arrays.sort(nums);

        Set<List<Integer>> res = new HashSet();
        for (int i = 0; i < len; i++) {
            int n = nums[i];
            List<List<Integer>> twoRes = twoSum(i+1, len-1, nums, 0-n);
            for (List<Integer> tr : twoRes) {
                List<Integer> tmpRes = new ArrayList(3);
                tmpRes.add(n);
                tmpRes.addAll(tr);
                res.add(tmpRes);
            }
        }
        
        List<List<Integer>> finalRes = new ArrayList(res.size());
        finalRes.addAll(res);
        return finalRes;
    }

    public List<List<Integer>> twoSum(int s, int e, int[] nums, int target) {
        int len = nums.length;
        List<List<Integer>> res = new ArrayList();

        if (s >= len) {
            return res;
        }

        while (s < e) {
            int ns = nums[s];
            int ne = nums[e];
            int sum = ns + ne;
            boolean sc = false, ec = false;
            if (sum == target) {
                res.add(Arrays.asList(ns, ne));
                s++;
                e--;
            } else if (sum < target) {
                s++;
            } else {
                e--;
            }
        }
        return res;
    }
}
// @lc code=end

