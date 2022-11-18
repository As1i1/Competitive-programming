#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


vector<string> table;
vector<vector<int>> g;
vector<int> starts;
vector<int> depth;


int binpow(int a, int n){
//    int ans = 1;
//    for (int i = 0; i < n; ++i){
//        ans *= a;
//    }
    return (1 << n);
}


void dfs(int v) {
    int t = 0;
    int d = 0;
    for (int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (starts[u] == -1) {
            dfs(u);
        }
        if (starts[u] == 1) {
            t += binpow(2, g[v].size() - i - 1);
        }
        d = max(d, depth[u]);
    }
    depth[v] = d + 1;
    starts[v] = (table[v][t] - '0');
}


void solve(){
    int n;
    cin >> n;
    g.resize(n);
    table.resize(n);
    depth.resize(n);
    vector<int> cord;
    int k = 0;
    for (int i = 0; i < n; ++i){
        int m;
        cin >> m;
        if (m != 0) {
            for (int j = 0; j < m; ++j) {
                int v;
                cin >> v;
                g[i].push_back(v - 1);
            }
            string s = "";
            for (int j = 0; j < binpow(2, m); ++j){
                int x;
                cin >> x;
                s += to_string(x);
            }
            table[i] = s;
        } else {
            k++;
            cord.push_back(i);
        }
    }
    starts.resize(n);
    vector<int> ans;
    int ans1 = 0;
    reverse(cord.begin(), cord.end());
    int k2 = binpow(2, k);
    for (int i = 0; i < k2; i++) {
        fill(starts.begin(), starts.end(), -1);
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                starts[cord[j]] = 1;
            } else {
                starts[cord[j]] = 0;
            }
        }
        dfs(n - 1);
        ans.push_back(starts[n - 1]);
        if (ans1 == 0) {
            ans1 = depth[n - 1];
        }
    }
    cout << ans1 << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
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
