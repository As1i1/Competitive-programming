//
// Created by asi1i on 10/21/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve(){
    int n;
    cin >> n;
    vector<int> pref(n - 2);
    vector<int> cnt(n, 0);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 2; ++i) {
        cin >> pref[i];
        pref[i]--;
        cnt[pref[i]]++;
    }
    set<int> vertex;
    for (int i = 0; i < n; ++i)
        if (cnt[i] == 0) vertex.insert(i);
    reverse(pref.begin(), pref.end());
    while (!pref.empty()) {
        int u = pref.back();
        int v = *vertex.begin();
        ans.push_back({u, v});
        pref.pop_back();
        vertex.erase(*vertex.begin());
        cnt[u]--;
        if (cnt[u] == 0) {
            vertex.insert(u);
        }
    }
    ans.push_back({*vertex.begin(), *(++vertex.begin())});
    for (auto [u, v]: ans) {
        cout << u + 1 << " " << v + 1 << "\n";
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
