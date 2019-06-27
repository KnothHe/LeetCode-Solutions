#include <iostream>
#include <string>
using namespace std;
inline int charToInt(char c) {
    return c - '0';
}
inline char intToChar(int n) {
    return n + '0';
}
string revStr(string input) {
    string res;
    for (int i = input.size() - 1; i >= 0; i--) {
        res += input[i];
    }
    return res;
}
string addStr(string n1, string n2) {
    string res;
    int carry = 0;
    int len1 = n1.size();
    int len2 = n2.size();
    for (int i1 = len1 - 1, i2 = len2 - 1; i1 >= 0 || i2 >= 0; ) {
        int a1 = i1 >= 0 ? charToInt(n1[i1]) : 0;
        int a2 = i2 >= 0 ? charToInt(n2[i2]) : 0;
        int a = a1 + a2 + carry;
        res = intToChar(a % 10) + res; 
        carry = a / 10;
        i1--; i2--;
    }
    if (carry != 0) {
        res = intToChar(carry) + res;
    }
    return res;
}
bool isPaild(string n) {
    for (int i = 0; i < n.size() / 2; i++) {
        if (n[i] != n[n.size() - i - 1])
            return false;
    }
    return true;
}
int main() {
    int step, K;
    string num;
    cin >> num >> K;
    for (step = 0; step < K; step++) {
        if (isPaild(num)) {
            cout << num << '\n' << step << endl;
            return 0;
        }
        num = addStr(num, revStr(num));
    }
    cout << num << '\n' << step << endl;
    return 0;
}

