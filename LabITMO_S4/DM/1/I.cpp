//
// Created by aas1i1 on 4/10/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr ll INF = 1e9, MOD = 104'857'601;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;

struct GF {
// static const int div_count = 1000;
    vector<ll> pf;

    GF(const vector<ll> &pf_) : pf(pf_) {}

    void remove_zeros() {
        while (pf.size() > 1) {
            if (pf.back() == 0) {
                pf.pop_back();
            } else {
                break;
            }
        }
    }

    friend GF operator*(GF &a, GF &b);

};

GF operator*(GF &a, GF &b) {
    vector<ll> res(a.pf.size() + b.pf.size() + 10, 0);
    for (size_t n = 0; n < res.size(); ++n) {
        ll cur = 0;
        for (int i = 0; i < min(n + 1, a.pf.size()); ++i) {
            if (n - i >= b.pf.size()) continue;
            cur = (((b.pf[n - i] * a.pf[i]) % MOD + MOD) % MOD + cur) % MOD;
        }
        res[n] = cur;
    }
    GF resGF = res;
    resGF.remove_zeros();
    return resGF;
}

GF mul_with_minus(GF &a, GF &b) {
    vector<ll> res(a.pf.size() + b.pf.size() + 10, 0);
    for (size_t n = 0; n < res.size(); ++n) {
        ll cur = 0;
        for (int i = 0; i < min(n + 1, a.pf.size()); ++i) {
            if (n - i >= b.pf.size()) continue;
            ll tmp = (b.pf[n - i] * ((n - i) % 2 == 1 ? -1 : 1) + MOD) % MOD;
            cur = (((tmp * a.pf[i]) % MOD + MOD) % MOD + cur) % MOD;
        }
        res[n] = cur;
    }
    GF resGF = res;
    resGF.remove_zeros();
    return resGF;
}

ll getNTH(ll n, GF P, GF Q) {
    while (n != 0) {
        P = mul_with_minus(P, Q);
        Q = mul_with_minus(Q, Q);
        vector<ll> new_c;
        for (int i = 0; i < Q.pf.size(); i += 2) {
            new_c.push_back(Q.pf[i]);
        }
        Q.pf = new_c;
        if (n % 2 == 0) {
            vector<ll> p_1(P.pf.size() / 2);
            for (int i = 0; i < P.pf.size(); i += 2) {
                p_1[i / 2] = P.pf[i];
            }
            P.pf = p_1;
            n /= 2;
        } else {
            vector<ll> p_1((P.pf.size() + 1) / 2);
            for (int i = 1; i < P.pf.size(); i += 2) {
                p_1[i / 2] = P.pf[i];
            }
            P.pf = p_1;
            n = (n - 1) / 2;
        }
    }
    return (P.pf[0] + MOD) % MOD;
}

void solve() {
    ll k, n;
    cin >> k >> n;
    n--;
    vector<ll> a(2 * k);
    vector<ll> c(k + 1);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    c[0] = 1;
    for (int i = 0; i < k; ++i) {
        cin >> c[i + 1];
//        c[i + 1] = -c[i + 1];
        c[i + 1] = (-c[i + 1] % MOD + MOD) % MOD;
    }
    GF A(a);
    GF C(c);
    A = (A * C);
    A.pf = vector<ll>(A.pf.begin(), A.pf.size() < k ? A.pf.end() : A.pf.begin() + k);
    cout << getNTH(n, A, C);
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//     gen.seed(time(0));
//     cout << fixed;
//     cout.precision(15);
//             cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}