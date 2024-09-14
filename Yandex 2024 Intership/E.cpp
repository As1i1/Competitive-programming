//
// Created by aas1i1 on 3/2/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
int q;

struct node {
    int child[26]{};
    int parent;
    int val = -1;
    int num;
};
vector<node> arr;
vector<pair<int, int>> mx;
vector<bool> used;


int add_string(string s, int val, int num) {
    int cur = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (arr[cur].child[s[i] - 'a'] == 0) {
            arr.push_back({});
            arr.back().parent = cur;
            arr[cur].child[s[i] - 'a'] = arr.size() - 1;
        }
        cur = arr[cur].child[s[i] - 'a'];
    }
    if (val > arr[cur].val) {
        arr[cur].val = val;
        arr[cur].num = num;
    }
    return cur;
}

void dfs(int v) {
    mx[v] = {arr[v].val, arr[v].num};
    for (int c = 0; c < 26; ++c){
        if (arr[v].child[c] != 0)
            dfs(arr[v].child[c]);
        if (mx[arr[v].child[c]].first > mx[v].first) {
            mx[v] = mx[arr[v].child[c]];
        }
    }
}

void solve() {
    int n;
    cin >> n >> q;
    arr.push_back({});
    for (int i = 0; i < n; ++i) {
        string s; int w;
        cin >> s >> w;
        add_string(s, w, i + 1);
    }
    mx = vector<pair<int, int>>(arr.size());
    dfs(0);
    int cur_v = 0;
    string cur = "";
    int balans = 0;
    while (q--) {
        char c;
        cin >> c;
        if (c == '+') {
            char sym;
            cin >> sym;
            cur += sym;
            if (balans != 0 || arr[cur_v].child[sym - 'a'] == 0) {
                cout << "-1\n";
                balans++;
            } else {
                cur_v = arr[cur_v].child[sym - 'a'];
                cout << mx[cur_v].second << "\n";
            }
        } else {
            if (balans > 1) {
                balans--;
                cout << "-1\n";
            } else if (balans == 1) {
                balans--;
                cout << mx[cur_v].second << "\n";
            } else {
                cur_v = arr[cur_v].parent;
                cout << mx[cur_v].second << "\n";
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


