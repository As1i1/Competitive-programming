//
// Created by aas1i1 on 4/9/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define int ll
constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;

struct GF {
    static const int div_count = 10000;
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


struct fraction {
    ll x;
    ll y;

    fraction(ll x, ll y) : x(x), y(y) {}

    fraction(int x) : x(x), y(1) {}
};

fraction operator*(const fraction& a, const fraction& b) {
    ll x_ = a.x * b.x;
    ll y_ = a.y * b.y;
    ll gc = std::gcd(abs(x_), y_);
    return {x_ / gc, y_ / gc};
}

fraction operator*(const fraction& a, ll b) {
    ll x_ = a.x * b;
    ll gc = std::gcd(abs(x_), a.y);
    return {x_ / gc, a.y / gc};
}

fraction operator+(const fraction& a, const fraction& b) {
    ll x_ = a.x * b.y + a.y * b.x;
    ll y_ = a.y * b.y;
    ll gc = std::gcd(abs(x_), y_);
    return {x_ / gc, y_ / gc};
}

fraction operator/(const fraction& a, const fraction& b) {
    fraction tmp = {b.y * (b.x < 0 ? -1 : 1), abs(b.x)};
    return a * tmp;
}

ll fact(int k) {
    ll p = 1;
    for (int i = 1; i <= k; ++i) {
        p *= i;
    }
    return p;
}

GF bimon(ll free_coef, ll t_coef, int p) {
    if (p == 0) {
        return vector<ll>{1};
    }
    GF res({free_coef, -t_coef});
    for (int i = 1; i < p; ++i) {
        res = GF(res) * GF({free_coef, -t_coef});
    }
    return res;
}

vector<fraction> calc_C(vector<GF>& v, vector<int>& expected) {
    vector<fraction> result;
    for (int i = 0; i < v.size(); ++i) {
        fraction cur_sum{0, 1};
        for (int j = 0; j < i; ++j) {
            cur_sum = cur_sum + result[j] * v[j].pf[v[j].pf.size() - (i - j) - 1]; // TODO
        }
        fraction c = expected[expected.size() - i - 1];
        c = c + (cur_sum * -1);
        c = c / fraction{v[i].pf[v[i].pf.size() - 1], 1};
        result.push_back(c);
    }
    return result;
}

GF mul_poly(const vector<GF>& poly) {
    if (poly.empty()) {
        return GF({1});
    }
    GF res = poly[0];
    for (int i = 1; i < poly.size(); ++i) {
        res = res * poly[i];
    }
    return res;
}

void solve() {
    int r, k;
    cin >> r >> k;
    vector<int> P(k + 1);
    for (int i = 0; i <= k; ++i) {
        cin >> P[i];
    }
    vector<GF> gfs;
    for (int i = k; i >= 0; i--) {
        gfs.push_back(bimon(1, r, i));
    }
    auto coefs = calc_C(gfs, P);
    vector<GF> gf;
    vector<GF> equla;
    for (int i = 0; i <= k; ++i) {
        equla.emplace_back(mul_poly(gf));
        gf.emplace_back(GF({i + 1, 1}));
    }
    for (int i = 0; i <= k; ++i) {
        fraction res = {0, 1};
        for (int j = i; j <= k; ++j) {;
            res = res + coefs[j] * equla[j].pf[i] * fraction{1, fact(j)};
        }
        cout << res.x << "/" << res.y << " ";
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


