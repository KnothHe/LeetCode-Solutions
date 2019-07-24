#include <iostream>
#include <vector>

using namespace std;

vector<int> input;

void slove()
{
    int c = 0; 
    int sum = 0;
    for (const auto &i : input) {
        int o = i - c;
        if (o > 0) {
            sum += o*6;
        } else {
            sum += (-o)*4;
        }
        c = i;
    }
    sum += input.size() * 5;

    cout << sum << endl;
}

int main()
{
    int N, n;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> n;
        input.push_back(n);
    }

    slove();

    return 0;
}
