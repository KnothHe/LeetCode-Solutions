/*
 * @lc app=leetcode id=215 lang=java
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (49.75%)
 * Total Accepted:    437.7K
 * Total Submissions: 877.5K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
class Solution {
    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        int lo = 0, hi = len - 1;
        k = len - k;
        while (lo < hi) {
            int p = partition(nums, lo, hi);
            if (p < k) { lo = p + 1; }
            else if (p > k) { hi = p - 1; }
            else { break; }
        }
        return nums[k];
    }
    public int partition(int[] nums, int lo, int hi) {
        int p = lo;
        lo++;
        while (true) {
            while (lo <= hi && nums[lo] <= nums[p]) { lo++; }
            while (hi >= lo && nums[hi] >= nums[p]) { hi--; }
            if (lo >= hi) { break; }
            exch(nums, lo, hi);
        }
        exch(nums, p, hi);
        return hi;
    }
    public void exch(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
