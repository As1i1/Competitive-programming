#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;


int MOD = (int) 1e9 + 7;

struct segtree {
    vector<vector<ll>> tree;
    int size = 1;

    void init(int N) {
        while (size < N) {
            size *= 2;
        }
        tree.assign(2 * size, {0, 0, INT32_MAX, INT32_MIN, 1, 0});
    }

    vector<ll> comb(vector<ll> a, vector<ll> b){
        vector<ll> c = {0, 0, 0, 0, 0, 0};
        c[0] = a[0] ^ b[0];
        c[1] = a[1] + b[1];
        c[2] = min(a[2], b[2]);
        c[3] = max(a[3], b[3]);
        c[4] = (((a[4]) % MOD) * b[4]) % MOD;
        c[5] = a[5] | b[5];
        return c;
    }

    vector<ll> get_sum(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return {0, 0, INT32_MAX, INT32_MIN, 1, 0};
        }
        if (lx >= l && rx <= r) {
            return tree[x];
        }
        int m = (rx + lx) / 2;
        vector<ll> s_left = get_sum(l, r, 2 * x + 1, lx, m);
        vector<ll> s_right = get_sum(l, r, 2 * x + 2, m, rx);
        return comb(s_left, s_right);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = {v, v, v, v, v, v};
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = comb(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    vector<ll> get_sum(int l, int r) {
        return get_sum(l, r, 0, 0, size);
    }
};



int main() {
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);

    int n, q;
    cin >> n;
    vector<ll> mul = vector<ll>(n + 1);
    vector<int> o_r = vector<int>(n + 1);
    mul[1] = 1;
    o_r[1] = 1;
    for (int i = 2; i <= n; ++i) {
        mul[i] = (mul[i - 1] * i) % MOD;
        o_r[i] = o_r[i - 1] | i;
    }
    segtree tree;
    tree.init(n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        tree.set(i, tmp);
    }
    cin >> q;
    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int i, v;
            cin >> i >> v;
            tree.set(i - 1, v);
        }
        else if (c == 2) {
            int l, r, m;
            cin >> l >> r;
            m = r - l + 1;
            long long res1 = 0;
            if (m % 4 == 0) {
                res1 = m;
            } else if (m % 4 == 1) {
                res1 = 1;
            } else if (m % 4 == 2) {
                res1 = m + 1;
            } else if (m % 4 == 3) {
                res1 = 0;
            }
            ll sm = (m * (m + 1)) / 2;
//            cout << tree.get_sum(l - 1, r) << " ";
            vector<ll> rs = tree.get_sum(l - 1, r);
            if (res1 == rs[0] && sm == rs[1] && rs[2] == 1 && rs[3] == m && rs[4] == mul[m] && rs[5] == o_r[m]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
//            cout << tree.get_sum(l, r) << "\n";
        }
    }
    return 0;
}