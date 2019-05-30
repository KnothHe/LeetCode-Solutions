class Solution {
    public int romanToInt(String s) {
        int rtn = 0;
        char[] romanChar = s.toCharArray();
        int[] romanInt = RomanCharToInt(romanChar);
        for (int i = 0; i < romanInt.length - 1; i++)
            if (romanInt[i] < romanInt[i + 1])
                romanInt[i] = -romanInt[i];
        for (int i = 0; i < romanInt.length; i++) 
            rtn += romanInt[i];
        return rtn;
    }
    
    public static int[] RomanCharToInt(char[] a) {
        int[] rtn = new int[a.length];
        for (int i = 0; i < a.length; i++) {
            if (a[i] == 'I' || a[i] == 'i') rtn[i] = 1;
            if (a[i] == 'V' || a[i] == 'v') rtn[i] = 5;
            if (a[i] == 'X' || a[i] == 'x') rtn[i] = 10;
            if (a[i] == 'L' || a[i] == 'l') rtn[i] = 50;
            if (a[i] == 'C' || a[i] == 'c') rtn[i] = 100;
            if (a[i] == 'D' || a[i] == 'd') rtn[i] = 500;
            if (a[i] == 'M' || a[i] == 'm') rtn[i] = 1000;
        }
        return rtn;
    }
}
