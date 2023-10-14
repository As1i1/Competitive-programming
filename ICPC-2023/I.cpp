#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
int n, m, kkk;
vector<vector<int>> g;
vector<vector<int>> d;


bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}


void bfs(int sx, int sy) {
    set<pair<int, pair<int, int>>> queue;
    queue.insert({-kkk, {sx, sy}});
    d[sx][sy] = kkk;
    vector<pair<int, int>> dxdy = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<pair<int, int>> dxdy2 = {{0, 2}, {2, 0}, {0, -2}, {-2, 0}};
    while (!queue.empty()) {
        auto [k_, p] = *queue.begin();
        k_ = -k_;
        int x = p.first, y = p.second;
        queue.erase(queue.begin());
        for (auto [dx, dy]: dxdy) {
            if (check(x + dx, y + dy) && d[x + dx][y + dy] < k_ && g[x + dx][y + dy] == 0) {
                d[x + dx][y + dy] = k_;
                queue.insert({-k_, {x + dx, y + dy}});
            }
        }
        if (k_ != 0) {
            for (auto [dx, dy]: dxdy2) {
                if (check(x + dx, y + dy) && d[x + dx][y + dy] < k_ - 1 && g[x + dx][y + dy] == 0) {
                    d[x + dx][y + dy] = k_ - 1;
                    queue.insert({-(k_ - 1), {x + dx, y + dy}});
                }
            }
        }
    }
}


void solve(){
    cin >> n >> m >> kkk;
    g.resize(n, vector<int>(m, 0));
    d.resize(n, vector<int>(m, -INF));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            if (c == '.') {
                g[i][j] = 0;
            } else {
                g[i][j] = 1;
            }
        }
    }
    int s1, s2;
    cin >> s1 >> s2;
    s1--;
    s2--;
    int e1, e2;
    cin >> e1 >> e2;
    e1--; e2--;
    bfs(s1, s2);
    if (d[e1][e2] == -INF) {
        cout << "NO";
    } else {
        cout << "YES";
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
