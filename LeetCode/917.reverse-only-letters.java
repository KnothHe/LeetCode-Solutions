/*
 * @lc app=leetcode id=917 lang=java
 *
 * [917] Reverse Only Letters
 *
 * https://leetcode.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (55.95%)
 * Total Accepted:    26.1K
 * Total Submissions: 46.7K
 * Testcase Example:  '"ab-cd"'
 *
 * Given a string S, return the "reversed" string where all characters that are
 * not a letter stay in the same place, and all letters reverse their
 * positions.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "ab-cd"
 * Output: "dc-ba"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "a-bC-dEf-ghIj"
 * Output: "j-Ih-gfE-dCba"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "Test1ng-Leet=code-Q!"
 * Output: "Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S.length <= 100
 * 33 <= S[i].ASCIIcode <= 122 
 * S doesn't contain \ or "
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
    public String reverseOnlyLetters(String S) {
        StringBuilder sb = new StringBuilder("");
        for (char c : S.toCharArray()) {
            if (Character.isLowerCase(c) || Character.isUpperCase(c)) {
                sb.append(c);
            }
        }

        StringBuilder ans = new StringBuilder(S);
        int index = 0;
        for (char c : sb.reverse().toString().toCharArray()) {
            while (!Character.isLowerCase(ans.charAt(index)) 
                    && !Character.isUpperCase(ans.charAt(index))) {
                ++index;
            }
            ans.setCharAt(index, c);
            ++index;
        }

        return ans.toString();
    }
}
