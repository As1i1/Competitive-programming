//
// Created by Dima on 23.12.2022.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<long> fact(19);


void f(long n, long k, set<int> s){
    if (n == 0) {
        return;
    }
    long t = k / fact[n - 1];
    auto tmp = s.begin();
    for (int i = 0; i < t;++i) {
        tmp++;
    }
    cout << *(tmp) << " ";
    s.erase(tmp);
    f(n - 1, k - t * fact[n - 1], s);
}


void solve(){
    fact[0] = 1;
    for (int i = 1; i < 19; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    long n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 1; i <= n; ++i) s.insert(i);
    f(n, k, s);
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
