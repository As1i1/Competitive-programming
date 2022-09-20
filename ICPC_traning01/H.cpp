#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve(){
    int n, t, d;
    cin >> n >> t >> d;
    vector<int> s(n), t_s(t);
    vector<pair<int, int>> teams(t);
    for (int i = 0; i < n; ++i){
        cin >> s[i];
    }
    for (int i = 0; i < t; ++i){
        cin >> teams[i].first >> teams[i].second;
        for (int j = teams[i].first - 1; j < teams[i].second; ++j){
            t_s[i] += s[j];
        }
    }
    for (int i = 0; i < d; ++i){
        int m; cin >> m;
        for (int j = 0; j < m; ++j){
            int ind; cin >> ind;
            for (int k = 0; k < t; ++k){
                if (teams[k].first <= ind && ind <= teams[k].second) t_s[k]++;
            }
        }
        cout << "Day " << i + 1 << ": ";
        for (int j = 0; j < t; ++j){
            cout << t_s[j] << " ";
        }
        cout << "\n";
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
