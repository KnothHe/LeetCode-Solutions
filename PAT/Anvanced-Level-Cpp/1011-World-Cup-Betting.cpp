#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const vector<char> chs = { 'W', 'T', 'L' };
vector<vector<double>> games;

void slove()
{
    double prod = 1;
    for (int i = 0; i < 3; ++i) {
        int maxIdx = distance(games[i].begin(), 
                max_element(games[i].begin(), games[i].end()));
        cout << chs[maxIdx] << " ";
        prod *= games[i][maxIdx];
    }
    cout << fixed << setprecision(2) << (prod*0.65-1)*2 << endl;
}

int main()
{
    double w, t, l;
    for (int i = 0; i < 3; ++i) {
        cin >> w >> t >> l;
        games.push_back({w, t, l});
    }

    slove();

    return 0;
}
