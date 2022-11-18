//
// Created by Dima on 05.10.2022.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 1, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<int> a;
int n;


int binary_search(int x){
    int l = 0, r = n;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (a[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}


void solve(){
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    a.push_back(INF);
    a.push_back(-INF);
    n += 2;
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    while (q--) {
        int m1, m2;
        cin >> m1 >> m2;
        int l = binary_search(m1 - 1), r = binary_search(m2);
//        cout << l << " " << r << "\n";
        while (l < n && a[l] < m1) {
            l++;
        }
        cout << r - l + 1 << "\n";
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

