#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

string s;
const vector<string> WORDS = { "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"};

void slove()
{
    int sum = 0;
    for (const auto &c : s) {
        sum += static_cast<int>(c - '0');
    }

    stack<int> st;
    if (sum == 0) {
        st.push(0);
    } else {
        while (sum > 0) {
            st.push(sum%10);
            sum /= 10;
        }
    }

    cout << WORDS[st.top()];
    st.pop();
    while (!st.empty()) {
        cout << " " << WORDS[st.top()];
        st.pop();
    }
    cout << endl;
}

int main()
{
    cin >> s;

    slove();

    return 0;
}
