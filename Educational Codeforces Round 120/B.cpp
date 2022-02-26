//
// Created by AMD on 27.12.2021.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


bool comp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}


void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), pos, nev;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; ++i){
        char c;
        cin >> c;
        if (c == '1'){
            pos.push_back(a[i]);
        }
        else{
            nev.push_back(a[i]);
        }
    }
    sort(pos.begin(), pos.end());
    sort(nev.begin(), nev.end());
    int k = 1;
    for (int i = 0; i < nev.size(); ++i){
        ans[nev[i].second] = k;
        k++;
    }
    for (int i = 0; i < pos.size(); ++i){
        ans[pos[i].second] = k;
        k++;
    }
    for(int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << "\n";
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

