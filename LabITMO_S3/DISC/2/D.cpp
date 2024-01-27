//
// Created by asi1i on 12/11/23.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

void solve() {
    int n, m;
    cin >> n >> m;
    set<vector<int>> I;
    for (int i = 0; i < m; ++i) {
        vector<int> v;
        int sz; cin >> sz;
        for (int j = 0; j < sz; ++j) {
            int x; cin >> x; v.push_back(x);
        }
        sort(v.begin(), v.end());
        I.insert(v);
    }

    if (I.find({}) == I.end()) {
        cout << "NO";
        return;
    }

    for (auto v: I) {
        for (int i = 0; i < (1 << v.size()); ++i) {
            vector<int> v1;
            for (int j = 0; j < v.size(); ++j) {
                if (i & (1 << j)) v1.push_back(v[j]);
            }
            if (I.find(v1) == I.end()) {
                cout << "NO";
                return;
            }
        }
    }

    for (auto v1_: I) {
        for (auto v2_: I) {
            if (v1_.size() == v2_.size()) continue;
            auto v1 = v1_;
            auto v2 = v2_;
            if (v1.size() < v2.size()) {
                swap(v1, v2);
            }
            vector<int> diff;
            for (int i = 0; i < n; ++i) {
                if (find(v1.begin(), v1.end(), i + 1) != v1.end() && find(v2.begin(), v2.end(), i + 1) == v2.end()) {
                    diff.push_back(i + 1);
                }
            }
            bool ans = false;
            for (auto item: diff) {
                v2.push_back(item);
                sort(v2.begin(), v2.end());
                if (I.find(v2) != I.end()) {
                    ans = true;
                    break;
                }
                v2.erase(find(v2.begin(), v2.end(), item));
            }
            if (!ans) {
                cout << "NO";
                return;
            }
        }
    }

    cout << "YES";
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
