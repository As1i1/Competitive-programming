//
// Created by aas1i1 on 4/2/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;

struct edge {
    string word;
};


void solve() {
    int n; cin >> n;
    vector<string> t1(n), t2(n);
    for (int i = 0; i < n; ++i) {
        cin >> t1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t2[i];
    }
    vector<vector<vector<edge>>> g(26 * 2, vector<vector<edge>>(26 * 2, vector<edge>()));
    for (int i = 0; i < n; ++i) {
        g[t1[i][0] - 'a'][t1[i].back() - 'a' + 26].push_back(edge{t1[i]});
        g[t2[i][0] - 'a' + 26][t2[i].back() - 'a'].push_back(edge{t2[i]});
    }
    vector<vector<vector<edge>>>  g_copy(g);
    int v = 0;
    for (int i = 0; i < 26 * 2; ++i) {
        int deg_in = 0;
        int deg_out = 0;
        for (int j = 0; j < 26 * 2; ++j) {
            deg_in += g[i][j].size();
            deg_out += g[j][i].size();
        }
        if (deg_in > deg_out && deg_in - deg_out % 2 == 1) {
            v = i;
            break;
        }
        if (deg_in > 0) {
            v = i;
        }
    }
    vector<int> stack = {v};
    vector<int> res;
    while (!stack.empty()) {
        int w = stack.back();
        bool found = false;
        for (int i = 0; i < 26 * 2; ++i) {
            if (g[w][i].size() != 0) {
                stack.push_back(i);
                g[w][i].pop_back();
                found = true;
                break;
            }
        }
        if (!found) {
            res.push_back(w);
            stack.pop_back();
        }
    }
    std::reverse(res.begin(), res.end());
    for (int i = 0; i < res.size() - 1; ++i) {
        cout << g_copy[res[i]][res[i + 1]].back().word << "\n";
        g_copy[res[i]][res[i + 1]].pop_back();
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


