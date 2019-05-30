/*
 * @lc app=leetcode id=667 lang=cpp
 *
 * [667] Beautiful Arrangement II
 *
 * https://leetcode.com/problems/beautiful-arrangement-ii/description/
 *
 * algorithms
 * Medium (51.48%)
 * Total Accepted:    16.8K
 * Total Submissions: 32.6K
 * Testcase Example:  '3\n2'
 *
 * 
 * Given two integers n and k, you need to construct a list which contains n
 * different positive integers ranging from 1 to n and obeys the following
 * requirement: 
 * 
 * Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 -
 * a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
 * 
 * 
 * 
 * If there are multiple answers, print any of them.
 * 
 * 
 * Example 1:
 * 
 * Input: n = 3, k = 1
 * Output: [1, 2, 3]
 * Explanation: The [1, 2, 3] has three different positive integers ranging
 * from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: n = 3, k = 2
 * Output: [1, 3, 2]
 * Explanation: The [1, 3, 2] has three different positive integers ranging
 * from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
 * 
 * 
 * 
 * Note:
 * 
 * The n and k are in the range 1 4.
 * 
 * 
 */
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res { 1 };
        vector<bool> used(n+1, false);
        used[1] = true;

        for (int i = k; i >= 1; --i) {
            int num = res.back();
            int ins = num - i;
            if (ins <= 0 || used[ins]) {
                ins = num + i;
            }
            if (ins > n) break;
            res.push_back(ins);
            used[ins] = true;
        }

        for (int i = 1; i < used.size(); ++i) {
            if (!used[i]) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
