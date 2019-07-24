#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> hws(1010);
vector<bool> visited(1010);

void dfs(int c)
{
    visited[c] = true;
    for (const auto &nc : hws[c]) {
        if (!visited[nc]) {
            dfs(nc);
        }
    }
}

void slove()
{
    int c, cnt;
    for (int i = 0; i < K; ++i) {
        fill(visited.begin(), visited.end(), false);
        cin >> c;
        visited[c] = true;
        cnt = 0;
        for (int j = 1; j <= N; ++j) {
            if (!visited[j]) {
                cnt++;
                dfs(j);
            }
        }
        cout << cnt-1 << endl;
    }
}

int main()
{
    cin >> N >> M >> K;
    int c1, c2;
    for (int i = 0; i < M; ++i) {
        cin >> c1 >> c2;
        hws[c1].push_back(c2);
        hws[c2].push_back(c1);
    }

    slove();

    return 0;
}
