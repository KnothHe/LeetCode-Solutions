#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Mouse {
    int weight, rank;
};
int main() {
    int np, ng, o;
    cin >> np >> ng;
    vector<Mouse> misc(np);
    queue<int> que;
    for (int i = 0; i < np; i++) cin >> misc[i].weight;
    for (int i = 0; i < np; i++) {
        cin >> o;
        que.push(o);
    }
    while (que.size() > 1) {
        int len = que.size();
        int group = len % ng == 0 ? len / ng : len / ng + 1;
        int max_val = -1, max_ele, cnt = 0;
        for (int i = 0; i < len; i++) {
            int temp = que.front();
            que.pop();
            cnt++;
            misc[temp].rank = group + 1;
            if (misc[temp].weight > max_val) {
                max_val = misc[temp].weight;
                max_ele = temp;
            }
            if (cnt == ng || i == len - 1) {
                cnt = 0;
                max_val = -1;
                que.push(max_ele);
            }
        }
    }
    misc[que.front()].rank = 1;
    cout << misc[0].rank;
    for (int i = 1; i < misc.size(); i++) {
        cout << " " << misc[i].rank;
    }
    return 0;
}
