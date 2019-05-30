/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (29.26%)
 * Total Accepted:    176K
 * Total Submissions: 601.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int ind = -1;
        for (int i = len-2; i >= 0; i--) {
            if (i >= 0 && nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int swi;
        for (int i = len-1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                 swi = i;
                 break;
            }
        }
        int tmp = nums[swi]; nums[swi] = nums[ind]; nums[ind] = tmp;
        reverse(nums.begin()+ind+1, nums.end());
    }
};
