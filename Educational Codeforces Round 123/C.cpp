//
// Created by AMD on 22.02.2022.
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] += x;
    }
    int l = 0, r = 0;
    ll cur = 0, ans = 0, mn = 0;
    for (int i = 0; i < n; ++i){
        cur += a[i];
        if (ans < cur - mn){
            ans = cur - mn;
            r = i + 1;
        }
        if (mn > cur){
            l = i + 1;
            mn = cur;
        }
    }
    vector<int> answer;
    for (int i = 0; i < n - (r - l); ++i){
        answer.push_back(ans);
    }
    ll sum_pref = 0, sum_suf = 0;
    int k1 = l, k2 = r - 1;

}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
