//
// Created by AMD on 31.12.2021.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<set<int>> g;


bool check1(int mn){
    for (int  i = 0; i < g.size(); ++i){
        if (g[i].size() < mn) return false;
    }
    return true;
}


bool check2(int mx){
    for (int i = 0; i < g.size(); ++i){
        if (g[i].size() > mx) return false;
    }
    return true;
}


void solve(){
    int n, mx, mn;
    cin >> n >> mx >> mn;
    g.resize(n);
    while (!check1(mn)) {
        int t_mn = INF;
        vector<int> other, cur_mn;
        for (int i = 0; i < n; ++i) {
            if (g[i].size() < t_mn){
                t_mn = g[i].size();
                cur_mn = {i};
            }
            else if (g[i].size() == t_mn){
                cur_mn.push_back(i);
            }
        }
        for (int i = 0; i < n; ++i){
            if (find(cur_mn.begin(), cur_mn.end(), i) != cur_mn.end()){
                other.push_back(i);
            }
        }
        if (cur_mn.size() == 1){
            int a = cur_mn[0], b = other[gen() % other.size()];
            g[a].insert(b);
            g[b].insert(a);
            while (!check2(mx)){
                g[a].erase(b);
                g[b].erase(a);
                b = other[gen() % other.size()];
                g[a].insert(b);
                g[b].insert(a);
            }
        }
        else{
            int a = cur_mn[gen() % cur_mn.size()];
            cur_mn.erase(find(cur_mn.begin(), cur_mn.end(), a));
            int b = cur_mn[gen() % cur_mn.size()];
            g[a].insert(b);
            g[b].insert(a);
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
    gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//  cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
