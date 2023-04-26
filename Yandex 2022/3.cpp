#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

//struct SegTree{
//    int size = 1;
//    vector<pair<int, int>> tree;
//
//    void init(vector<int> &a){
//        while(size < a.size()) {
//            size *= 2;
//        }
//        tree.assign(2 * size, {0, INF});
//        build(0, 0, size, a);
//    }
//
//    void build(int v, int l, int r, vector<int> &a) {
//        if (r - l == 1) {
//            if (l < a.size()) {
//                tree[v] = a[l];
//            }
//            return;
//        }
//        int m = (l + r) / 2;
//        build(2 * v + 1, l, m, a);
//        build(2 * v + 2, m, r, a);
//        if (tree[2 * v + 1].first < tree[2 * v + 2].first) {
//            tree[v] = tree[2 * v + 1];
//        } else {
//            tree[v] = tree[2 * v + 2];
//        }
//    }
//
//    pair<int, int> getmax(int l, int r) {
//        getmax(0, 0, size, l, r);
//    }
//
//    pair<int, int> getmax(int v, int lx, int rx, int l, int r) {
//        if (lx >= r || l >= rx) {
//            return {INF, -1};
//        }
//        if (l <= lx && rx <= r) {
//            return tree[v];
//        }
//        int m = (lx + rx) / 2;
//        pair<int, int> left = getmax(2 * v + 1, lx, m, l, r);
//        pair<int, int> right = getmax(2 * v + 2, m, rx, l, r);
//        if (left.first > right.first) {
//            return left;
//        } else {
//            return right;
//        }
//    }
//};


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "0";
        return;
    }
    vector<pair<int, int>> pref(n), suf(n);
    pref[0].first = a[0];
    pref[0].second = 0;
    suf.back() = {a.back(), n - 1};
    for (int i = 1; i < n; ++i){
        if (pref[i - 1].first > a[i]) {
            pref[i] = {a[i], i};
        } else {
            pref[i] = pref[i - 1];
        }
//        pref[i] = min(pref[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        if (suf[i + 1].first < a[i]) {
            suf[i] = {a[i], i};
        } else {
            suf[i] = suf[i + 1];
        }
//        suf[i] = max(suf[i + 1], a[i]);
    }
    vector<pair<double, pair<int, int>>> ans(n, {1, {-1, -1}});
    for (int i = 1; i < n; ++i) {
        double tmp = a[i] * 1.0 / pref[i - 1].first;
        if (tmp > 1) {
            ans[i] = {tmp, {pref[i - 1].second, i}};
        }
    }

    vector<int> mx(n);
    mx[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (ans[mx[i - 1]].first > ans[i].first) {
            mx[i] = mx[i - 1];
        } else {
            mx[i] = i;
        }
    }

    double better = ans[mx.back()].first;
    double s_b = 1;
    pair<int, int> inds2 = {-1, -1}, inds1;


    for (int i = 2; i < n - 1; i++) {
        if (ans[mx[i - 1]].second.first == -1){
            continue;
        }

        double tmp = (ans[mx[i - 1]].first / a[i]) * suf[i + 1].first;
        if (tmp > better && tmp > s_b) {
            s_b = tmp;
            inds2 = {i, suf[i + 1].second};
            inds1 = ans[mx[i - 1]].second;
        }
    }

    if (s_b > better) {
        cout << "2\n";
        cout << inds1.first + 1 << " " << inds1.second + 1 << "\n";
        cout << inds2.first + 1 << " " << inds2.second + 1;
    } else if (better != 1) {
        cout << "1\n";
        cout << ans[mx.back()].second.first + 1 << " " << ans[mx.back()].second.second + 1;
    } else {
        cout << "0";
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
