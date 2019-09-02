/*
 * @lc app=leetcode id=65 lang=java 
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (13.97%)
 * Total Accepted:    124.4K
 * Total Submissions: 887.6K
 * Testcase Example:  '"0"'
 *
 * Validate if a given string can be interpreted as a decimal number.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one. However, here is a
 * list of characters that can be in a valid decimal number:
 * 
 * 
 * Numbers 0-9
 * Exponent - "e"
 * Positive/negative sign - "+"/"-"
 * Decimal point - "."
 * 
 * 
 * Of course, the context of these characters also matters in the input.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button to reset your code definition.
 * 
 */
class Solution {
    public boolean isNumber(String s) {
        if (s == null || s.isEmpty()) return false;

        int index = 0;
        int len = s.length();
        boolean hasNumberBeforeDot = false;
    
        // skip whitespace
        for (; index < len && s.charAt(index) == ' '; index++) {  }

        if (index < len && 
                (s.charAt(index) == '+' || 
                s.charAt(index) == '-')) {
            index++;
        }

        // return false is just has space or '+'/'-';
        if (index == len) return false;

        if (Character.isDigit(s.charAt(index))) {
            hasNumberBeforeDot = true;
            while (index < len && Character.isDigit(s.charAt(index))) {
                index++;
            }
        } else if (s.charAt(index) != '.'){
            return false;
        }

        if (index < len && s.charAt(index) == '.') {
            index++;
            if (!hasNumberBeforeDot && 
                    (index == len || !Character.isDigit(s.charAt(index)))) {
                return false;
            }
            while (index < len && Character.isDigit(s.charAt(index))) {
                index++;
            }
        }

        if (index < len && s.charAt(index) == 'e') {
            index++;
            if (index < len && (s.charAt(index) == '+' ||
                    s.charAt(index) == '-')) {
                index++;
            }
            if (index == len || !Character.isDigit(s.charAt(index))) {
                return false;
            }
            while (index < len && Character.isDigit(s.charAt(index))) {
                index++;
            }
        }
        
        // skip trail whitespace
        for (; index < len && s.charAt(index) == ' '; index++) {  }

        if (index < len) {
            return false;
        }

        return true;
    }

    public boolean isNumber_orig(String s) {
        if (s == null || s.isEmpty()) return false;
        s = s.trim();

        int len = s.length();
        int index = 0;
        boolean hasNumberBeforeE = false;
        boolean hasNumberBeforeDot = false;

        // ensure index < s.length() and not start with 'e'
        if (index == len) return false;

        // sign
        if (s.charAt(index) == '-' || s.charAt(index) == '+') {
            index++;
        }

        // return false when input like "+" / "-"
        // ensure index < s.length();
        if (index == len) return false;

        while (index < len &&
                Character.isDigit(s.charAt(index))) {
            hasNumberBeforeE = true;
            hasNumberBeforeDot = true;
            index++;
        }

        // 0 or 0xxx or xxx, integer
        if (index == len) {
            return true;
        }

        if (s.charAt(index) == '.') {
            index++;
            while (index < len && 
                    Character.isDigit(s.charAt(index))) {
                hasNumberBeforeE = true;
                index++;                    
            }
        }


        // x.xxx
        if (index == len) {
            // "."
            if (!hasNumberBeforeDot && s.charAt(index-1) == '.') {
                return false;
            } else {
                return true;
            }
        }

        if (hasNumberBeforeE && s.charAt(index) == 'e') {
            index++;
            // xxe or xxx.xxe
            if (index == len) {
                return false;
            }
            if (s.charAt(index) == '+' ||
                    s.charAt(index) == '-') {
                index++;
            }

            // xxe+ or xxx.xxe-
            if (index == len) {
                return false;
            }

            while (index < len && 
                    Character.isDigit(s.charAt(index))) {
                index++;
            }
        }

        if (index == len) {
            return true;
        } else {
            return false;
        }
    }
}
