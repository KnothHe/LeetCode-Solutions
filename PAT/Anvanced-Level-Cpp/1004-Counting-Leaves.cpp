#include <iostream>
#include <vector>

using namespace std;

int maxdepth = -1;
const int MAX_N = 105;
vector<int> level(MAX_N, 0);
vector<vector<int>> nodes(MAX_N);

void dfs(int index, int depth)
{
    if (nodes[index].size() == 0) {
        level[depth]++;
        maxdepth = max(maxdepth, depth);
        return;
    }

    for (int i = 0; i < nodes[index].size(); ++i) {
        dfs(nodes[index][i], depth+1);
    }
}

void slove()
{
    dfs(1, 0);

    for (int i = 0; i <= maxdepth; ++i) {
        if (i != 0) cout << " ";
        cout << level[i];
    }
    cout << endl;
}

int main()
{
    int N, M, id, k, u;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            cin >> u;
            nodes[id].push_back(u);
        }
    }

    slove();

    return 0;
}
