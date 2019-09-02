class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        queue<char> charQue;
        set<char> charSet;
        for (int i = 0; i < s.length(); i++) {
            if (charSet.find(s[i]) != charSet.cend()) {
                char ch = charQue.front();
                while (ch != s[i]) {
                    charQue.pop();
                    charSet.erase(charSet.find(ch));
                    ch = charQue.front();
                }
                charQue.pop();
                charSet.erase(charSet.find(ch));
            }
            charSet.insert(s[i]);
            charQue.push(s[i]);
            if (charSet.size() > maxlen) {
                maxlen = charSet.size();
            }
        }
        return maxlen;
    }
};
