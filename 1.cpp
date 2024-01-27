#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
const int N = 7;
const int FACT = 5040;
vector<vector<vector<int>>> graphs;


bool check_sv(int index) {
    vector<bool> used(N, false);
    function<void(int)> f;
    f = [&] (int v) {
        used[v] = true;
        for (int i = 0; i < N; ++i) {
            if (!used[i] && graphs[index][v][i] == 1) {
                f(i);
            }
        }
    };
    f(0);
    for (int i = 0; i < N; ++i) {
        if (!used[i]) return false;
//        int cnt = 0;
//        for (int j = 0; j < N; ++j) {
//            cnt += graphs[index][i][j];
//        }
//        if (cnt < ((N + 1) / 2) - 1) return false;
    }
    return true;
}


bool check_cls(vector<vector<int>> a, vector<vector<int>> b) {
    vector<int> per = {0, 1, 2, 3, 4, 5, 6};
    vector<bool> used = vector<bool>(N, false);
    bool ans = true;
    function<void(int, int)> f;
    f = [&] (int v, int v2) {
        used[v] = true;
        for (int i = 0; i < N; ++i) {
            if (a[v][i] == 1 && b[per[v2]][per[i]] == 1){
                if (!used[v]) {
                    f(i, i);
                }
            } else if (a[v][i] != b[per[v2]][per[i]]) {
                ans = false;
                return;
            }
        }
    };
    for (int i = 0; i < FACT; i++) {
        used = vector<bool>(N, false);
        ans = true;
        f(0, 0);
        next_permutation(per.begin(), per.end());
        if (ans) {
            return true;
        }
    }
    return false;
}


bool check_e(int index) {
    vector<bool> used(N, false);
    function<void(int)> f;
    f = [&] (int v) {
        used[v] = true;
        for (int i = 0; i < N; ++i) {
            if (!used[i] && graphs[index][v][i] == 1) {
                f(i);
            }
        }
    };
    f(0);
    for (int i = 0; i < N; ++i) {
        if (!used[i]) return false;
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            cnt += graphs[index][i][j];
        }
        if (cnt % 2 != 0) return false;
    }
    return true;
}


void print_g(vector<vector<int>> g, int n) {
    cout << "-------------------\n";
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "-------------------";
}


void solve() {
    int n = 4;
    map<pair<int, int>, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            mp[{i, j}] = cnt;
            cnt++;
        }
    }
    for (int i = 0; i < (1 << (n * (n - 1) / 2)); ++i) {
        vector<vector<int>> g(n, vector<int>(n, 0));
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < j; ++k) {
                if (i & (1 << mp[{j, k}])) {
                    g[j][k] = 1;
                    g[k][j] = 1;
                } else {
                    g[j][k] = 2;
                    g[k][j] = 2;
                }
            }
        }
        vector<int> v = {0, 1, 2, 3};
        bool is_ans = false;
        for (int k = 0; k < 24; ++k) {
            if (g[v[0]][v[1]] == g[v[1]][v[2]] && g[v[1]][v[2]] == g[v[2]][v[3]]) {
                is_ans = true;
                break;
            }
            next_permutation(v.begin(), v.end());
        }
        if (!is_ans) {
            print_g(g, n);
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
//    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
    solve();
    return 0;
}
