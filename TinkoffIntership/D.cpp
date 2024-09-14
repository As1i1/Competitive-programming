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


void solve() {
    int n;
    char type;
    bool used[1000][1000];
    cin >> n >> type;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            used[i][j] = false;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (used[i][j]) {
                continue;
            }

            used[i][j] = true;
            if (type == 'L') {
                int x = n - j - 1;
                int y = i;

                while (!(x == i && y == j)) {
                    used[x][y] = true;
                    int x_ = n - y - 1;
                    int y_ = x;
                    x = x_;
                    y = y_;
                    cnt++;
                }

            } else {
                int x = j;
                int y = n - i - 1;

                while (!(x == i && y == j)) {
                    used[x][y] = true;
                    int x_ = y;
                    int y_ = n - x - 1;
                    x = x_;
                    y = y_;
                    cnt++;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            used[i][j] = false;

    cout << cnt << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (used[i][j]) {
                continue;
            }

            used[i][j] = true;
            if (type == 'L') {
                int x = n - j - 1;
                int y = i;

                while (!(x == i && y == j)) {
                    used[x][y] = true;
                    cout << i << " " << j << " " << x << " " << y << "\n";
                    int x_ = n - y - 1;
                    int y_ = x;
                    x = x_;
                    y = y_;
                    cnt++;
                }

            } else {
                int x = j;
                int y = n - i - 1;

                while (!(x == i && y == j)) {
                    used[x][y] = true;
                    cout << i << " " << j << " " << x << " " << y << "\n";
                    int x_ = y;
                    int y_ = n - x - 1;
                    x = x_;
                    y = y_;
                    cnt++;
                }
            }
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
    while (t--) {
        solve();
    }
    return 0;
}


