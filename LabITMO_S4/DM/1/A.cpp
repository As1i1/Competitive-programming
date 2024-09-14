//
// Created by aas1i1 on 3/16/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 998'244'353, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

struct GF {
    static const int div_count = 1000;
    vector<int> pf;

    GF(const vector<int>& pf_) : pf(pf_) {}

    void remove_zeros() {
        while(pf.size() > 1) {
            if (pf.back() == 0) {
                pf.pop_back();
            } else {
                break;
            }
        }
    }

    friend GF operator*(GF& a, GF& b);
    friend GF operator+(GF& a, GF& b);
    friend GF operator/(GF& a, GF& b);
};

GF operator+(GF &a, GF &b) {
    vector<int> res(max(a.pf.size(), b.pf.size()), 0);
    for (int i = 0; i < res.size(); ++i) {
        int cur = 0;
        cur = (cur + (i >= a.pf.size() ? 0 : a.pf[i])) % MOD;
        cur = (cur + (i >= b.pf.size() ? 0 : b.pf[i])) % MOD;
        res[i] = cur;
    }
    GF resGF = res;
    resGF.remove_zeros();
    return resGF;
}

GF operator*(GF &a, GF &b) {
    vector<int> res(a.pf.size() * b.pf.size(), 0);
    for (size_t n = 0; n < res.size(); ++n) {
        ll cur = 0;
        for (int i = 0; i < min(n + 1, a.pf.size()); ++i) {
            if (n - i >= b.pf.size()) continue;
            cur = ((b.pf[n - i] * a.pf[i]) % MOD + cur) % MOD;
        }
        res[n] = cur;
    }
    GF resGF = res;
    resGF.remove_zeros();
    return resGF;
}

GF operator/(GF &a, GF &b) {
    vector<int> res(GF::div_count, 0);
    for (size_t n = 0; n < GF::div_count; ++n) {
        ll cur = n >= a.pf.size() ? 0 : a.pf[n];
        for (size_t i = 0; i < n; ++i) {
            if (b.pf.size() <= n - i) continue;
            cur = (cur - (res[i] * 1ll * b.pf[n - i]) % MOD + MOD) % MOD;
        }
        res[n] = cur;
    }
    GF resGF = res;
    return resGF;
}


void print(const GF& g) {
    if (g.pf.size() == 1 && g.pf[0] == 0) {
        cout << "0\n0\n";
    } else {
        cout << g.pf.size() - 1 << "\n";
        for (auto c: g.pf) {
            cout << c << " ";
        }
        cout << "\n";
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> P(n + 1), Q(m + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> P[i];
    }
    for (int i = 0; i <= m; ++i) {
        cin >> Q[i];
    }
    GF PGF(P), QGF(Q);
    GF div = PGF / QGF;
    print(PGF + QGF);
    print(PGF * QGF);
    for (auto c: div.pf) {
        cout << c << " ";
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


