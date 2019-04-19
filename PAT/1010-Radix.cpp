#include <algorithm>
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

long long tag, R;
string N1, N2;

long long convert(string s, long long radix)
{
    long long res = 0, n;
    for (const auto &c : s) {
        n = isdigit(c) ? c-'0' : c-'a'+10;
        res = res*radix + n;
    }
    return res;
}

long long find_radix(string n, long long num)
{
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it-'0' : it-'a'+10)+1;
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low+high)/2;
        long long t = convert(n, mid);
        if (t < 0 || t > num) high = mid-1;
        else if (t == num) return mid;
        else low = mid+1;
    }
    return -1;
}

void slove()
{
    if (tag == 2) {
        swap(N1, N2);
    }
    long long res = find_radix(N2, convert(N1, R));
    if (res == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << res << endl;
    }
}

int main()
{
    cin >> N1 >> N2 >> tag >> R;
    
    slove();

    return 0;
}
