#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<char, char> replace({
        {'1', '@'},
        {'0', '%'},
        {'l', 'L'},
        {'O', 'o'}
        });
struct Account {
    string name, passwd;
} account;
vector<Account> ans;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> account.name >> account.passwd;
        bool modified = false;
        for (auto &c : account.passwd) {
            if (replace.find(c) != replace.end()) {
                modified = true;
                c = replace[c];
            }
        }
        if (modified) {
            ans.push_back(account);
        }
    }
    if (ans.size() == 0) {
        if (n == 1) {
            cout << "There is 1 account and no account is modified" << endl;
        } else {
            cout << "There are " << n << " accounts and no account is modified" << endl;
        }
    } else {
        cout << ans.size() << endl;
        for (auto ac : ans) {
            cout << ac.name << " " << ac.passwd << endl;
        }
    }
    return 0;
}
