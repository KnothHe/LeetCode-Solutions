#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int MAX_K = 1001;
vector<double> p1(MAX_K, 0);
vector<double> p2(MAX_K, 0);
vector<double> p(MAX_K*MAX_K, 0);

void slove()
{
    for (int i = 0; i < MAX_K; ++i) {
        for (int j = 0; j < MAX_K; ++j) {
            p[i+j] += p1[i]*p2[j];
        }
    }
    int nzc = 0;
    for (int i = 0; i < MAX_K*MAX_K; ++i) {
        if (p[i] != 0) ++nzc;
    }
    cout << nzc;
    for (int i = MAX_K*MAX_K-1; i >= 0; --i) {
        if (p[i] != 0) {
            cout << " " << i << " " << fixed << setprecision(1) << p[i];
        }
    }
    cout << endl;
}

int main()
{
    int K, N;
    double a;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> N >> a;
        p1[N] = a;
    }
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> N >> a;
        p2[N] = a;
    }

    slove();

    return 0;
}
