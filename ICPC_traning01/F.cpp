#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


int mn(int n){
    if (n == 1) return 1;
    for (double i = 2; i < 100; i++){
        if (pow(pow(n, 1/i), i) == n) return pow(n, 1/i);
    }
}


void solve(){
    int n;
    cin >> n;
//    vector<int> a(n);
    set<int> ans;
    for (int i = 0; i < n; ++i){
        int t;
        cin >> t;
        ans.insert(mn(t));
    }
    cout << (int)ans.size();
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
