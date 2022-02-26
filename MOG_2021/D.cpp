//
// Created by AMD on 31.01.2022.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


map<int, int> dels(int n){
    map<int, int> ans;
    int i = 2;
    while(i * i <= n){
        while (n % i == 0){
            ans[i]++;
            n /= i;
        }
        i++;
    }
    if (n != 1){
        ans[n] = 1;
    }
    return ans;
}



struct SegTree{
    int size = 1;
    vector<map<int, int>> tree;


    SegTree(int n, vector<map<int, int>> &a){
        while (n >= size){
            size *= 2;
        }
        tree.assign(2 * size, {});
        build(0, 0, size, a);
    }

    map<int, int> combine(map<int, int> a, map<int, int> b){
        if (a.size() < b.size()){
            swap(a, b);
        }
        for (auto p: b){
            a[p.first] += p.second;
        }
        return a;
    }

    void build(int x, int lx, int rx, vector<map<int, int>> &a){
        if (rx - lx == 1){
            if (lx < a.size()) tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m, a);
        build(2 * x + 2, m, rx, a);
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }

    map<int, int> get_ans(int x, int lx, int rx, int l, int r){
        if (l >= rx || r <= lx){
            return {};
        }
        if (lx >= l && rx <= r){
            return tree[x];
        }
        int m = (rx + lx) / 2;
        auto left = get_ans(2 * x + 1, lx, m, l, r), right = get_ans(2 * x + 2, m, rx, l, r);
        return combine(left, right);
    }

    map<int, int> get_ans(int l, int r){
        return get_ans(0, 0, size, l, r);
    }
};



void solve(){
    int n, q;
    cin >> n >> q;
    vector<map<int, int>> a(n);
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        a[i] = dels(x);
    }
    SegTree tree(n, a);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        map<int, int> ans = tree.get_ans(l, r);
        ll ans_p = 1;
        for (auto p: ans){
            ans_p = (ans_p * (p.second + 1)) % MOD;
        }
        cout << ans_p << "\n";
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
