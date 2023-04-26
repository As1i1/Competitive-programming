#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


struct  DSU{
    vector<int> size, p, sum;

    void init(int n, vector<int> a) {
        p.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            sum[i] = a[i];
        }
    }

    int get(int a) {
        if (p[a] != a) {
            p[a] = get(p[a]);
        }
        return p[a];
    }

    bool can_merge(int p1, int p2) {
        return sum[get(p1)] + sum[get(p2)] >= 0;
    }

    void union_set(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) {
            return;
        }
        if (size[a] > size[b]) {
            swap(a, b);
        }
        p[a]= b;
        sum[b] += sum[a];
        size[b] += size[a];
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    DSU smn;
    smn.init(n, a);


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
