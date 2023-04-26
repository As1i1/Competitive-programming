//
// Created by Dima on 22.02.2023.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

struct Node{
    ll p[3][3];
};

struct SegTree{

    int size = 1;
    vector<Node> tree;

    Node combine(Node a, Node b) {
        Node c;
        return c;
    }

    void init(int n) {
        while (size < n) {
            size *= 2;
        }
        tree.assign(2 * size, {});
        build(0, 0, size);
    }

    void build(int x, int lx, int rx){
        if (rx - lx == 1) {
//            tree[x] = {1, 0, 0, 0, 1, 0, 0, 0, 1}; // right ?
            return;
        }
        int m = (rx + lx) / 2;
        build(2 * x + 1, lx, m);
        build(2 * x + 2, m, rx);
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }

    Node get(int x, int lx, int rx, int l, int r){
       if (l <= lx && r <= rx) {
           return tree[x];
       }
       int m = (lx + rx) / 2;
       if (m >= r) {
           return get(2 * x + 1, lx, m, l, r);
       } else if (m <= l) {
           return get(2 * x + 2, m, rx, l, r);
       } else {
           return combine(get(2 * x + 1, lx, m, l, r),
                          get(2 * x + 2, m, rx, l, r));
       }
    }

    Node get(int l, int r) {
        return get(0, 0, size, l, r);
    }

};


void solve(){
    int n, q;
//    cin >> n >> q;
//    n++;
//    SegTree tree;
//    tree.init((n + 2) / 3);
//    Node s = tree.get(0, (n + 2) / 3);
//    cout << s.left1 << " " << s.left2 << " " << s.left3 << "\n";
//    if (n % 3 == 0) {
//        cout << (s.left1 * 2 + s.left2 + s.left3) % MOD;
//    } else if (n % 3 == 1) {
//        cout << s.left1;
//    } else {
//        cout << (s.left1 + s.left2) % MOD;
//    }
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
