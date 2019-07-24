#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, C1, C2;
vector<int> R;
vector<vector<int>> e;
const int INF = (1<<20);

void slove()
{
    vector<int> diffr(N, 0);
    vector<int> dist(N, INF);
    vector<int> nums(N, 0);
    vector<bool> visited(N, false);
    dist[C1] = 0;
    nums[C1] = R[C1];
    diffr[C1] = 1;

    while (true) {
        int v = -1;
        for (int u = 0; u < N; ++u) {
            if (!visited[u] && (v == -1 || dist[u] < dist[v])) {
                v = u;
            }
        }

        if (v == -1) break;
        visited[v] = true;
        
        for (int u = 0; u < N; ++u) {
            if (dist[v] + e[u][v] < dist[u]) {
                dist[u] = dist[v] + e[u][v];
                diffr[u] = diffr[v];
                nums[u] = nums[v] + R[u];
            } else if (dist[v] + e[u][v] == dist[u]) {
                diffr[u] = diffr[v] + diffr[u];
                if (nums[v] + R[u] > nums[u]) {
                    nums[u] = nums[v] + R[u];
                }
            }
        }
    }

    cout << diffr[C2] << " " << nums[C2] << endl;
}


int main()
{
    cin >> N >> M >> C1 >> C2;

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        R.push_back(n);
    }

    e.resize(N, vector<int>(N, INF));
    for (int i = 0; i < M; ++i) {
        int c1, c2, w;
        cin >> c1 >> c2 >> w;
        e[c1][c2] = w;
        e[c2][c1] = w;
    }

    slove();

    return 0;
}
