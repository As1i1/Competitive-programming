//
// Created by AMD on 12.01.2022.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


struct SegTree {

    struct node {
        ll c_xor = 0, c_and = INT64_MAX, c_or = 0;
        vector<pair<int, ll>> op; // 1 - or, 2 - and, 3 - xor
    };

    int size = 1;
    vector<node> tree;

    SegTree(int N, vector<ll> a) {
        while (size < N) {
            size *= 2;
        }
        tree.assign(2 * size, {});
        build(0, 0, size, a);
    }


    node combine(node a, node b) {
        node c;
        c.c_or = a.c_or | b.c_or;
        c.c_and = a.c_and & b.c_and;
        c.c_xor = a.c_xor ^ b.c_xor;
        return c;
    }

    void push(int x, int lx, int rx) {
        if (tree[x].op.size() == 0) return;
        ll tmp = tree[x].op[0].second;
        bool c = false;
        if (tree[x].op[0].first == 2) c = true;
        for (int i = 1; i < tree[x].op.size(); ++i) {
            if (tree[x].op[i].first == 1) {
                tmp |= tree[x].op[i].second;
            }
            else if (tree[x].op[i].first == 2) {
                tmp &= tree[x].op[i].second;
                c = true;
            }
        }
        tree[x].op = {};
        if (!c) {
            tree[x].c_xor |= tmp;
            tree[x].c_and |= tmp;
            tree[x].c_or |= tmp;
        }
        else {
            tree[x].c_xor &= tmp;
            tree[x].c_and &= tmp;
            tree[x].c_or &= tmp;
        }
        if (rx - lx == 1) {
            return;
        }
        int c1 = 1;
        if (c) c1 = 2;
        tree[2 * x + 1].op.push_back({ c, tmp });
        tree[2 * x + 2].op.push_back({ c, tmp });
    }


    void build(int x, int lx, int rx, vector<ll>& a) {
        if (rx - lx == 1) {
            if (lx < a.size()) tree[x].c_xor = tree[x].c_and = tree[x].c_or = a[lx];
            return;
        }
        int m = (rx + lx) / 2;
        build(2 * x + 1, lx, m, a);
        build(2 * x + 2, m, rx, a);
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }


    void update(int x, int lx, int rx, int l, int r, int c, ll d) {
        if (r <= lx || l >= rx) {
            return;
        }
        if (lx >= l && rx <= r) {
            tree[x].op.push_back({ c, d });
            push(x, lx, rx);
            return;
        }
        push(x, lx, rx);
        int m = (rx + lx) / 2;
        update(2 * x + 1, lx, m, l, r, c, d);
        update(2 * x + 2, m, rx, l, r, c, d);
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }

    ll get(int x, int lx, int rx, int l, int r, int c) {
        push(x, lx, rx);
        if (r <= lx || l >= rx) {
            if (c == 2) return INT64_MAX;
            return 0;
        }
        if (lx >= l && rx <= r) {
            if (c == 1) return tree[x].c_or;
            if (c == 2) return tree[x].c_and;
            return tree[x].c_xor;
        }
        int m = (rx + lx) / 2;
        ll left = get(2 * x + 1, lx, m, l, r, c);
        ll right = get(2 * x + 2, m, rx, l, r, c);
        if (c == 1) return left | right;
        if (c == 2) return left & right;
        return left ^ right;
    }

    void update(int l, int r, int c, ll d) {
        update(0, 0, size, l, r, c, d);
    }

    ll get(int l, int r, int  c) {
        return get(0, 0, size, l, r, c);
    }

};


void solve2(int n, int q) {
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (q--) {
        string c1, c2;
        int l, r;
        cin >> c1 >> c2 >> l >> r;
        l--;
        if (c1 == "get") {
            ll ans = a[l];
            if (c2 == "xor") {
                for (int i = l + 1; i < r; ++i) {
                    ans ^= a[i];
                }
            }
            else if (c2 == "or") {
                for (int i = l + 1; i < r; ++i) {
                    ans |= a[i];
                }
            }
            else {
                for (int i = l + 1; i < r; ++i) {
                    ans &= a[i];
                }
            }
            cout << ans << "\n";
        }
        else {
            ll d;
            cin >> d;
            if (c2 == "xor") {
                for (int i = l; i < r; ++i) {
                    a[i] ^= d;
                }
            }
            else if (c2 == "or") {
                for (int i = l; i < r; ++i) {
                    a[i] |= d;
                }
            }
            else {
                for (int i = l; i < r; ++i) {
                    a[i] &= d;
                }
            }
        }
    }
}



void solve() {
    int n, q;
    cin >> n >> q;
    if (n <= 1000 && q <= 1000) {
        solve2(n, q);
        return;
    }
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    SegTree tree(n, a);
    while (q--) {
        string c1, c2;
        int l, r;
        cin >> c1 >> c2 >> l >> r;
        l--;
        if (c1 == "get") {
            if (c2 == "xor") {
                cout << tree.get(l, r, 3) << "\n";
            }
            else if (c2 == "or") {
                cout << tree.get(l, r, 1) << "\n";
            }
            else{
                cout << tree.get(l, r, 2) << "\n";
            }
        }
        else {
            ll d;
            cin >> d;
            if (c2 == "or") {
                tree.update(l, r, 1, d);
            }
            else {
                tree.update(l, r, 2, d);
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
