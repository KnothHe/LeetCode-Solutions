/*
 * @lc app=leetcode id=43 lang=java
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (30.52%)
 * Total Accepted:    202K
 * Total Submissions: 657.8K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
    public String multiply(String num1, String num2) {
        if ((num1.length() == 1 && num1.charAt(0) == '0') ||
        (num2.length() == 1 && num2.charAt(0) == '0')) {
            return "0";
        }

        List<String> nums = new ArrayList<>();
        int len1 = num1.length();
        int len2 = num2.length();

        for (int i2 = len2-1; i2 >= 0; i2--) {
            StringBuilder sb = new StringBuilder();
            for (int i = len2-1; i > i2; i--) {
                sb.append("0");
            }
            int carry = 0; 
            int n2 = num2.charAt(i2)-'0';
            for (int i1 = len1-1; i1 >= 0; i1--) {
                int n1 = num1.charAt(i1)-'0';
                int temp_result = n1 * n2 + carry;
                carry = temp_result / 10;
                sb.append(temp_result % 10);
            }
            sb.append(carry);
            // reverse number represent
            nums.add(sb.toString());
        }

        String result = "0";
        for (String n : nums) {
            result = add(result, n);
        }

        int i = result.length()-1;
        while (i >= 0) {
            if (result.charAt(i) != '0') {
                break;
            }
            i--;
        }

        return new StringBuilder(result.substring(0, i+1))
            .reverse().toString();
    }

    // add reverse number represent and return reverse number represent
    private String add(String a, String b) {
        int carry = 0;
        int i = 0;
        int j = 0;
        StringBuilder sb = new StringBuilder();

        while (i < a.length() || j < b.length()) {
            int n1 = i < a.length() ? a.charAt(i)-'0' : 0;
            int n2 = j < b.length() ? b.charAt(j)-'0' : 0;
            int temp_result = n1 + n2 + carry;
            carry = temp_result / 10;
            sb.append(temp_result % 10);
            i++;
            j++;
        }
        sb.append(carry);

        return sb.toString();
    }
}
