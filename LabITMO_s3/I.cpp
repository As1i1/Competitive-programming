//
// Created by asi1i on 10/15/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve(){
    int n;
    cin >> n;
    vector<pair<ll, ll>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    vector<ld> key(n, INF);
    vector<int> sel(n, -1);
    vector<bool> used(n, false);
    function<ld(int, int)> dist = [&] (int x, int y) {
        return sqrt(
                (points[x].first - points[y].first) *
                   (points[x].first - points[y].first)
                    +
                   (points[y].second - points[x].second) *
                   (points[y].second - points[x].second));
    };
    key[0] = 0;
    ld ans = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (v == -1 || key[j] < key[v])) {
                v = j;
            }
        }
        used[v] = true;
        if (sel[v] != -1) {
            ans += dist(v, sel[v]);
        }
        for (int j = 0; j < n; ++j) {
            if (j == v) continue;
            if (dist(v, j) < key[j]) {
                key[j] = dist(v, j);
                sel[j] = v;
            }
        }
    }
    cout << ans;
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//	gen.seed(time(0));
	cout << fixed;
	cout.precision(15);
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
