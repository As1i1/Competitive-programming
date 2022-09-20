//
// Created by Dima on 30.08.2022.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
int w, h;
vector<vector<bool>> field, used;
vector<vector<pair<int, int>>> p;


void bfs(int i, int j){
    queue<int> qx, qy;
    p[i][j] = {-2, -2};
    qx.push(i);
    qy.push(j);
    vector<pair<int, int>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    while (!qx.empty()){
        int x, y;
        x = qx.front();
        y = qy.front();
        qx.pop(); qy.pop();
        if (used[x][y]) continue;
        used[x][y] = true;
        for (auto par: d){
            int new_x = x + par.first, new_y = y + par.second;
            if (new_x >= 0 && new_x < w && new_y >= 0 && new_y < h && field[new_x][new_y] && !used[new_x][new_y]){
                p[new_x][new_y] = {x, y};
                qx.push(new_x);
                qy.push(new_y);
            }
        }
    }
}


void solve(){
    int x1, y1, x2, y2;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2;
    x1--;y1--;x2--;y2--;
    field.assign(w, vector<bool>(h, false));
    used.assign(w, vector<bool>(h, false));
    p.assign(w, vector<pair<int, int>>(h, {-1, -1}));
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            char c; cin >> c;
            if (c == '.') field[j][i] = true;
            else field[j][i] = false;
        }
    }
    bfs(x1, y1);
    if (!used[x2][y2]){
        cout << "NO";
        return;
    }
    vector<pair<int, int>> ans = {{x2, y2}};
    while (p[x2][y2].first != -2){
        int x_t = p[x2][y2].first, y_t = p[x2][y2].second;
        ans.push_back({x_t, y_t});
        x2 = x_t;
        y2 = y_t;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    for(auto par: ans){
        cout << par.first + 1 << " " << par.second + 1 << "\n";
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
  //  cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
