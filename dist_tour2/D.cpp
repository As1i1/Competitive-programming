//
// Created by AMD on 30.12.2021.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


bool can(vector<ll> p, vector<ll> s_p, set<pair<int, int>> s){
    while (p != s_p){
        bool flag = false;
        for (auto par: s){
            if (p[par.first] > p[par.second]){
                swap(p[par.first], p[par.second]);
                flag = true;
            }
        }
        if (!flag && p != s_p) return false;
    }
    return true;
}


void solve(){
    int n, q;
    cin >> n >> q;
    vector<ll> p(n), sorted_p(n);
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i){
        cin >> p[i];
        sorted_p[i] = p[i];
    }
    sort(sorted_p.begin(), sorted_p.end());
    while(q--){
        int c;
        cin >> c;
        if (c == 1){
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            x--;y--;
            swap(p[x], p[y]);
        }
        else if (c == 2){
            int x, y;
            cin >> x >> y;
            if (x == y) continue;
            if (x > y) swap(x, y);
            x--; y--;
            s.insert({x, y});
        }
        else if (c == 3){
            if (can(p, sorted_p, s)){
                cout << "DA\n";
            }
            else{
                cout << "NE\n";
            }

        }
        else{
            cout << 1 << "\n";
        }
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
