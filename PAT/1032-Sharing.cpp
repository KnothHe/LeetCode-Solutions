#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int MAX_N = 100005;
struct Node {
    int next;
    bool flag = false;
};
vector<Node> nodes(MAX_N);
int main() {
    int a1, a2, n;
    cin >> a1 >> a2 >> n;
    for (int i = 0; i < n; i++) {
        int add, next;
        char data;
        cin >> add >> data >> next;
        nodes[add].next = next;
    }
    for (int i = a1; i != -1; i = nodes[i].next) {
        nodes[i].flag = true;
    }
    int res = -1;
    for (int i = a2; i != -1; i = nodes[i].next) {
        if (nodes[i].flag) {
            res = i; break;
        }
    }
    if (res == -1) printf("-1");
    else printf("%05d", res);
    return 0;
}
