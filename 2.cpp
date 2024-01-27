//
// Created by asi1i on 10/9/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

struct matrix {
    vector<vector<ll>> m;

    matrix(int l, int r) {
        m = vector<vector<ll>>(l, vector<ll>(r, 0));
    }

    friend matrix operator*(const matrix& left, const matrix& right) {
        matrix res(left.m.size(), left.m.size());
        int n = left.m.size();
        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                ll sum = 0;
                for (int k = 0; k < n; ++k) {
                    sum = (sum + (left.m[i][k] * right.m[k][j]) % MOD) % MOD;
                }
                res.m[i][j] = sum;
            }
        }
        return res;
    }
};

matrix binpow(ll n, matrix a) {
    if (n == 1) {
        return a;
    }
    matrix d = binpow(n / 2, a);
    if (n % 2 != 0) {
        return d * d * a;
    } else {
        return d * d;
    }
}

void solve() {
    matrix m(5, 5);
    m.m = {{0, 1, 0, 0, 1},
           {0, 0, 1, 0, 0},
           {0, 0, 0, 1, 0},
           {1, 0, 0, 0, 0},
           {0, 0, 0, 1, 0}};
    ll s = 11986126526701LL;
    m = binpow(s, m);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; ++j) {
            cout << m.m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << m.m[0][1];
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

