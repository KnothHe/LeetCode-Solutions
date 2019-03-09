/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (72.96%)
 * Total Accepted:    35.7K
 * Total Submissions: 49K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an array of integers A sorted in non-decreasing order, return an array
 * of the squares of each number, also in sorted non-decreasing order.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A is sorted in non-decreasing order.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        int len = A.size();
        
        int index = -1;
        for (int i = 0; i < len; i++) {
            if (A[i] < 0 && (i+1) < len && A[i+1] >= 0) {
                index = i;
            }
            A[i] = A[i]*A[i];
        }
        
        int left = index, right = index+1;
        while (left >= 0 || right < len) {
            if (left < 0) {
                result.push_back(A[right]);
                right++;
            } else if (right == len) {
                result.push_back(A[left]);
                left--;
            } else if (A[left] < A[right]) {
                result.push_back(A[left]);
                left--;
            } else {
                result.push_back(A[right]);
                right++;
            }
        }

        return result;
    }
};
