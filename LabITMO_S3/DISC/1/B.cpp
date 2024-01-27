//
// Created by asi1i on 10/21/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

bool is_ore(vector<vector<int>>& g, set<int>& v, int n) {
    vector<int> cnt(n, 0);
    int cur_n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v.find(i) == v.end()) continue;
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == 1 && v.find(j) != v.end()) cnt[i]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (v.find(i) == v.end()) continue;
        for (int j = 0; j < n; ++j) {
            if (i == j || v.find(j) == v.end() || g[i][j] == 1) continue;
            if (cnt[i] + cnt[j] < cur_n) return false;
        }
    }

    return true;
}

bool is_diraka(vector<vector<int>>& g, set<int>& v, int n) {
    int mn = INF;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        if (v.find(i) == v.end()) continue;
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == 1 && v.find(j) != v.end()) cnt++;
        }
        mn = min(mn, cnt);
    }
    return mn >= v.size() / 2;
}


deque<int> fincCircle1(vector<vector<int>> g, int n){
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        q.push_back(i);
    }

    for (int k = 0; k < n * (n - 1); k++) {
        int first = q[0];
        int second = q[1];
        if (g[first][second] == 0) {
            int i = 2;
            while (g[first][q[i]] == 0 || g[second][q[i + 1]] == 0) {
                ++i;
            }
            for (int j = 1; j <= i - j + 1; ++j) {
                int t = q[j];
                q[j] = q[i - j + 1];
                q[i - j + 1] = t;
            }
        }
        q.push_back(first);
        q.pop_front();
    }
    return q;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    vector<int> cnt(n, 0), v;
    for (int i = 0; i < n; ++i) {
        v.push_back(i);
        for (int j = 0; j < i; ++j) {
            char c; cin >> c;
            if (c == '1'){
                cnt[i]++;
                cnt[j]++;
                g[i][j] = 1;
                g[j][i] = 1;
            }
        }
    }
    if (n < 20) {
        auto res = fincCircle1(g, n);
        for (auto u: res) {
            cout << u + 1 << " ";
        }
        return;
    }
    sort(v.begin(), v.end(), [&] (int a, int b) {return cnt[a] > cnt[b];});

    set<int> cur_v;
    for (int i = 0; i < 5; ++i) {
        cur_v.insert(v[i]);
    }
    int i = 5;
    for (; i < n; ++i) {
        cur_v.insert(v[i]);
        if (!is_diraka(g, cur_v, n) && !is_ore(g, cur_v, n)) {
            cur_v.erase(v[i]);
            break;
        }
    }
    vector<vector<int>> g_(cur_v.size(), vector<int>(cur_v.size(), 0));
    for (int k = 0; k < cur_v.size(); ++k) {
        for (int j = 0; j < cur_v.size(); ++j) {
            g_[k][j] = g[v[k]][v[j]];
        }
    }
    deque<int> circ = fincCircle1(g_, cur_v.size());
    for (;i < n; ++i) {
        for (int j = 0; j < circ.size(); ++j) {
            if (g[circ[j]][v[i]] == 1 && g[v[i]][circ[(j + 1) % circ.size()]] == 1) {
                circ.insert(next(find(circ.begin(), circ.end(), circ[j])), v[i]);
                break;
            }
        }
    }
    assert(circ.size() == n);
    for (auto u: circ) {
        cout << u + 1 << " ";
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
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
