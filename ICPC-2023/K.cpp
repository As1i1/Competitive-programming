#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

int max_left(int v, vector<pair<int, int>> tree) {
    if (tree[v].first == -1) {
        return v;
    }
    return max_left(tree[v].first, tree);
}

vector<vector<int>> to_bambuk(vector<pair<int, int>>& tree) {
    vector<vector<int>> ans;
    int cur_v = 0;
    int mx_left = max_left(0, tree);
    while (tree[cur_v].second != -1 || tree[cur_v].first != -1) {
        if (tree[cur_v].second != -1){
            ans.push_back({tree[cur_v].second, mx_left, cur_v});
            tree[mx_left].first = tree[cur_v].second;
            tree[cur_v].second = -1;
            mx_left = max_left(mx_left, tree);
        }
        cur_v = tree[cur_v].first;
    }
    return ans;
}


void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> b_tree1(n, {-1, -1}), b_tree2(n, {-1, -1});
    for (int i = 1; i < n; ++i) {
        int p; cin >> p;
        if (b_tree1[p].first == -1) {
            b_tree1[p].first = i;
        } else {
            b_tree1[p].second = i;
        }
    }
    for (int i = 1; i < n; ++i) {
        int p; cin >> p;
        if (b_tree2[p].first == -1) {
            b_tree2[p].first = i;
        } else {
            b_tree2[p].second = i;
        }
    }
    vector<vector<int>> ans1 = to_bambuk(b_tree1), ans2 = to_bambuk(b_tree2);
    vector<int> to(n);
    to[0] = 0;
    int f = 0, s = 0;
    while (b_tree1[f].first != -1) {
        to[b_tree2[s].first] = b_tree1[f].first;
        f = b_tree1[f].first;
        s = b_tree2[s].first;
    }
    cout << ans1.size() + ans2.size() << "\n";
    for (int i = 0; i < ans1.size(); ++i) {
        cout << ans1[i][0] << " " << ans1[i][1] << "\n";
    }
    for (int i = ans2.size() - 1; i >= 0; --i) {
        cout << to[ans2[i][0]] << " " << to[ans2[i][2]] << "\n";
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
