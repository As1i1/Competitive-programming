//
// Created by aas1i1 on 4/8/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;

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
        cur = cur + (i >= a.pf.size() ? 0 : a.pf[i]); // TODO % MOD
        cur = cur + (i >= b.pf.size() ? 0 : b.pf[i]); // TODO % MOD
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
            cur = b.pf[n - i] * a.pf[i] + cur; // TODO % MOD
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
            cur = cur - res[i] * 1ll * b.pf[n - i]; // TODO % MOD
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

ll fact(int k) {
    ll p = 1;
    for (int i = 1; i <= k; ++i) {
        p *= i;
    }
    return p;
}

vector<ll> mul_poly(const vector<GF>& poly) {
    if (poly.empty()) {
        return {1};
    }
    GF res = poly[0];
    for (int i = 1; i < poly.size(); ++i) {
        res = res * poly[i];
    }
    return res.pf;
}

GF bimon(ll free_coef, ll t_coef, int p) {
    if (p == 0) {
        return vector<ll>{1};
    }
    GF res({free_coef, t_coef});
    for (int i = 1; i < p; ++i) {
        res = GF(res) * GF({free_coef, t_coef});
    }
    return res;
}

GF calc_P(vector<ll> coefs, ll r) {
    GF res({coefs.back()});
    for (int i = coefs.size() - 2; i >= 0; i--) {
        res = res + bimon(1, -r, coefs.size() - i - 1) * GF({coefs[i]});
    }
    return res;
}

void solve() {
    ll r;
    cin >> r;
    int d;
    cin >> d;
    vector<ll> poly(d + 1);
    for (int i = 0; i <= d; ++i) {
        cin >> poly[i];
    }
    vector<vector<ll>> equla(d + 1);
    vector<GF> gf;
    for (int i = 0; i <= d; ++i) {
        equla[i] = mul_poly(gf);
        gf.emplace_back(GF({i + 1, 1}));
    }
    vector<ll> coefs(d + 1);
    for (int i = d; i >= 0; i--) {
        ll calc = 0;
        for (int j = d; j > i; j--) {
            calc += equla[j][i] * coefs[j] / fact(j);
        }
        coefs[i] = (poly[i] - calc) * fact(i);
    }
    print(calc_P(coefs, r));
    print(bimon(1, -r, d + 1));
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


