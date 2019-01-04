class Solution {
    public boolean isPalindrome(int x) {
         if (x < 0)
            return false;
        Integer integerX = x;
        int len = integerX.toString().length();
        for (int i = 1; i <= len / 2; i++) {
            int head = x / (int)Math.pow(10, (len - i)) % 10;
            int tail = x / (int)Math.pow(10, i - 1) % 10;
            if ( head != tail) {
                return false;
            }
        }
        return true;
   }
}
