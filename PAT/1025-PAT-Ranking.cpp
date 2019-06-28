#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
struct Rank {
    int final_rank;
    int location_number;
    int local_rank;
};
bool cmp(const pair<string, int> &lhs, const pair<string, int> &rhs) {
    return (lhs.second != rhs.second) ? lhs.second > rhs.second :
        lhs.first < rhs.first;
}
int N, K;
vector<pair<string, int>> local_rank;
vector<pair<string, int>> final_rank;
unordered_map<string, Rank> pat_rank;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        local_rank.clear();
        for (int j = 0; j < K; j++) {
            int n;
            string user;
            cin >>  user >> n;
            pat_rank[user] = { -1, i + 1, -1 };
            local_rank.push_back(pair<string, int>(user, n));
            final_rank.push_back(pair<string, int>(user, n));
        }
        sort(local_rank.begin(), local_rank.end(), cmp);
        pat_rank[local_rank[0].first].local_rank = 1;
        for (int r = 1; r < local_rank.size(); r++) {
            if (local_rank[r].second == local_rank[r - 1].second) {
                pat_rank[local_rank[r].first].local_rank =
                    pat_rank[local_rank[r - 1].first].local_rank;
            } else {
                pat_rank[local_rank[r].first].local_rank = r + 1;
            }
        }
    }
    sort(final_rank.begin(), final_rank.end(), cmp);
    pat_rank[final_rank[0].first].final_rank = 1;
    for (int r = 1; r < final_rank.size(); r++) {
        if (final_rank[r].second == final_rank[r - 1].second) {
            pat_rank[final_rank[r].first].final_rank =
                pat_rank[final_rank[r - 1].first].final_rank;
        } else {
            pat_rank[final_rank[r].first].final_rank = r + 1;
        }
    }
    cout << final_rank.size() << '\n';
    for (const auto &p : final_rank) {
        string user(p.first);
        cout << user << " " << pat_rank[user].final_rank << " " <<
            pat_rank[user].location_number << " " << pat_rank[user].local_rank << '\n';
    }
    return 0;
}


