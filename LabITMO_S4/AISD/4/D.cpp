//
// Created by Dubinin Dmitrii on 6/3/24.
//

#include <bits/stdc++.h>
#include <numbers>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;

typedef complex<double> ftype;
const double pi = std::numbers::pi_v<double>;

ftype binpow(ftype a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    ftype d = binpow(a, n / 2);
    return d * d * (n % 2 == 0 ? 1: a);
}

template<typename T>
vector<ftype> fft(vector<T>& p, ftype w) {
    if (p.size() == 1) {
        return {p[0]};
    }
    vector<T> A0(p.size() / 2);
    vector<T> B0(p.size() / 2);
    for (int i = 0; i < p.size(); i += 2) {
        A0[i / 2] = p[i];
        B0[i / 2] = p[i + 1];
    }
    auto g0 = fft(A0, w * w);
    auto g1 = fft(B0, w * w);
    vector<ftype> g(p.size());
    ftype tmp = 1;
    for (int i = 0; i < p.size() / 2; ++i) {
        g[i] = g0[i] + tmp * g1[i];
        g[i + p.size() / 2] = g0[i] - tmp * g1[i];
        tmp *= w;
    }
    return g;
}

vector<int> interpolate(vector<ftype>& p) {
    int n = p.size();
    auto inv = fft(p, polar(1., -2 * pi / n));
    vector<int> res(n);
    for(int i = 0; i < n; i++)
        res[i] = round(real(inv[i]) / n);
    return res;
}

vector<ftype> evaluate(vector<int>& p) {
    int n = 1;
    while (n < p.size()) {
        n *= 2;
    }
    n *= 2;
    for (int i = p.size(); i < n; ++i) {
        p.push_back(0);
    }
    return fft(p, polar(1., 2 * pi / p.size()));
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n + 1; ++i) {
        cin >> b[i];
    }
    auto c = evaluate(a);
    auto d = evaluate(b);
    for (int i = 0; i < c.size(); ++i) {
        c[i] *= d[i];
    }
    auto res = interpolate(c);
    for (int i = 0; i < 2 * n + 1; ++i) {
        cout << res[i] << " ";
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


