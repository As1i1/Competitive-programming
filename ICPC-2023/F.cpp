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
    vector<pair<ld, ld>> points;
    for (int i = 0; i < n; ++i) {
        ld x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    ld ans = 0;
    ld mx = -1;
    for (int i = 0; i < n; ++i) {
        auto [x1, y1] = points[i];
        auto [x2, y2] = points[(i + 1) % n];
        ld tmp = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        ans += tmp;
        mx = max(mx, tmp);
    }
    cout << ans - mx;
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
