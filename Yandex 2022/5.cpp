#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<int> p, color;
int k;
string s;

void dfs1(int v, int clr){
    color[v] = clr;
    if (color[p[v]] != -1) {
        dfs1(p[v], clr);
    }
}

void find_cyrcle(int v)


void solve(){
    int n;
    cin >> n >> k;
    cin >> s;
    vector<int> d(n);
    p.resize(n);
    color.resize(n, -1);
    vector<vector<char>> s_l(n, vector<char>(26));
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; j++) {
            s_l[i][j] = 'a' + ((s[i] - 'a') + j * d[i]) % 26;
        }
    }

    int c = 1;
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            dfs1(i, c);
            c++;
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
