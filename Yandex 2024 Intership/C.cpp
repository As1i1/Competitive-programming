//
// Created by aas1i1 on 3/2/24.
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
    int n;
    cin >> n;
    vector<int> b(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
        cin >> b[i];
    }
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    multiset<int> before, after;
    for (int i = 0; i < n; ++i) {
        after.insert(b[a[i].second]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        after.erase(after.find(b[a[i].second]));
        int lb = -(before.empty() ? 1 : *before.begin());
        int ub = after.empty() ? INF : *after.begin();
        if (lb < b[a[i].second] && b[a[i].second] < ub) {
            ans++;
        }
        before.insert(-b[a[i].second]);
    }
    cout << ans;
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


