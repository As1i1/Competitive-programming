//
// Created by AMD on 31.01.2022.
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
    multiset<int> s1;
    set<int> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        s.insert(x);
        s1.insert(x);
    }
    int ans = INF + 10;
    for (auto elem: s){
        s1.erase(s1.find(elem));
        auto p_u = s1.upper_bound(elem), p_l = s1.lower_bound(elem);
        ans = min(min(abs(*p_u - elem), abs(*p_l - elem)), ans);
        s1.insert(elem);
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
    while(t--){
        solve();
    }
    return 0;
}
