#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> ids;
vector<string> sis;
vector<string> sos;


void slove()
{
    cout << ids[distance(sis.begin(), min_element(sis.begin(), sis.end()))] << " ";
    cout << ids[distance(sos.begin(), max_element(sos.begin(), sos.end()))] << endl;
}

int main()
{
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string id, si, so;
        cin >> id >> si >> so;
        ids.push_back(id);
        sis.push_back(si);
        sos.push_back(so);
    }

    slove();

    return 0;
}
