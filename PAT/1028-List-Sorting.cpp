#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Record {
    string id, name, score;
} record;
int N, C;
int main() {
    cin >> N >> C;
    vector<Record> records(N);
    for (int i = 0; i < N; i++) {
        cin >> record.id >> record.name >> record.score;
        records[i] = record;
    }
    switch (C) {
        case 1 : sort(records.begin(), records.end(), [](auto &lhs, auto &rhs) {
                         return lhs.id < rhs.id;
                         });
                 break;
        case 2 : sort(records.begin(), records.end(), [](auto &lhs, auto &rhs) {
                         return lhs.name != rhs.name ? lhs.name <= rhs.name :
                            lhs.id < rhs.id; 
                         });
                 break;
        case 3 : sort(records.begin(), records.end(), [](auto &lhs, auto &rhs) {
                         return lhs.score != rhs.score ? lhs.score <= rhs.score :
                            lhs.id < rhs.id;
                         });
                 break;
        default : break;
    }
    for (auto &r : records) {
        cout << r.id << " " << r.name << " " << r.score << endl;
    }
    return 0;
}
