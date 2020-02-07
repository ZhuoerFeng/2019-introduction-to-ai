#include <bits/stdc++.h>
using namespace std;

map<int, int> freq_1;
map<tuple<int, int>, int> freq_2;
map<tuple<int, int, int>, int> freq_3;

int cur[2333333], pos;

int main() {
    ios::sync_with_stdio(false);
    string s;
    while (getline(cin, s)) {
        pos = 0;
        for (int i = 0; i < len; ++i) {
            if (i + 1 >= len) break;
            if (charid.count(s[i])) {
                int id = charid[s[i]];
                cur[++pos] = id;
                upd();
                ++i;
            }
        }
    }
    return 0;
}
