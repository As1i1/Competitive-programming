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
    cout << a[0];
    for (int i = 1; i < a.size(); i++) {
        cout << "+" << a[i];
    }
    cout << "\n";
}

void f(int n, int k, vector<int> a){
    if (n == 0) {
        print(a);
        return;
    }
    bool flag = true;
    for (int i = k; i <= n; ++i) {
        flag = false;
        a.push_back(i);
        f(n - i, i, a);
        a.pop_back();
    }
    if (flag) {
        return;
    }
}


void solve(){
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 1; i <= n; ++i) {
        a.push_back(i);
        f(n - i, i, a);
        a.pop_back();
    }
    cout << cnt;
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
