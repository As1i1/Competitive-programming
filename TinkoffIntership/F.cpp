//
// Created by aas1i1 on 4/15/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;

bool check(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> field(n, vector<char>(n));
    vector<vector<pair<int, int>>> dist(n, vector<pair<int, int>>(n, {INF, INF}));

    vector<pair<int, int>> K_d = {{2, 1}, {1, 2}, {-2, 1}, {1, -2},
                                  {2, -1},{1, -2}, {-2, -1}, {-1, -2}};

    vector<pair<int, int>> G_d = {{1, 1}, {1, 0}, {1, -1}, {0, -1},
                                  {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};
    pair<int, int> start;
    pair<int, int> finish;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> field[i][j];
            if (field[i][j] == 'S') {
                start = {i, j};
            }
            if (field[i][j] == 'F') {
                finish = {i , j};
            }
        }
    }
    queue<tuple<int, int, int, int>> q;
    q.emplace(start.first, start.second, 1, 1);
    dist[start.first][start.second].first = 0;
    while (!q.empty()) {
        auto [x, y, state, was] = q.front();
        int value;
        if (was == 1) {
            value = dist[x][y].first;
        } else {
            value = dist[x][y].second;
        }
        q.pop();
        if (state == 0) {
            for (auto [dx, dy] : G_d) {
                int new_x = dx + x;
                int new_y = dy + y;
                if (check(new_x, new_y, n) && dist[new_x][new_y].second > value + 1) {
                    dist[new_x][new_y].second = value + 1;
                    int new_state = state;
                    if (field[new_x][new_y] == 'K') {
                        new_state = 1;
                    }
                    q.emplace(new_x, new_y, new_state, state);
                }
            }
        } else {
            for (auto [dx, dy] : K_d) {
                int new_x = dx + x;
                int new_y = dy + y;
                if (check(new_x, new_y, n) && dist[new_x][new_y].first > value + 1) {
                    dist[new_x][new_y].first = value + 1;
                    int new_state = state;
                    if (field[new_x][new_y] == 'G') {
                        new_state = 0;
                    }
                    q.emplace(new_x, new_y, new_state, state);
                }
            }
        }
    }

    int answer = min(dist[finish.first][finish.second].first, dist[finish.first][finish.second].second);
    cout << ((answer >= INF) ? -1 : answer);
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
    while (t--) {
        solve();
    }
    return 0;
}


