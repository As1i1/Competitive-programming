//
// Created by Dubinin Dmitrii on 12/18/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

struct node {
    int child[26]{};
    int sufflink = -1;
    int parent;
    bool is_leaf = false;
    vector<int> rev_sufflinks{};
};
vector<node> arr;
vector<pair<int, int>> pairs;


int add_string(string s) {
    int cur = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (arr[cur].child[s[i] - 'a'] == 0) {
            arr.push_back({});
            arr.back().parent = cur;
            arr[cur].child[s[i] - 'a'] = arr.size() - 1;
        }
        cur = arr[cur].child[s[i] - 'a'];
    }
    arr[cur].is_leaf = true;
    return cur;
}


void build_aho() {
    queue<pair<int, int>> q;
    q.push({0, -1});
    while (!q.empty()) {
        auto [cur, v] = q.front();
        q.pop();
        if (cur == 0) {
            arr[cur].sufflink = 1;
        } else {
            arr[cur].sufflink = arr[arr[arr[cur].parent].sufflink].child[v];
            arr[arr[cur].sufflink].rev_sufflinks.push_back(cur);
        }
        for (int i = 0; i < 26; ++i) {
            if (arr[cur].child[i] != 0) {
                q.push({arr[cur].child[i], i});
            } else {
                arr[cur].child[i] = arr[arr[cur].sufflink].child[i];
            }
        }
    }
}


void dos(string t) {
    int cur = 0;
    for (int i = 0; i < t.size(); ++i) {
        if (pairs[cur].first == INF) {
            pairs[cur].first = i;
        }
        pairs[cur].second = i;
        cur = arr[cur].child[t[i] - 'a'];
    }
    if (pairs[cur].first == INF) {
        pairs[cur].first = t.size();
    }
    pairs[cur].second = t.size();
}


void check(int v) {
    for (int ref: arr[v].rev_sufflinks) {
        if (ref == 1) continue;
        check(ref);
        pairs[v] = {min(pairs[v].first, pairs[ref].first),
                    max(pairs[v].second, pairs[ref].second)};
    }
}


void solve() {
    int n;
    cin >> n;
    vector<string> strs(n);
    vector<int> no(n);
    arr.push_back({});
    arr.push_back({});
    for (int i = 0; i < 26; ++i) {
        arr[1].child[i] = 0;
    }
    arr.back().parent = 0;
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
        no[i] = add_string(strs[i]);
    }
    build_aho();
    pairs.assign(arr.size(), {INF, -1});
    string t;
    cin >> t;
    dos(t);
    check(0);
    for (int i = 0; i < n; ++i) {
        if (pairs[no[i]].first == INF) {
            cout << "-1 -1\n";
        } else {
            cout << pairs[no[i]].first - strs[i].size() << " " << pairs[no[i]].second - strs[i].size() << "\n";
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
