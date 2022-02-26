#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve(){
    int n, m;
    ll t, k;
    cin >> n >> m >> t >> k;
    vector<ll> a, b;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        if (x <= t) a.push_back(x);
    }
    for (int j = 0; j < m; ++j) {
        ll x; cin >> x;
        if (x <= t) b.push_back(x);
    }
    n = a.size(), m = b.size();
    int k1 = 0, k2 = 0;
    ll cur_time = 0, cur_channels = 0, ans1 = 0, ans2 = 0;
    while (cur_time < t){
        if (cur_channels == 0){
            while (k1 < n && a[k1] + k < cur_time){
                k1++;
            }
            if (k1 == n){
                ans1 += t - cur_time;
                cur_time = t;
            }
            else if (k1 == n - 1){
                if (a[k1] <= cur_time){
                    if (a[k1] + k <= cur_time){
                        ans1 += t - cur_time;
                    }
                    else{
                        ans1 += max(t - (a[k1] + k), 0ll);
                    }
                    cur_time = t;
                }
                else{
                    ans1 += a[k1] - cur_time;
                    cur_time = a[k1];
                }
            }
            else{
                if (a[k1] <= cur_time){
                    ans1 += (a[k1 + 1] - a[k1] - k);
                    cur_time = a[k1 + 1];
                }
                else{
                    ans1 += a[k1] - cur_time;
                    cur_time = a[k1];
                }
            }
        }
        else{
            while (k2 < m && b[k2] + k < cur_time){
                k2++;
            }
            if (k2 == m){
                ans2 += t - cur_time;
                cur_time = t;
            }
            else if (k2 == m - 1){
                if (b[k2] <= cur_time){
                    if (b[k2] + k <= cur_time){
                        ans2 += t - cur_time;
                    }
                    else{
                        ans2 += max(t - (b[k2] + k), 0ll);
                    }
                    cur_time = t;
                }
                else{
                    ans2 += b[k2] - cur_time;
                    cur_time = b[k2];
                }
            }
            else{
                if (b[k2] <= cur_time){
                    ans2 += (b[k2 + 1] - b[k2] - k);
                    cur_time = b[k2 + 1];
                }
                else{
                    ans2 += b[k2] - cur_time;
                    cur_time = b[k2];
                }
            }
        }
        cur_channels = 1 - cur_channels;
    }
    cout << ans1 << " " << ans2;

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