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

void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}


void solve(){
    int n;
    cin >> n;
    vector<vector<int>> a;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> b;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                b.push_back(j + 1);
            }
        }
        a.push_back(b);
    }
    sort(a.begin(), a.end());
    for (auto c: a) {
        print(c);
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
