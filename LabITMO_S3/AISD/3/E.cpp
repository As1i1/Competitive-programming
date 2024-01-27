//
// Created by Dubinin Dmitrii on 12/18/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

set<ll> fact(int n) {
    set<ll> res;
    ll i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            res.insert(i);
            res.insert(n / i);
        }
        i++;
    }
    return res;
}


void solve() {
    string s;
    cin >> s;
    if (string(s.size(), s[0]) == s) {
        cout << 1;
        return;
    }
    int n = s.size();
    set<ll> divs = fact(n);
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < s.size(); ++i) {
        z[i] = max(0, min(r - i, z[i - l]));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    for (ll del: divs) {
        bool ans = true;
        for (int i = del; i < n; i += del) {
            if (z[i] < del) {
                ans = false;
                break;
            }
        }
        if (ans) {
            cout << del;
            return;
        }
    }
    cout << s.size();
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
