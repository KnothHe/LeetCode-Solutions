#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    int best, id;
    vector<int> score, rank;

    Node (int i, int c, int m, int e) :
        id(i), score( { static_cast<int>((c+m+e)/3.0), c, m, e } ), rank(4) {  }
};

class Cmp {
private:
    int flag;

public:
    Cmp(int f) : flag(f) {  }
    bool operator()(Node *n1, Node *n2) {
        return n1->score[flag] > n2->score[flag];
    }
};

int N, M;
vector<Node*> stu;
unordered_map<int, int> exist;

void slove()
{
    for (int flag = 0; flag <= 3; ++flag) {
        sort(stu.begin(), stu.end(), Cmp(flag));
        stu[0]->rank[flag] = 1;
        for (size_t i = 1; i < stu.size(); ++i) {
            stu[i]->rank[flag] = i+1;
            if (stu[i]->score[flag] == stu[i-1]->score[flag]) {
                stu[i]->rank[flag] = stu[i-1]->rank[flag];
            }
        }
    }

    for (size_t i = 0; i < stu.size(); ++i) {
        exist[stu[i]->id] = i;
        stu[i]->best = distance(stu[i]->rank.begin(), 
                min_element(stu[i]->rank.begin(), stu[i]->rank.end()));
    }

    const string chs("ACME");
    int id, best;
    for (int i = 0; i < M; ++i) {
        cin >> id;
        if (exist.find(id) != exist.end()) {
            best = stu[exist[id]]->best;
            cout << stu[exist[id]]->rank[best] << " " << chs[best] << endl;
        } else {
            cout << "N/A" << endl;
        }
    }

    for (size_t i = 0; i < stu.size(); ++i) {
        delete stu[i];
    }
    stu.clear();
}

int main()
{
    cin >> N >> M;
    int id, c, m, e;
    for (int i = 0; i < N; ++i) {
        cin >> id >> c >> m >> e;
        stu.push_back(new Node(id, c, m, e));
    }

    slove();

    return 0;
}
