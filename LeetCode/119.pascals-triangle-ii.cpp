/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (41.42%)
 * Total Accepted:    178.4K
 * Total Submissions: 430.4K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the kth index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */

/*
 * reference: https://leetcode.com/problems/pascals-triangle-ii/discuss/38420/Here-is-my-brief-O(k)-solution
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec(rowIndex+1, 0);
        vec[0] = 1;

        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                vec[j] += vec[j-1];
            }
        }

        return vec;
    }
};
