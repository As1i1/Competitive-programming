//
// Created by aas1i1 on 4/7/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define int ll
constexpr int INF = 1e7, MOD = 1e7 + 7, Q = 38;
constexpr ld eps = 1e-7;
constexpr ll ll_INF = 1e18;
//mt19939 gen;

struct GF {
    static const int div_count = 7;
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
    vector<ll> res(min<int>(7, max(a.pf.size(), b.pf.size())), 0);
    for (int i = 0; i < res.size(); ++i) {
        ll cur = 0;
        cur = cur + (i >= a.pf.size() ? 0 : a.pf[i]);
        cur = cur + (i >= b.pf.size() ? 0 : b.pf[i]);
        res[i] = cur;
    }
    GF resGF = res;
    resGF.remove_zeros();
    return resGF;
}

GF operator*(const GF &a, const GF &b) {
    vector<ll> res(min<int>(7, a.pf.size() + b.pf.size() + 2), 0);
    for (size_t n = 0; n < res.size(); ++n) {
        ll cur = 0;
        for (int i = 0; i < min(n + 1, a.pf.size()); ++i) {
            if (n - i >= b.pf.size()) continue;
            cur = b.pf[n - i] * a.pf[i] + cur;
        }
        res[n] = cur;
    }
    GF resGF = res;
    resGF.remove_zeros();
    return resGF;
}

GF operator*(GF &a, GF &b) {
    vector<ll> res(min<int>(7, a.pf.size() + b.pf.size() + 2), 0);
    for (size_t n = 0; n < res.size(); ++n) {
        ll cur = 0;
        for (int i = 0; i < min(n + 1, a.pf.size()); ++i) {
            if (n - i >= b.pf.size()) continue;
            cur = b.pf[n - i] * a.pf[i] + cur;
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
            cur = cur - res[i] * 1ll * b.pf[n - i];
        }
        res[n] = cur;
    }
    GF resGF = res;
    return resGF;
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

GF binpow(GF& g, int n) {
    if (n == 0) {
        return GF({1});
    }
    if (n == 1) {
        return g;
    }
    GF d = binpow(g, n / 2);
    return n % 2 == 0 ? d * d : d * d * g;
}

GF bimon(int t, int p) {
    if (p == 0) {
        return vector<ll>{1};
    }
    GF pol(vector<ll>(t + 1, 0));
    pol.pf[0] = 1;
    pol.pf.back() = -1;
//    GF res = pol;
//    for (int i = 1; i < p; ++i) {
//        res = GF(res) * pol;
//    }
    return binpow(pol, p);
}

GF list_(const GF& a) {
    vector<ll> pf(7, 0);
    for (int i = 0; i < min<int>(a.pf.size(), 7); ++i) {
        pf[i] = -a.pf[i];
    }
    pf[0] = 1;
    GF res = GF(pf);
    res.remove_zeros();
    return GF({1}) / res;
}

GF set_(const GF& a) {
    vector<GF> polys;
    for (int i = 1; i < min<int>(7, a.pf.size()); ++i) {
        polys.push_back(GF({1}) / bimon(i, a.pf[i]));
    }
    return mul_poly(polys);
}

GF pair_(const GF& a, const GF& b) {
    return a * b;
}

GF calc(string s) {
//    cout << s << "\n";
    if (s[0] == 'B') {
        return GF({0, 1});
    }
    if (s[0] == 'L') {
        return list_(calc(s.substr(2, s.size() - 3)));
    }
    if (s[0] == 'S') {
        return set_(calc(s.substr(2 , s.size() - 3)));
    }
    int bal = 1;
    int middle = -1;
    for (int i = 2; i < s.size(); ++i) {
        if (s[i] == ')') {
            bal--;
        }
        if (s[i] == '(') {
            bal++;
        }
        if (bal == 1 && s[i] == ',') {
            middle = i - 2;
            break;
        }
    }
    return pair_(calc(s.substr(2, middle)), calc(s.substr(middle + 3, s.size() - middle - 4)));
}

void solve() {
    string s;
    getline(cin, s);
    GF res = calc(s);
    for (int i = 0; i < 7; ++i) {
        if (i >= res.pf.size()) {
            cout << "0 ";
        } else {
            cout << res.pf[i] << " ";
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
//	cout.precision(7);
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


