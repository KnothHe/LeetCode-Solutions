/*
 * Reference:
 *  https://www.liuchuo.net/archives/2265
 *
 * Use Bit Index Tree
 *
 * Still can't understand BIT.
 */
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
const int max_n = 100010;
vector<int> c(max_n);
stack<int> s;
int lowbit(int x) { return x & (-x); }
void update(int x, int v) {
    for (int i = x; i < max_n; i += lowbit(i)) c[i] += v;
}
int getsum(int x) {
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) { sum += c[i]; }
    return sum;
}
void PeekMedian() {
    int left = 1, right = max_n, mid, k = (s.size() + 1) / 2;
    while (left < right) {
        mid = (left + right) / 2;
        if (getsum(mid) >= k) { right = mid; }
        else { left = mid + 1; }
    }
    cout << left << endl;
}
int main() {
    int n, temp;
    string op;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;
        switch(op[1]) {
            case 'u' :
                cin >> temp;
                s.push(temp);
                update(temp, 1);
                break;
            case 'o' :
                if (s.empty()) {
                    cout << "Invalid\n";
                } else {
                    update(s.top(), -1);
                    cout << s.top() << "\n";
                    s.pop();
                }
                break;
            default :
                if (s.empty()) {
                    cout << "Invalid\n";
                } else {
                    PeekMedian();
                }
        }
    }
    return 0;
}

