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
    vector<int> pf;

    GF(const vector<int>& pf_) : pf(pf_) {
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

GF operator*(const GF &a, const GF &b) {
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

GF operator/(const GF &a, const GF &b) {
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
    int k;
    cin >> k;
    vector<int> Q_pf(k + 1);
    vector<int> A_pf(k);
    Q_pf[0] = 1;
    for (int i = 0; i < k; ++i) {
        cin >> A_pf[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> Q_pf[i + 1];
        Q_pf[i + 1] = -Q_pf[i + 1];
    }
    GF P_im = GF(A_pf) * GF(Q_pf);
    A_pf.assign(k, 0);
    for (int i = 0; i < k; ++i) {
        A_pf[i] = P_im.pf[i];
    }
    GF P_real = GF(A_pf);
    print(P_real);
    print(GF(Q_pf));
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


