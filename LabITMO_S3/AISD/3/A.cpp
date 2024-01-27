//
// Created by Dubinin Dmitrii on 12/17/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve() {
    string s;
    cin >> s;
    vector<ll> hash(s.size() + 1);
    vector<ll> st(s.size() + 1);
    hash[s.size()] = 0;
    ll p = 1;
    st[s.size()] = p;
    for (int i = s.size() - 1; i >= 0; i--) {
        hash[i] = (hash[i + 1] + s[i] * p) % MOD;
        p = (p * Q) % MOD;
        st[i] = p;
    }
    int n; cin >> n;
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;x2--;
        if (x1 - y1 != x2 - y2) {
            cout << "No\n";
            continue;
        }
        ll h1 = (hash[x1] - hash[y1] + MOD) % MOD;
        ll h2 = (hash[x2] - hash[y2] + MOD) % MOD;
        if (y2 < y1) {
            swap(h1, h2);
            swap(y1, y2);
        }
        if ((h2 * st[s.size() - (y2 - y1)]) % MOD == h1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
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
