//
// Created by aas1i1 on 3/16/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

//#define int ll
constexpr ll INF = 1e9, MOD = 998'244'353, Q = 38; // 998 244 353
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;

ll binpow(ll a, int n) {
    if (a == 0) return 0;
    if (n == 0 || a == 1) return 1;
    if (n == 1) return a;
    ll d = binpow(a, n / 2);
    return n % 2 == 1 ? ((d * d) % MOD * a) % MOD : (d * d) % MOD;
}

ll fact(int n) {
    ll res = 1;
    for (int i = 1; i <= n; ++i) {
        res = (res * i) % MOD;
    }
    return res;
}

struct GF {
    static const int div_count = 1000;
    vector<ll> pf;

    GF(const vector<ll> &pf_) : pf(pf_) {
        remove_zeros();
    }

    void remove_zeros() {}

    friend GF operator*(GF &a, GF &b);

    friend GF operator+(GF &a, GF &b);

    friend GF operator/(GF &a, GF &b);
};

GF operator+(const GF &a, const GF &b) {
    vector<ll> res(max(a.pf.size(), b.pf.size()), 0);
    for (int i = 0; i < res.size(); ++i) {
        ll cur = 0;
        cur = (cur + (i >= a.pf.size() ? 0 : a.pf[i])) % MOD;
        cur = (cur + (i >= b.pf.size() ? 0 : b.pf[i])) % MOD;
        res[i] = cur;
    }
    GF resGF = res;
    resGF.remove_zeros();
    return resGF;
}

GF operator*(const GF &a, const GF &b) {
    vector<ll> res(a.pf.size() * b.pf.size(), 0);
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

GF operator/(const GF &a, const GF &b) {
    vector<ll> res(GF::div_count, 0);
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

void calc_and_print(vector<GF> &pf, int m, vector<ll> &coefs) {
    GF sum({pf[0].pf[0] * coefs[0]});
    for (int i = 1; i < m; ++i) {
        sum = sum + pf[i] * GF({coefs[i]});
    }
    for (int i = 0; i < m; ++i) {
        cout << sum.pf[i] % MOD << " ";
    }
    cout << "\n";
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> pf(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        cin >> pf[i];
    }
    GF B(pf);
    vector<GF> gfs(1, GF({1}));
    for (int i = 0; i < m; ++i) {
        GF tmp = GF(gfs.back()) * B;
        if (tmp.pf.size() > m) {
            gfs.emplace_back(vector<ll>(tmp.pf.begin(), tmp.pf.begin() + m + 1));
        } else {
            gfs.emplace_back(vector<ll>(tmp.pf.begin(), tmp.pf.end()));
        }
    }
    vector<ll> coefs(m);
    coefs[0] = 1;
    for (int i = 1; i < m; ++i) {
        ll rev_f = binpow((((2 * i - 1) * fact(i)) % MOD * fact(i) % MOD) * binpow(4, i) % MOD, MOD - 2);
        ll tmp = ((rev_f * fact(2 * i)) % MOD * (i % 2 == 0 ? -1 : 1) + MOD) % MOD;
        coefs[i] = tmp;
    }
    calc_and_print(gfs, m, coefs);
    coefs.assign(m, 0);
    for (int i = 0; i < m; ++i) {
        ll rev_f = binpow(fact(i), MOD - 2);
        coefs[i] = rev_f;
    }
    calc_and_print(gfs, m, coefs);
    coefs.assign(m, 0);
    for (int i = 0; i < m; ++i) {
        ll rev_f = (binpow(i, MOD - 2) * (i % 2 == 0 ? -1 : 1) + MOD) % MOD;
        coefs[i] = rev_f;
    }
    calc_and_print(gfs, m, coefs);
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


