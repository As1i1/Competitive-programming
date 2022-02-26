//
// Created by AMD on 24.02.2022.
//

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<vector<pair<int, int>>> tv;
vector<int> cost;
int n, m, global_ans = INF;
vector<int> m_ans;


bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}


int find_ans(int cur_v, int cur_sum, vector<bool> m_t, vector<int> m_cur) {
    if (cur_v == m) {
        if (cur_sum < global_ans) {
            global_ans = cur_sum;
            m_ans = m_cur;
        }
        return cur_sum;
    }
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (m_t[tv[cur_v][i].second]) {
            int tmp = cur_sum + tv[cur_v][i].first;
            if (tmp > global_ans) continue;
            else {
                m_cur[i] = tv[cur_v][i].second;
                ans = min(ans, find_ans(cur_v + 1, tmp, m_t, m_cur));
            }
        }
        else {
            int tmp = cur_sum + tv[cur_v][i].first + cost[tv[cur_v][i].second];
            if (tmp > global_ans) continue;
            else {
                m_cur[i] = tv[cur_v][i].second;
                m_t[tv[cur_v][i].second] = true;
                ans = min(ans, find_ans(cur_v + 1, tmp, m_t, m_cur));
                m_t[tv[cur_v][i].second] = false;
            }
        }
    }
    return ans;
}


int f2(int v, int cur_sum, vector<bool> mt) {

    if (v == m) return cur_sum;
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (mt[tv[v][i].second]) ans = min(ans, cur_sum + tv[v][i].first);
        else {
            mt[tv[v][i].second] = true;
            ans = min(ans, cur_sum + tv[v][i].first + cost[tv[v][i].second]);
            mt[tv[v][i].second] = false;
        }
    }
    return ans;
}


void solve() {
    cin >> n >> m;
    global_ans = INF;
    cost.resize(n);
    m_ans.resize(n);
    tv.resize(m, vector<pair<int, int>>(n));
    for (int i = 0; i < n; ++i) cin >> cost[i];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tv[i][j].first;
            tv[i][j].second = j;
        }
        sort(tv[i].begin(), tv[i].end(), comp);
    }
    vector<bool> tmp1(n, false);
    vector<int> tmp2(m, 0);
    find_ans(0, 0, tmp1, tmp2);
    cout << "----------------\n";
    cout << global_ans << "\n";
    for (int i = 0; i < m; ++i) {
        cout << m_ans[i] + 1 << " ";
    }
    cout << "\n---------------\n";
    cost.clear();
    m_ans.clear();
    tv.clear();
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
    //	gen.seed(time(0));
    //	cout << fixed;
    //	cout.precision(15);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
