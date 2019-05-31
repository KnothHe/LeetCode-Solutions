/*
 * @lc app=leetcode id=788 lang=java
 *
 * [788] Rotated Digits
 *
 * https://leetcode.com/problems/rotated-digits/description/
 *
 * algorithms
 * Easy (54.05%)
 * Total Accepted:    27.3K
 * Total Submissions: 50.4K
 * Testcase Example:  '10'
 *
 * X is a good number if after rotating each digit individually by 180 degrees,
 * we get a valid number that is different from X.  Each digit must be rotated
 * - we cannot choose to leave it alone.
 * 
 * A number is valid if each digit remains a digit after rotation. 0, 1, and 8
 * rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each
 * other, and the rest of the numbers do not rotate to any other number and
 * become invalid.
 * 
 * Now given a positive number N, how many numbers X from 1 to N are good?
 * 
 * 
 * Example:
 * Input: 10
 * Output: 4
 * Explanation: 
 * There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 * Note that 1 and 10 are not good numbers, since they remain unchanged after
 * rotating.
 * 
 * 
 * Note:
 * 
 * 
 * N  will be in range [1, 10000].
 * 
 * reference :
 * https://leetcode.com/problems/rotated-digits/discuss/117975/Java-dp-solution-9ms
 * 
 */
class Solution {
    public int rotatedDigits(int N) {
        int count = 0;
        int[] dp = new int[N + 1];

        for (int i = 0; i <= N; i++) {
            if (i < 10) {
                switch (i) {
                    case 0 :
                    case 1 :
                    case 8 :
                        dp[i] = 1;
                        break;
                    case 2 :
                    case 5 :
                    case 6 :
                    case 9 :
                        dp[i] = 2;
                        count++;
                        break;
                    default :
                        dp[i] = 0;
                        break;
                }
            } else {
                int a = dp[ i / 10 ];
                int b = dp[ i % 10 ];
                if (a == 1 && b == 1) {
                    dp[i] = 1;
                } else if (a >= 1 && b >= 1) {
                    dp[i] = 2;
                    count++;
                } else {
                    dp[i] = 0;
                }
            }
        }

        return count;
    }

    private int solve1(int N) {
        int count = 0;
        
        for (int i = 1; i <= N; i++) {
            boolean isVaild = true;
            boolean isDiff = false;

            for (char c : String.valueOf(i).toCharArray()) {
                switch (c) {
                    case '2' :
                    case '5' :
                    case '6' :
                    case '9' : isDiff = true; break;
                    case '3' :
                    case '4' :
                    case '7' : isVaild = false; break;
                }
            }

            if (isVaild && isDiff) {
                count++;
            }
        }

        return count;
    }
}
