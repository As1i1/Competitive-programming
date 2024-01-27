//
// Created by Dubinin Dmitrii on 12/17/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pref(n);
    pref[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        int k = pref[i - 1];
        while (k > 0 && s[i] != s[k]) {
            k = pref[k - 1];
        }
        if (s[i] == s[k]) {
            k++;
        }
        pref[i] = k;
    }
    for (auto&& i: pref) {
        cout << i << " ";
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
