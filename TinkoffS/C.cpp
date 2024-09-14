//
// Created by aas1i1 on 4/2/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;


void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int sm = a + b + c + d;
    if (sm % 4 != 0) {
        cout << "-1";
        return;
    }
    map<int, int> mp;
    vector<int> v = {a, b, c, d};
    sort(v.begin(), v.end());
    mp[a]++;
    mp[b]++;
    mp[c]++;
    mp[d]++;
    int expected = sm / 4;
    if (mp.find(expected) == mp.end()) {
        if (v[2] < expected) {
            cout << "3";
        } else {
            cout << "2";
        }
    } else if (mp[expected] == 1) {
        cout << "2";
    } else if (mp[expected] == 2) {
        cout << "1";
    } else {
        cout << "0";
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


