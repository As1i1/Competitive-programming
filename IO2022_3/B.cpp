//
// Created by Dima on 08.03.2022.
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
    ll n, X;
    cin >> n >> X;
    vector<bool> times(n), rat(n);
    int k1 = 0;
    set<pair<ll, int>> s1;
    for (int i = 0; i < n; ++i){
        char c; cin >> c;
        if (c == '+'){
            int t, p;
            cin >> t >> p;
            t--;
            times[t] = true;
            rat[t] = p;
            s1.insert({p, t});
            if (s1.size() <= 2) continue;
            pair<ll, int> pr1 = *s1.begin();
            pair<ll, int> pr2 = *(++s1.rbegin());
            while (s1.size() > 2){
                pair<ll, int> pr = *s1.rbegin();
                if ((pr.first - pr1.first) * (pr.first - pr2.first) > X){
                    s1.erase(pr);
                    times[pr.second] = false;
                }
                else{
                    break;
                }
            }
        }
        else {
            while (!times[k1]) {
                k1++;
            }
            cout << k1 + 1 << "\n";
            s1.erase({rat[k1], k1});
            k1++;
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
