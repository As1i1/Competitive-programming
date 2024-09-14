//
// Created by aas1i1 on 4/9/24.
//

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

using namespace std;
typedef long long ll;
typedef long double ld;

#define int ll
constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;

void karatsuba(const int *a, const int *b, int *c, int n) {
    if (n <= 64) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                c[i + j] = (c[i + j] + (a[i] * b[j]) % MOD) % MOD;
    } else {
        int k = n / 2;
        int l[k], r[k];
        int t[n];
        for (int i = 0; i < n; ++i) {
            t[i] = 0;
        }
        for (int i = 0; i < k; i++) {
            l[i] = (a[i] + a[k + i]) % MOD;
            r[i] = (b[i] + b[k + i]) % MOD;
        }
        karatsuba(l, r, t, k); // считает t
        karatsuba(a, b, c, k); // считает p1
        karatsuba(a + k, b + k, c + n, k); // считает p2
        int *t1 = t, *t2 = t + k;
        int *s1 = c, *s2 = c + k, *s3 = c + 2 * k, *s4 = c + 3 * k;
        for (int i = 0; i < k; i++) {
            int c1 = ((((s2[i] + t1[i]) % MOD - s1[i] + MOD) % MOD) - s3[i] + MOD) % MOD;
            int c2 = ((((s3[i] + t2[i]) % MOD - s2[i] + MOD) % MOD) - s4[i] + MOD) % MOD;
            c[k + i] = c1;
            c[n + i] = c2;
        }
    }
}


struct GF {
    static const int div_count = 1000;
    vector<ll> pf;

    GF(const vector<ll>& pf_) : pf(pf_) {
        remove_zeros();
    }

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
    vector<ll> a_tmp(a.pf);
    vector<ll> b_tmp(b.pf);
    for (int i = a_tmp.size(); i < max(a_tmp.size(), b_tmp.size()); ++i) {
        a_tmp.push_back(0);
    }
    for (int i = b_tmp.size(); i < max(a_tmp.size(), b_tmp.size()); ++i) {
        b_tmp.push_back(0);
    }
    vector<ll> res(a_tmp.size() * b_tmp.size() + 10, 0);
    karatsuba(a_tmp.data(), b_tmp.data(), res.data(), a_tmp.size());
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

ll binpow(ll a, int n) {
    if (a == 0) return 0;
    if (n == 0 || a == 1) return 1;
    if (n == 1) return a;
    ll d = binpow(a, n / 2);
    return n % 2 == 1 ? ((d * d) % MOD * a) % MOD : (d * d) % MOD;
}

void calc_and_print(vector<GF> &pf, int m, vector<ll> &coefs) {
    GF sum({pf[0].pf[0] * coefs[0]});
    for (int i = 1; i < m; ++i) {
        sum = sum + pf[i] * GF({coefs[i]});
    }
    for (int i = 1; i < m; ++i) {
        cout << sum.pf[i] % MOD << " ";
    }
    cout << "\n";
}

void solve() {
    int k, m;
    cin >> k >> m;
    m++;
    vector<ll> c(m + 1);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        c[x]++;
    }
    GF B(c);
    vector<GF> gfs(1, GF({1}));
    for (int i = 0; i < m; ++i) {
        GF tmp = GF(gfs.back()) * B;
        if (tmp.pf.size() > m) {
            gfs.emplace_back(vector<ll>(tmp.pf.begin(), tmp.pf.begin() + m + 1));
        } else {
            gfs.emplace_back(vector<ll>(tmp.pf.begin(), tmp.pf.end()));
        }
    }
    vector<ll> Catalans_number = {1};
    for (int i = 1; i <= m; ++i) {
        ll tmp = (Catalans_number[i - 1] * 2 * (2 * i - 1)) % MOD;
        tmp = (binpow(i + 1, MOD - 2) * tmp) % MOD;
        Catalans_number.push_back(tmp);
    }
    calc_and_print(gfs, m, Catalans_number);
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


