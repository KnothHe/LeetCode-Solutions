#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

vector<int> nums;

void slove()
{
    vector<int> fis(nums.size());
    vector<int> sums(nums.size());
    fis[0] = 0;
    sums[0] = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        if (sums[i-1] >= 0) {
            sums[i] = sums[i-1] + nums[i];
            fis[i] = fis[i-1];
        } else {
            sums[i] = nums[i];
            fis[i] = i;
        }
    }

    int maxIdx = distance(sums.begin(), max_element(sums.begin(), sums.end()));
    if (sums[maxIdx] >= 0) {
        cout << sums[maxIdx] << " " << nums[fis[maxIdx]] << " " << nums[maxIdx] << endl;
    } else {
        cout << 0 << " " << nums.front() << " " << nums.back() << endl;
    }
}

void slove2()
{
    int maxSum = numeric_limits<int>::min();
    int sum = 0;
    int fi = 0;
    int rfi = 0, rla = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (sum >= 0) {
            sum += nums[i];
        } else {
            sum = nums[i];
            fi = i;
        }
        if (sum > maxSum) {
            maxSum = sum;
            rfi = fi;
            rla = i;
        }
    }

    if (maxSum >= 0) {
        cout << maxSum << " " << nums[rfi] << " " << nums[rla] << endl;
    } else {
        cout << 0 << " " << nums.front() << " " << nums.back() << endl;
    }
}

int main()
{
    int K, n;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> n;
        nums.push_back(n);
    }

    slove2();

    return 0;
}
