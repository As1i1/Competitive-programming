//
// Created by Dima on 18.02.2023.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<ll> pref1, pref2;

struct SegTree{
    int size = 1;
    vector<pair<ll, ll>> tree;

    void init(vector<int>& a){
        while (size < a.size()) {
            size *= 2;
        }
        tree.assign(2 * size, {0, 0});
        build(0, 0, size, a);
    }

    void build(int x, int lx, int rx, vector<int>& a) {
        if (rx - lx == 1){
            if (lx < a.size()) {
                tree[x] = {a[lx], pref1[a[lx]] - pref1[a[lx] - 1]};
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m, a);
        build(2 * x + 2, m, rx, a);
        tree[x].first = tree[2 * x + 1].first + tree[2 * x + 2].first;
        tree[x].second = tree[2 * x + 1].second + tree[2 * x + 2].second;
    }

    void set(int i, int v) {
        set(0, 0, size, i, v);
    }

    void set(int x, int lx, int rx, int i, int v) {
        if (rx - lx == 1) {
            tree[x] = {v, pref1[v] - pref1[v - 1]};
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m) {
            set(2 * x + 1, lx, m, i, v);
        } else {
            set(2 * x + 2, m, rx, i, v);
        }
        tree[x].first = tree[2 * x + 1].first + tree[2 * x + 2].first;
        tree[x].second = tree[2 * x + 1].second + tree[2 * x + 2].second;
    }

    pair<ll, ll> get(int l, int r) {
        return get(0, 0, size, l, r);
    }

    pair<ll, ll> get(int x, int lx, int rx, int l, int r){
        if (l <= lx && rx <= r) {
            return tree[x];
        }
        if (r <= lx || rx <= l) {
            return {0, 0};
        }
        int m = (rx + lx) / 2;
        pair<ll, ll> left = get(2 * x + 1, lx, m, l, r);
        pair<ll, ll> right = get(2 * x + 2, m, rx, l, r);
        return {left.first + right.first, left.second + right.second};
    }
};


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    pref1.resize(n + 1);
    pref2.resize(n + 1);
    pref1[0] = 1;
    ll cur = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cur *= 5;
        pref1[i + 1] = cur + pref1[i];
        pref2[i + 1] = i + 1 + pref2[i];
    }
    SegTree tree;
    tree.init(a);
    int q;
    cin >> q;
    while (q--) {
        int s;
        int x, y;
        cin >> s >> x >> y;
        if (s == 2) {
            int n = y - x + 1;
            pair<ll, ll> ans = tree.get(x - 1, y);
            if (ans.first == pref2[n] - pref2[0] && ans.second == pref1[n] - pref1[0]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            tree.set(x - 1, y);
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
//	cout.precision(15);
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
