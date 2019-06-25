#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <utility> // pair
#include <numeric> // accumulate
#include <algorithm> // sort
#include <cstdio>

using namespace std;
vector<int> rates(24);
int one_day_rate;

vector<int> split_to_ints(string s)
{
    vector<int> ints;
    string delimiter = ":";
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        ints.push_back(stoi(token));
        s.erase(0, pos + delimiter.size());
    }
    ints.push_back(stoi(s));
    return ints;
}

pair<int, double> count_bill(string t1, string t2) 
{
    vector<int> v1 = split_to_ints(t1);
    vector<int> v2 = split_to_ints(t2);
    long bill = 0;
    int time = 0;
    int d1 = v1[1], d2 = v2[1], h1 = v1[2], h2 = v2[2], m1 = v1[3], m2 = v2[3];
    if (d1 == d2) {
        if (h2 == h1) {
            bill += (m2 - m1) * rates[h1];
            time += m2 - m1;
        } else {
            bill += (60 - m1) * rates[h1];
            bill += m2 * rates[h2];
            time += 60 - m1;
            time += m2;
            for (int h = h1 + 1; h < h2; h++) {
                bill += 60 * rates[h];
                time += 60;
            }
        }
    } else {
        bill += (60 - m1) * rates[h1];
        bill += m2 * rates[h2];
        time += 60 - m1;
        time += m2;
        for (int h = h1 + 1; h < 24; h++) {
            bill += 60 * rates[h];
            time += 60;
        }
        for (int h = 0; h < h2; h++) {
            bill += 60 * rates[h];
            time += 60;
        }
        for (int d = d1 + 1; d < d2; d++) {
            bill += 60 * one_day_rate;
            time += 60 * 24;
        }
    }
    return { time, bill / 100.0 };
}

int main()
{
    int N; 
    for (int i = 0; i < 24; i++) {
        int rate;
        cin >> rate;
        rates[i] = rate;
    }
    one_day_rate = accumulate(rates.begin(), rates.end(), 0);
    cin >> N;
    // name, time, status(true : on-line, false : off-line)
    map<string, vector<pair<string, bool>>> res_map;
    string time;
    for (int i = 0; i < N; i++) {
        string name, status;
        cin >> name >> time >> status;
        res_map[name].push_back(make_pair(time, 
                    (status == "on-line" ? true : false)));
    }
    string month = time.substr(0, 2);
    for (auto &iter : res_map) {
        sort(iter.second.begin(), iter.second.end(), 
                [](auto &left, auto &right) { 
                return left.first < right.first; 
                });
        double total_bill = 0;
        bool need_print = false;
        for (auto it = iter.second.begin(); it < iter.second.end(); it++) {
            if (it->second && it + 1 < iter.second.end() && !(it + 1)->second) {
                need_print = true;
                break;
            }
        }
        if (need_print) {
            cout << iter.first << " " << month << "\n";
            for (auto it = iter.second.begin(); it < iter.second.end(); ) {
                if (it->second && it + 1 < iter.second.end() && !(it + 1)->second) {
                    auto p = count_bill(it->first, (it + 1)->first);
                    cout << it->first.substr(3, it->first.size()) << " ";
                    it++;
                    cout << it->first.substr(3, it->first.size()) << " ";
                    printf("%d $%.2lf\n", p.first, p.second);
                    total_bill += p.second;
                }
                it++;
            }
            printf("Total amount: $%.2lf\n", total_bill);
        }
    }
    return 0;
}

