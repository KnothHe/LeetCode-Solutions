/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 *
 * https://leetcode.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (66.66%)
 * Total Accepted:    30.6K
 * Total Submissions: 45.9K
 * Testcase Example:  '[4,2,5,7]'
 *
 * Given an array A of non-negative integers, half of the integers in A are
 * odd, and half of the integers are even.
 * 
 * Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is
 * even, i is even.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [4,2,5,7]
 * Output: [4,5,2,7]
 * Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been
 * accepted.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int ei = 0, oi = 1;
        while (ei < A.size()) {
            if (A[ei] % 2 != 0) {
                break;
            }
            ei += 2;
        }

        while (ei < A.size() && oi < A.size()) {
            while (oi < A.size()) {
                if (A[oi] % 2 == 0) {
                    swap(A[ei], A[oi]);
                    break;
                }
                oi += 2;
            }
            while (ei < A.size()) {
                if (A[ei] % 2 != 0) {
                    break;
                }
                ei += 2;
            }
        }

        return A;
    }
};
