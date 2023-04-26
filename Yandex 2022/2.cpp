#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
ll x;

bool comp(pair<int, int> a, pair<int, int> b){
    int d1 = abs(x - a.first), d2 = abs(x - b.first);
    return d1 < d2;
}

void solve(){
    ll n, t;
    cin >> n >> x >> t;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), comp);
    int ans = 0;
    vector<int> index;
    for (int i = 0; i < n; ++i) {
        if (abs(x - a[i].first) + ans <= t) {
            ans += abs(x - a[i].first);
            index.push_back(a[i].second + 1);
        }
    }
    sort(index.begin(), index.end());
    cout << index.size() << "\n";
    for (auto i: index){
        cout << i << " ";
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
