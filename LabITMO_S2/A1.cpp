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

struct SegTree{
    int size = 1;
    vector<int> tree;

    void init(vector<int>& a){
        while (size < a.size()) {
            size *= 2;
        }
        tree.assign(2 * size, INT32_MAX);
        build(0, 0, size, a);
    }

    void build(int x, int lx, int rx, vector<int>& a) {
        if (rx - lx == 1){
            if (lx < a.size()) {
                tree[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m, a);
        build(2 * x + 2, m, rx, a);
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v) {
        set(0, 0, size, i, v);
    }

    void set(int x, int lx, int rx, int i, int v) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m) {
            set(2 * x + 1, lx, m, i, v);
        } else {
            set(2 * x + 2, m, rx, i, v);
        }
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    int get(int l, int r) {
        return get(0, 0, size, l, r);
    }

    int get(int x, int lx, int rx, int l, int r){
        if (l <= lx && rx <= r) {
            return tree[x];
        }
        if (r <= lx || rx <= l) {
            return INT32_MAX;
        }
        int m = (rx + lx) / 2;
        int left = get(2 * x + 1, lx, m, l, r);
        int right = get(2 * x + 2, m, rx, l, r);
        return min(left, right);
    }
};


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegTree tree;
    tree.init(a);
    while (cin) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        if (s == "min") {
            cout << tree.get(x - 1, y) << "\n";
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
