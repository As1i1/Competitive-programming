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
vector<ll> pow_q;
int mx = 0;

ll hash_to(ll s, ll e, ll level) {
    return (((s - e + MOD) % MOD) * pow_q[level]) % MOD;
}

vector<ll> get_hash(string s) {
    vector<ll> hash(s.size() + 1);
    hash[s.size()] = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        hash[i] = (hash[i + 1] + s[i] * pow_q[s.size() - i - 1]) % MOD;
    }
    return hash;
}


pair<bool, int> check(int k, vector<vector<ll>>& hashs) {
    map<ll, pair<int, int>> pos;
    for (int i = k; i < hashs[0].size(); ++i) {
        pos[hash_to(hashs[0][i - k], hashs[0][i], mx - (hashs[0].size() - i + k))] = {1, i - k};
    }
    for (int _i = 1; _i < hashs.size(); ++_i) {
        set<ll> used;
        for (int i = k; i < hashs[_i].size(); ++i) {
            ll h = hash_to(hashs[_i][i - k], hashs[_i][i], mx - (hashs[_i].size() - i + k));
            if (used.find(h) == used.end() && pos.find(h) != pos.end()) {
                pos[h].first++;
                used.insert(h);
            }
        }
    }
    for (auto&& [_, p]: pos) {
        if (p.first == hashs.size()) {
            return make_pair(true, p.second);
        }
    }
    return make_pair(false, -1);
}


void solve() {
    int n;
    cin >> n;
    int mn = INF;
    pow_q = vector<ll>(1e6 + 10);
    pow_q[0] = 1;
    for (int i = 1; i < 1e6 + 10; ++i) {
        pow_q[i] = (pow_q[i - 1] * Q) % MOD;
    }
    vector<string> strs(n);
    vector<vector<ll>> hashs(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
        mn = min(mn, (int)strs[i].size());
        mx = max(mx, (int)strs[i].size());
    }
    mn++;
    sort(strs.begin(), strs.end(), [&] (const string& a, const string& b) {return a.size() < b.size();});
    for (int i = 0; i < n; ++i) {
        hashs[i] = get_hash(strs[i]);
    }
    int l = 0, r = mn;
    while (r - l > 1) {
        int m = (r + l) / 2;
        auto res = check(m, hashs);
        if (res.first) {
            l = m;
        } else {
            r = m;
        }
    }
    pair<bool, int> p;
    if ((p = check(r, hashs)).first) {
        cout << strs[0].substr(p.second, r);
    } else {
        cout << strs[0].substr(check(l, hashs).second, l);
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
